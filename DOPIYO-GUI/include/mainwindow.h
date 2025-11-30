#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class Nota;
class MenuOrder;
class CustomerName;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setMenuOrder(MenuOrder *ptr);
    void setNota(Nota *ptr);

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::MainWindow *ui;
    MenuOrder *menuOrder;
    Nota *nota;
};
#endif // MAINWINDOW_H
