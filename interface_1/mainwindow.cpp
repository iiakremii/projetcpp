#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donateur.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this) ;
    ui->table_D->setModel(D.afficher());
     ui->table_D_2->setModel(D.afficher());
      ui->table_D_3->setModel(D.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_21_clicked()
{
ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_button_add_clicked()
{
    int id_donateur = ui->le_id->text().toInt() ;
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString addresse = ui->le_addresse->text();
    int num_tel = ui->le_numtel->text().toInt() ;
    QString email = ui->le_mail->text();
    QString type_donateur = ui->le_type_d->text();
    int nb_don = ui->le_nb_don->text().toInt() ;
    int quantite = ui->le_quantite->text().toInt() ;

 Donateur d(id_donateur , nom , prenom , addresse , num_tel , email , type_donateur , nb_don, quantite );
 bool test = d.ajouter() ;
 if(test)
 { QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("ajouter effectue\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
               { QMessageBox::critical(nullptr, QObject::tr("not ok "),
                            QObject::tr("ajout non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel );}
}





void MainWindow::on_button_sup_clicked()
{
    Donateur D1 ;
    D1.setId(ui->le_id_sup_2->text().toInt());
    bool test=D1.supprimer(D1.getId());
    if(test)
    { QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("supprission effectue\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                ui->table_D->setModel(D1.afficher()) ;
    }
               else
                  { QMessageBox::critical(nullptr, QObject::tr("not ok "),
                               QObject::tr("supprission non effectue.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel );}
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_button_side_ajouter_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_button_side_lire_4_clicked()
{
      ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_button_side_lire_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_button_side_supp_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_button_side_supp_clicked()
{
     ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_button_side_lire_clicked()
{
     ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_pushButton_76_clicked()
{
       ui->stackedWidget->setCurrentIndex(4) ;
}

void MainWindow::on_pushButton_81_clicked()
{
     ui->stackedWidget->setCurrentIndex(4) ;
}

void MainWindow::on_button_side_supp_3_clicked()
{
       ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_button_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_button_add_2_clicked()
{
    int id_donateur = ui->le_id_modif->text().toInt() ;
    QString nom = ui->le_nom_modif->text();
    QString prenom = ui->le_prenom_modif->text();
    QString addresse = ui->le_addresse_modif->text();
    int num_tel = ui->le_numtel_modif->text().toInt() ;
    QString email = ui->le_mail_modif->text();
    QString type_donateur = ui->le_type_d_modif->text();
    int nb_don = ui->le_nb_don_modif->text().toInt() ;
    int quantite = ui->le_quantite_modif->text().toInt() ;
    Donateur d(id_donateur , nom , prenom , addresse , num_tel , email , type_donateur , nb_don, quantite );
    bool test = d.modifier() ;
    if(test)
    { QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("Modification avec succes\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
      ui->table_D_3->setModel(d.afficher()) ;
           }
               else
                  { QMessageBox::critical(nullptr, QObject::tr("not ok "),
                               QObject::tr("Echec de modification\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel );}
   }


void MainWindow::on_table_D_3_activated(const QModelIndex &index)
    {
        // Get the selected row from the table
        int row = index.row();

        // Get the data for the selected row
        QString id_donateur = ui->table_D_3->model()->index(row, 0).data().toString();
        QString nom = ui->table_D_3->model()->index(row, 1).data().toString();
        QString prenom = ui->table_D_3->model()->index(row, 2).data().toString();
        QString addresse = ui->table_D_3->model()->index(row, 3).data().toString();
        QString num_tel = ui->table_D_3->model()->index(row, 4).data().toString();
        QString email = ui->table_D_3->model()->index(row, 5).data().toString();
        QString type_donateur = ui->table_D_3->model()->index(row, 6).data().toString();
        QString nb_don = ui->table_D_3->model()->index(row, 7).data().toString();

}
