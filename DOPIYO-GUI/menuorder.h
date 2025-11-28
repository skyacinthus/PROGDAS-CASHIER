#ifndef MENUORDER_H
#define MENUORDER_H

#include <QWidget>
#include <QFile>
#include <QSpinBox>
#include <QTextStream>
#include <QLabel>

namespace Ui
{
    class MenuOrder;
}

class Cart;
class CustomerName;
class OrderManager;
class MenuOrder : public QWidget
{
    Q_OBJECT

public:
    explicit MenuOrder(QWidget *parent = nullptr);
    ~MenuOrder();
    void setCart(Cart *ptr);
    void updateCustomerName();

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::MenuOrder *ui;
    Cart *cart;
    QVector<QLabel*> nameLabels;
    QVector<QLabel*> priceLabels;
    QVector<QSpinBox*> qtySpinBoxes;
};

#endif // MENUORDER_H
