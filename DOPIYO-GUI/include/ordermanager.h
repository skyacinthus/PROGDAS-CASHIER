#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <QObject>
#include<QVector>

struct OrderItem {
    QString name;
    int price;
    int qty;

    double total() const {return price * qty;}
};

class OrderManager : public QObject
{
    Q_OBJECT

public:
    static OrderManager &instance();  // Singleton instance

    void clear();
    void addItem(const OrderItem &item);
    const QVector<OrderItem>& getItems() const;

private:
OrderManager() {}  // private constructor
QVector<OrderItem> items;
};

#endif // ORDERMANAGER_H
