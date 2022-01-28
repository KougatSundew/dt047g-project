//
// Created by jolof on 2022-01-08.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PrivateMessagePanel.h" resolved

#include "privatemessagepanel.h"
#include "ui_PrivateMessagePanel.h"

/**
 * Constructor
 * @param parent - QObject parent for signals / slot
 */
PrivateMessagePanel::PrivateMessagePanel(QWidget *parent) :
        QWidget(parent), ui(new Ui::PrivateMessagePanel) {
    ui->setupUi(this);

    connect(ui->friendViewList, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {clearMessageWindow(); emit friendListItemChanged(item);});
    connect(ui->btnSendMessage, &QPushButton::clicked, this, &PrivateMessagePanel::onSendMessageBtnClicked);
}

PrivateMessagePanel::~PrivateMessagePanel() {
    delete ui;
}
/**
 * Function for adding a friend to the friendViewList
 * @param user - Friend with user details
 */
void PrivateMessagePanel::addFriend(class Friend user) {
    ui->friendViewList->addItem(user.getUsername());
}
/**
 * Function for adding a message to the message window
 * @param message - class Message containing message details
 */
void PrivateMessagePanel::addMessage(class Message message) {
    //TODO: fix so that a message only gets added if the selected friend is equal to the sender of the message
    //if(ui->friendViewList->currentItem()->data(Qt::DisplayRole) == message.getReceiver())
        ui->messageWidget->addItem(message.getSender() + ": " + message.getMessage());
}
/**
 * Function for clearing the message window
 */
void PrivateMessagePanel::clearMessageWindow() {
    ui->messageWidget->clear();
}
/**
 * Function for handling when the send message btn is clicked, function emits sendBtnClick
 */
void PrivateMessagePanel::onSendMessageBtnClicked() {
    QString message = ui->messageLine->toPlainText();
    QString receiver = ui->friendViewList->currentItem()->text();
    clearMessageBox();
    emit sendBtnClick(receiver, message);
}
/**
 * Function for clearing the message box
 */
void PrivateMessagePanel::clearMessageBox() {
    ui->messageLine->clear();
}

