#include "nota.h"
#include "ui_nota.h"
#include "mainwindow.h"
#include "customername.h"
#include "ordermanager.h"

Nota::Nota(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Nota)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Nota::updateTime);

    timer->start(1000);

    updateTime();

    connect(ui->pushButton_Print, &QPushButton::clicked, this, &Nota::saveAsPDF);

}

Nota::~Nota()
{
    delete ui;
}

void Nota::updateTime()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("HH:mm");

    ui->label_Time->setText(timeText);
}

void Nota::updateCustomerName()
{
    std::string name = CustomerName::instance().getName();
    ui->label_CustName->setText(QString::fromStdString(name));
}

void Nota::updateNota() {
    ui->label_Nota->setText("");

    const auto &orders = OrderManager::instance().getItems();
    int subtotal = 0;

    QString text;

    text += "------------------------------------\n";

    for (const auto &item : orders) {
        QString line = QString("%1x%2 Rp %3\n")
            .arg(item.name.leftJustified(24))
            .arg(item.qty,2)
            .arg(item.total(),5);
        text += line;
        subtotal += item.total();
    }

    double taxRate = 0.10;
    int tax = subtotal * taxRate;

    int total = subtotal + tax;

    text += "------------------------------------\n";
    text += "Subtotal : Rp " + QString::number(subtotal) + "\n";
    text += "Tax (10%): Rp " + QString::number(tax) + "\n";
    text += "------------------------------------\n";
    text += "TOTAL    : Rp " + QString::number(total) + "\n";

    ui->label_Nota->setText(text);
}

void Nota::saveAsPDF() {
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Save Nota as PDF",
        "nota",
        "PDF Files (*.pdf)"
        );

    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter(&printer);
    if (!painter.isActive()) return;

    QWidget *widget = ui->widget_Print;

    QRectF page = printer.pageRect(QPrinter::DevicePixel);

    double padding = 40;
    double usableW = page.width()  - padding * 2;
    double usableH = page.height() - padding * 2;

    double xscale = usableW / widget->width();
    double yscale = usableH / widget->height();
    double scale = qMin(xscale, yscale);

    double scaledW = widget->width()  * scale;
    double scaledH = widget->height() * scale;

    double offsetX = (page.width()  - scaledW) / 2.0;
    double offsetY = (page.height() - scaledH) / 2.0;

    painter.translate(offsetX, offsetY);

    painter.scale(scale, scale);
    widget->render(&painter);

    painter.end();

    QMessageBox::information(this, "Success", "Nota saved as PDF!");
}


