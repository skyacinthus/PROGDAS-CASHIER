#include "menuorder.h"
#include "ui_menuorder.h"
#include "cart.h"
#include "customername.h"
#include "ordermanager.h"

MenuOrder::MenuOrder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuOrder)
{
    ui->setupUi(this);

    QFile file("menu.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();

            QStringList parts = line.split(",");
            if (parts.size() < 2) continue;

            QString menuName = parts[0];
            QString price = parts[1];

            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            QWidget *rowWidget = new QWidget;

            QLabel *labelName = new QLabel(menuName);
            labelName->setFixedWidth(150);

            QLabel *labelPrice = new QLabel("Rp " + price);
            labelPrice->setFixedWidth(80);

            QSpinBox *spin = new QSpinBox;
            spin->setRange(0, 10);
            spin->setFixedWidth(60);

            nameLabels.append(labelName);
            priceLabels.append(labelPrice);
            qtySpinBoxes.append(spin);

            QHBoxLayout *layout = new QHBoxLayout(rowWidget);
            layout->addWidget(labelName);
            layout->addWidget(labelPrice);
            layout->addStretch();
            layout->addWidget(spin);

            rowWidget->setLayout(layout);

            item->setSizeHint(rowWidget->sizeHint());

            ui->listWidget->setItemWidget(item, rowWidget);
        }
    }

}

MenuOrder::~MenuOrder()
{
    delete ui;
}

void MenuOrder::setCart(Cart *ptr)
{
    cart = ptr;
}

void MenuOrder::on_pushButton_OK_clicked()
{
    OrderManager::instance().clear();

    for (int i = 0; i < nameLabels.size(); i++) {
        int qty = qtySpinBoxes[i]->value();
        if (qty > 0) {
            OrderItem item;

            item.name = nameLabels[i]->text();

            QString p = priceLabels[i]->text();
            p.remove("Rp ");
            item.price = p.toInt();

            item.qty = qty;

            OrderManager::instance().addItem(item);
        }
    }

    cart->updateUI();
    cart->show();
    this->hide();
}

void MenuOrder::updateCustomerName()
{
    std::string name = CustomerName::instance().getName();
    ui->label_WelcomeTag->setText("Hi " + QString::fromStdString(name) + "! What would you like to order today?");
}
