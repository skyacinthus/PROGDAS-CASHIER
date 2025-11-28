#include "ordermanager.h"

OrderManager &OrderManager::instance()
{
    static OrderManager instance;
    return instance;
}

void OrderManager::clear()
{
    items.clear();
}

void OrderManager::addItem(const OrderItem &item)
{
    items.append(item);
}

const QVector<OrderItem>& OrderManager::getItems() const
{
    return items;
}
