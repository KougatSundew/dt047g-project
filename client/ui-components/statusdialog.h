//
// Chatter, Programmeringsmetodik (DT047G)
// Joel Olofsson (jool1904)
// statusdialog.h, 2022-01-02 - 2021-01-10
// Contains the header definitions
//

//
// Created by jolof on 2022-01-02.
//

#ifndef CLIENT_STATUSDIALOG_H
#define CLIENT_STATUSDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class StatusDialog; }
QT_END_NAMESPACE

class StatusDialog : public QDialog {
Q_OBJECT

public:
    explicit StatusDialog(QWidget *parent = nullptr);

    ~StatusDialog() override;
signals:
    void dialogOptionPressed(bool retry);
private:
    Ui::StatusDialog *ui;
};


#endif //CLIENT_STATUSDIALOG_H
