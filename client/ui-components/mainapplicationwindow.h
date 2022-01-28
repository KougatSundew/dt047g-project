//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// mainapplicationwindow.h , 2022-01-07 - 2021-01-12
// Contains the header definitions
//

//
// Created by jolof on 2022-01-07.
//

#ifndef CLIENT_MAINAPPLICATIONWINDOW_H
#define CLIENT_MAINAPPLICATIONWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <memory>
#include <QListView>
#include "../data/FriendList.h"
#include "../data/Friend.h"
#include "../data/MessageList.h"
#include "../data/Message.h"
#include "privatemessagepanel.h"
#include "../data/User.h"
#include <iostream>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainApplicationWindow; }
QT_END_NAMESPACE

class MainApplicationWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainApplicationWindow(QWidget *parent = nullptr);
    void loadFriendList(std::shared_ptr<class FriendList> friends);

    void loadPrivateMessageWindow(class Message message);
    void privateWindowAddMessage(class Message message);
    void setUser(User data);

    ~MainApplicationWindow() override;
signals:
    void sendMessage(QString receiver, QString message);
private slots:
    void onFriendListItemChanged(QListWidgetItem *item);
private:
    void addMessage(QString receiver, QString message);
    Ui::MainApplicationWindow *ui;
    std::unique_ptr<PrivateMessagePanel> m_chatWindow;

    std::shared_ptr<class FriendList> friends;
    User userdata;
};


#endif //CLIENT_MAINAPPLICATIONWINDOW_H
