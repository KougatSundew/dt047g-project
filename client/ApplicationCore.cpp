//
// Created by jolof on 2021-12-29.
//

#include "ApplicationCore.h"
/**
 * Constructor that inits and define resources
 * @param parent - QObject parent for signal / slot
 */
ApplicationCore::ApplicationCore(QObject *parent)
    : QObject(parent),
    m_client(std::make_unique<Client>(this, QHostAddress("78.68.124.217"), 4040)),
    m_start(std::make_unique<StartingWindow>()),
    m_timer(std::make_unique<QTimer>(this)),
    m_mainWindow(std::make_unique<MainApplicationWindow>()),
    m_retryDialogWindow(std::make_unique<StatusDialog>()){

    m_start->show();
    connectSocketSignals();
    connectSignals();
    m_client->connectToServer();
    //Test connection to server for a specific amount of time
    m_timer->start(SOCKETCONNECTTIME);
}
/**
 * Function for handling when the socket connects
 */
void ApplicationCore::onSocketConnected() {
    connectionRetryAttempts = 0;
    m_timer->stop();
    m_start->switchToLogin();
}
/**
 * Function for handling onSocketDisconnected signal
 */
void ApplicationCore::onSocketDisconnected() {
    m_mainWindow->hide();
    m_retryDialogWindow->show();
}
/**
 * Function for handling onConnectionTimout
 */
void ApplicationCore::onConnectionTimeOut() {
    m_client->abort();
    if(connectionRetryAttempts != maxConnectionRetryAttempts) {
        socketRetryConnection();
    } else {
        m_start->setSocketConnStatus("connection to server failed");
    }
}
/**
 * Function for connecting different signals to the ApplicationCore slots
 */
void ApplicationCore::connectSignals() {
    connect(m_timer.get(), &QTimer::timeout, this, &ApplicationCore::onConnectionTimeOut);
    connect(m_start.get(), &StartingWindow::loginButtonPressed, this, &ApplicationCore::onLoginBtnPressed);
    connect(m_mainWindow.get(), &MainApplicationWindow::sendMessage, this, &ApplicationCore::onSendMessage);
    connect(m_retryDialogWindow.get(), &StatusDialog::dialogOptionPressed, this, &ApplicationCore::onDialogRetry);
}
/**
 * Function for connecting socket signals
 */
void ApplicationCore::connectSocketSignals() {
    connect(m_client.get(), &Client::connected, this, &ApplicationCore::onSocketConnected);
    connect(m_client.get(), &Client::disconnected, this, &ApplicationCore::onSocketDisconnected);
    connect(m_client.get(), &Client::messageReceived, this, &ApplicationCore::onMessageReceived);
    connect(m_client.get(), &Client::authReceived, this, &ApplicationCore::onAuthMessageReceived);
    connect(m_client.get(), &Client::friendListReceived, this, &ApplicationCore::onFriendListReceived);
}
/**
 * Function for handling if the login btn is pressed
 * @param username - type QString containing the username
 * @param password - type QString containing the password
 */
void ApplicationCore::onLoginBtnPressed(QString username, QString password) {
    //Sets user data
    userdata.setUsername(username);
    userdata.setPassword(password);
    m_mainWindow->setUser(userdata);
    userdata.setType(DataType::AuthRequest);
    if(m_client->isSocketConnected()) {
        m_start->resetLoginStatus();
        login();
    }
    else
        m_start->setLoginStatus("Error: disconnected from server");
}
/**
 * Function for retry connection to server
 */
void ApplicationCore::socketRetryConnection() {
    connectionRetryAttempts++;
    QString status = "Retrying connection... (attempt " + QString::number(connectionRetryAttempts) + "/5)";
    m_start->setSocketConnStatus(status);
    m_client->connectToServer();
}
/**
 * Function for sending login data
 */
void ApplicationCore::login() {
    m_client->write(userdata);
}
/**
 * Function for handling on message received
 * @param stream - reference type QDataStream containing the data
 */
void ApplicationCore::onMessageReceived(QDataStream &stream) {
    //Forward private messages only if the main window is shown
    if(m_mainWindow->isHidden()) return;

    class Message message;
    stream >> message;
    m_mainWindow->privateWindowAddMessage(message);
}
/**
 * Function for handling on auth message received
 * @param stream - reference type QDataStream containing the data
 */
void ApplicationCore::onAuthMessageReceived(QDataStream &stream) {
    AuthAnswer auth;
    stream >> auth;

    if(!auth.isSigned()) {
        m_start->setLoginStatus("Wrong login details");
        return;
    }
    m_start->close();
    m_mainWindow->show();
}
/**
 * Function for handling on friendlist received
 * @param stream - reference type QDataStream containing the data
 */
void ApplicationCore::onFriendListReceived(QDataStream &stream) {
    class FriendList tmpFriends;
    stream >> tmpFriends;
    friends = std::make_shared<class FriendList>(tmpFriends);
    m_mainWindow->loadFriendList(friends);
}
/**
 * Function for sending a message
 * @param receiver - type QString containing the username of the reciever
 * @param message - type QString containing the message
 */
void ApplicationCore::onSendMessage(QString receiver, QString message) {
    class Message msg(userdata.getUsername(), receiver, message);
    m_client->write(msg);
}
/**
 * Function for handling the StatusDialog signals
 * @param retry - boolean that can be true or false, if false exit the application or else restart the application
 */
void ApplicationCore::onDialogRetry(bool retry) {
    m_retryDialogWindow->close();
    if(retry) qApp->exit(ApplicationCore::EXIT_CODE_REBOOT);
    if(!retry) qApp->exit(ApplicationCore::EXIT_CODE_QUIT);
}


