#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "donateur.h"
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
    void on_pushButton_21_clicked();

    void on_button_add_clicked();

    void on_button_sup_clicked();

    void on_pushButton_23_clicked();

    void on_button_side_ajouter_3_clicked();

    void on_button_side_lire_4_clicked();

    void on_button_side_lire_3_clicked();

    void on_button_side_supp_2_clicked();

    void on_button_side_supp_clicked();

    void on_pushButton_25_clicked();

    void on_button_side_lire_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_81_clicked();

    void on_button_side_supp_3_clicked();

    void on_button_home_3_clicked();

    void on_button_add_2_clicked();



    void on_table_D_3_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Donateur D ;
};
#endif // MAINWINDOW_H
