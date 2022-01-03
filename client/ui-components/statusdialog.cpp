//
// Created by jolof on 2022-01-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StatusDialog.h" resolved

#include "statusdialog.h"
#include "ui_StatusDialog.h"


StatusDialog::StatusDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::StatusDialog) {
    ui->setupUi(this);
}

StatusDialog::~StatusDialog() {
    delete ui;
}

