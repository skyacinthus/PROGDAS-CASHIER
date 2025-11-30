#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>

namespace Ui {
class Payment;
}

class Nota;
class Payment : public QWidget
{
    Q_OBJECT

public:
    explicit Payment(QWidget *parent = nullptr);
    ~Payment();
    void setNota(Nota *ptr);

private slots:
    void on_pushButton_Confirm_clicked();

private:
    Ui::Payment *ui;
    Nota *nota;
};

#endif // PAYMENT_H
