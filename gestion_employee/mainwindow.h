#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Employee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_le_add_clicked();

    void on_bouton_supp_clicked();

    void on_le_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Employee E1;

};




#endif // MAINWINDOW_H
