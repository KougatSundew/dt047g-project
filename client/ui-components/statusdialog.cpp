//
// Created by jolof on 2022-01-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StatusDialog.h" resolved

#include "statusdialog.h"
#include "ui_StatusDialog.h"

/**
 * Constructor
 * @param parent - QObject paren for signals / slot
 */
StatusDialog::StatusDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::StatusDialog) {
    ui->setupUi(this);
    //Connection the pushbutton clicked signal to emit dialogOptionPressed
    connect(ui->btnYes, &QPushButton::clicked, this, [this]() { emit dialogOptionPressed(true);});
    connect(ui->btnNo, &QPushButton::clicked, this, [this]() {emit dialogOptionPressed(false);});
}

StatusDialog::~StatusDialog() {
    delete ui;
}

