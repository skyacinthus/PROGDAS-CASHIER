#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuorder.h"
#include "nota.h"
#include "customername.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMenuOrder(MenuOrder *ptr)
{
    menuOrder = ptr;
}

void MainWindow::setNota(Nota *ptr) {
    nota = ptr;
}

void MainWindow::on_pushButton_OK_clicked()
{
    QString qName = ui->lineEdit_EnterName->text();

    if(qName.isEmpty()) {
        ui->lineEdit_EnterName->setStyleSheet("border: 0.5px solid red; color: white;");
    return;
    }

    ui->lineEdit_EnterName->setStyleSheet("");

    CustomerName::instance().setName(qName.toStdString());

    if(menuOrder) {
        menuOrder->updateCustomerName();
        menuOrder->show();
    }
    if(nota) {
        nota->updateCustomerName();
    }
    this->hide();

}
