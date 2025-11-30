#include "payment.h"
#include "ui_payment.h"
#include "nota.h"

Payment::Payment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Payment)
{
    ui->setupUi(this);
}

Payment::~Payment()
{
    delete ui;
}

void Payment::setNota(Nota *ptr)
{
    nota = ptr;
}

void Payment::on_pushButton_Confirm_clicked()
{
    nota->updateNota();
    nota->show();
    this->hide();
}
