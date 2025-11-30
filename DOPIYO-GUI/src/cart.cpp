#include "cart.h"
#include "ui_cart.h"
#include "menuorder.h"
#include "payment.h"
#include "ordermanager.h"

Cart::Cart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cart)
{
    ui->setupUi(this);
}

Cart::~Cart()
{
    delete ui;
}

void Cart::setMenuOrder(MenuOrder *ptr)
{
    menuOrder = ptr;
}

void Cart::on_pushButton_Confirm_clicked()
{

    payment->show();
    this->hide();
}

void Cart::setPayment(Payment *ptr)
{
    payment = ptr;
}

void Cart::on_pushButton_Back_clicked()
{
    menuOrder->show();
    this->hide();
}

void Cart::updateUI()
{
    ui->listWidget->clear();

    if (OrderManager::instance().getItems().isEmpty()) {
        ui->label_Empty->setText("Oh no! Your cart is empty\n Please select at least one item of our menu");
        ui->label_Empty->show();
        ui->listWidget->hide();
        ui->pushButton_Confirm->hide();
        return;
    } else {
        ui->listWidget->show();
        ui->label_Empty->hide();
        ui->pushButton_Confirm->show();
    }

    const auto &orders = OrderManager::instance().getItems();

    int subtotal = 0;
    for (const auto &item : orders) {
        ui->listWidget->addItem(
            QString("%1 x %2 = Rp %3")
                .arg(item.name)
                .arg(item.qty)
                .arg(item.total())
            );
        subtotal += item.total();
    }
    ui->label_Subtotal->setText("Subtotal =     Rp " + QString ::number(subtotal));
}

void Cart::setCustomerName(const QString &name) {
    customerName = name;
}

