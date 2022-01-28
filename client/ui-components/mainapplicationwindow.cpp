//
// Created by jolof on 2022-01-07.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainApplicationWindow.h" resolved

#include "mainapplicationwindow.h"
#include "ui_MainApplicationWindow.h"
/**
 * Constructor
 * @param parent - QObject parent for signals / slots
 */
MainApplicationWindow::MainApplicationWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainApplicationWindow), m_chatWindow(std::make_unique<PrivateMessagePanel>(this)) {
    ui->setupUi(this);
    setWindowTitle("Chatter 3000x");

    connect(m_chatWindow.get(), &PrivateMessagePanel::friendListItemChanged, this, &MainApplicationWindow::onFriendListItemChanged);
    connect(m_chatWindow.get(), &PrivateMessagePanel::sendBtnClick, this, [this](QString receiver, QString message) { addMessage(receiver, message);emit sendMessage(receiver, message);});

    ui->VerticalLayout->addWidget(m_chatWindow.get());
}
/**
 * Destructor for ui
 */
MainApplicationWindow::~MainApplicationWindow() {
    delete ui;
}
/**
 * Function for loading friends from the friendlist to the friendlistview
 * @param friends
 */
void MainApplicationWindow::loadFriendList(std::shared_ptr<class FriendList> friends) {
    this->friends = friends;

    for(auto usersFriend : *this->friends) {
        m_chatWindow->addFriend(usersFriend);
    }
}
/**
 * Function for handling friendlist item changed in the friendlistview
 * @param item - QListWidgetItem containing the friend
 */
void MainApplicationWindow::onFriendListItemChanged(QListWidgetItem *item) {
    QString username = item->text();
    const Friend* user = friends->getFriend(username);
    QVector<class Message> messages = user->getMessages();
    for(const auto& message : messages) {
        loadPrivateMessageWindow(message);
    }
}
/**
 * Function for loading a message to the chat window
 * @param message - class Message containing message details
 */
void MainApplicationWindow::loadPrivateMessageWindow(class Message message) {
    m_chatWindow->addMessage(message);
}
/**
 * Function for adding message to the chat window and saving the message locally
 * @param receiver
 * @param data
 */
void MainApplicationWindow::addMessage(QString receiver, QString data) {
    class Message message(userdata.getUsername(), receiver, data);
    m_chatWindow->addMessage(message);
    friends->addMessage(receiver, message);
}
/**
 * Function for adding a message to the privatewindow
 * @param message
 */
void MainApplicationWindow::privateWindowAddMessage(class Message message) {
    m_chatWindow->addMessage(message);
    friends->addMessage(message.getSender(), message);
}
/**
 * Function for setting the user data
 * @param data - class User
 */
void MainApplicationWindow::setUser(User data) {
    userdata = data;
}





