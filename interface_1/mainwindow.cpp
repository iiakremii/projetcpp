#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donataires.h"
#include"QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_don->setModel(m.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajout_clicked()
{
     int id=ui->le_id->text().toInt();
     int num=ui->le_tel->text().toInt();
     int date=ui->le_date->text().toInt();
     int quant=ui->le_quant->text().toInt();
     QString nom=ui->le_nom->text();
     QString besoin=ui->le_besoin->text();
     QString type_de_don=ui->le_type->text();
     QString type_donat=ui->le_type_don->text();
     QString adress=ui->le_adress->text();





     Donataire m(id,type_de_don,num,quant,nom,besoin,adress,date,type_donat);

    bool test=m.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("ajout successful.\n"
                                            "click cancel to exit."),QMessageBox::Cancel);
     ui->tab_don->setModel(m.afficher());
     stat();
    }
    else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                  QObject::tr("ajout non effectue.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_supprimer_clicked()
{


    Donataire m1; m1.setId(ui->le_id->text().toInt());
        bool test=m1.supprimer(m1.getId());
        QMessageBox msgbox;
        if(test) {msgbox.setText("suppression avec succes");
       ui->tab_don->setModel(m1.afficher());
        }
        else msgbox.setText("echec de suppression");
        msgbox.exec();

}

void MainWindow::on_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    int num=ui->le_tel->text().toInt();
    int date=ui->le_date->text().toInt();
    int quant=ui->le_quant->text().toInt();
    QString nom=ui->le_nom->text();
    QString besoin=ui->le_besoin->text();
    QString type_de_don=ui->le_type->text();
    QString type_donat=ui->le_type_don->text();
    QString adress=ui->le_adress->text();





    Donataire m(id,type_de_don,num,quant,nom,besoin,adress,date,type_donat);

     bool test=m.modifier(id,type_de_don,num,quant,nom,besoin,adress,date,type_donat);
     if(test)
     {ui->tab_don->setModel(m.afficher());
         stat();
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modif successful.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);

     }
     else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                   QObject::tr("modif non effectue.\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}
