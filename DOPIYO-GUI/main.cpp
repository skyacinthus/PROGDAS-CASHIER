#include <QApplication>
#include "MainWindow.h"
#include "MenuOrder.h"
#include "Cart.h"
#include "Payment.h"
#include "Nota.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    MenuOrder *menuOrder = new MenuOrder();
    Cart *cart = new Cart();
    Payment *payment = new Payment();
    Nota *nota = new Nota();

    mainWindow->setMenuOrder(menuOrder);
    mainWindow->setNota(nota);

    menuOrder->setCart(cart);

    cart->setMenuOrder(menuOrder);
    cart->setPayment(payment);

    payment->setNota(nota);

    mainWindow->show();

    return a.exec();
}

