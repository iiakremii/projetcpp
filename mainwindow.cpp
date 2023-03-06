
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab->setModel(E1.afficher());
    ui->tab_2->setModel(E1.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_le_add_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString fonction = ui->le_fonction->text();
    QString adresse = ui->le_adresse->text();
    QString email = ui->le_email->text();
    int num_tel = ui->le_num_tel->text().toInt();
    QString mdp = ui->le_mdp->text();
    QString droit_access = ui->le_droit_daccess->text();
    QString statut = ui->le_satut->text();

    Employee E(id, nom, fonction, email, statut, num_tel, adresse, mdp, droit_access);
    bool test = E.ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_bouton_supp_clicked()
{
    Employee E2 ;
        E2.setid(ui->le_supp->text().toInt());
        bool test=E2.supprimer(E2.getid());
        if(test)
        { QMessageBox::information(nullptr, QObject::tr("ok"),
                                   QObject::tr("supprission effectue\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tab->setModel(E2.afficher()) ;
        }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("not ok "),
                                   QObject::tr("supprission non effectue.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel );}
}

void MainWindow::on_le_modifier_clicked()
{  int id = ui->le_id_2->text().toInt();
    QString nom = ui->le_nom_2->text();
    QString fonction = ui->le_fonction_2->text();
    QString adresse = ui->le_adresse_2->text();
    QString email = ui->le_email_2->text();
    int num_tel = ui->le_num_tel_2->text().toInt();
    QString mdp = ui->le_mdp_2->text();
    QString droit_access = ui->le_droit_daccess_2->text();
    QString statut = ui->le_satut_2->text();

    Employee E(id, nom, fonction, email, statut, num_tel, adresse, mdp, droit_access);
    bool test = E.modifier();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modification effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("modification non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

}
