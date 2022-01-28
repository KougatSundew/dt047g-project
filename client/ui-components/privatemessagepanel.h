//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// privatemessagepanel.h, 2022-01-08 - 2021-01-13
// Contains the header definitions
//

//
// Created by jolof on 2022-01-08.
//

#ifndef CLIENT_PRIVATEMESSAGEPANEL_H
#define CLIENT_PRIVATEMESSAGEPANEL_H

#include <QWidget>
#include <QListWidgetItem>
#include "../data/Message.h"
#include "../data/Friend.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PrivateMessagePanel; }
QT_END_NAMESPACE

class PrivateMessagePanel : public QWidget {
Q_OBJECT

public:
    explicit PrivateMessagePanel(QWidget *parent = nullptr);

    ~PrivateMessagePanel() override;

    void addFriend(class Friend user);
    void addMessage(class Message message);
signals:
    void friendListItemChanged(QListWidgetItem *item);
    void sendBtnClick(QString receiver, QString message);
private slots:
    void onSendMessageBtnClicked();
private:
    void clearMessageWindow();
    void clearMessageBox();

    Ui::PrivateMessagePanel *ui;
};


#endif //CLIENT_PRIVATEMESSAGEPANEL_H
