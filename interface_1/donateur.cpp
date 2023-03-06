#include "donateur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
Donateur::Donateur()
{
     id_donateur = 0;
     nom = " " ;
     prenom = " " ;
     addresse = " " ;
     num_tel= 0  ;
     email = " " ;
     type_donateur = " " ;
     nb_don = 0  ;
     quantite = 0  ;

}
Donateur::Donateur(int id_donateur , QString nom , QString prenom , QString addresse , int num_tel , QString email , QString type_donateur , int nb_don  , int quantite  )
{
    this->id_donateur = id_donateur ;
    this->nom = nom ;
    this->prenom = prenom ;
    this->addresse = addresse ;
    this->num_tel = num_tel ;
    this->email = email ;
    this->type_donateur = type_donateur ;
    this->nb_don = nb_don ;
    this->quantite = quantite ;

}
int Donateur::getId()
{return id_donateur; }
void Donateur::setId(int id_donateur )
{ this->id_donateur = id_donateur ;}
QString Donateur::getNom()
{return nom ; }
void Donateur::setNom(QString nom)
{this->nom = nom ;}

QString  Donateur::getPrenom()
{return prenom ; }
void  Donateur::setPrenom(QString prenom)
{this->prenom = prenom ;}
QString  Donateur::getAdresse()
{return addresse ; }
void  Donateur::setAdresse(QString addresse )
{this->addresse = addresse ; }

int Donateur::getNum()
{return num_tel; }
void Donateur::setNum (int num_tel)
{ this->num_tel = num_tel ;}

QString  Donateur::getMail()
{return email ; }
void  Donateur::setMail(QString email)
{ this->email = email ;}
QString  Donateur::getTypeD()
{return type_donateur ;}
void  Donateur::setTypeD(QString type_donateur)
{ this->type_donateur = type_donateur ;}
int  Donateur::getnbDons()
{return nb_don ; }
void  Donateur::setNbDons (int nb_don)
{ this->nb_don = nb_don ;}


int  Donateur::getQuantite()
{return quantite  ;}
void  Donateur::setQuantite(int quantite)
{this->quantite = quantite ; }

bool Donateur::ajouter()
{
     // Check if the ID already exists in the database
        QSqlQuery check_query;
        check_query.prepare("SELECT id_donateur FROM donateur WHERE id_donateur = ?");
        check_query.addBindValue(id_donateur);
        if (check_query.exec() && check_query.next()) {
            // ID already exists, display an error message and return false
            QMessageBox::critical(nullptr, "Error", "Donor ID already exists in the database.");
            return false;
        }

        // Check if the name, phone number are not empty
        if (nom.trimmed().isEmpty() && QString::number(num_tel).trimmed().isEmpty()) {
            QMessageBox::critical(nullptr, "Error", "Please fill in all required fields.");
            return false;
        }

       // Check if the phone number is a valid number
        bool ok;
        int num_tel_int = QString::number(num_tel).toInt(&ok);
        if (!ok) {
            QMessageBox::critical(nullptr, "Error", "Please enter a valid phone number.");
            return false;
        }

        // Check if the donation quantity is a valid number
        int quantite_int = QString::number(quantite).toInt(&ok);
        if (!ok || quantite_int <= 0) {
            QMessageBox::critical(nullptr, "Error", "Please enter a valid donation quantity.");
            return false;
        }
    QString id_string=QString::number(id_donateur);
    QString num_tel_string=QString::number(num_tel);
    QString nb_don_string=QString::number(nb_don);
    QString quantite_string=QString::number(quantite);
    QSqlQuery query;
    query.prepare("INSERT INTO DONATEUR (id_donateur , nom, prenom, addresse , num_tel ,  email , type_donateur ,nb_don ,quantite ) "
                  "VALUES ( :id_donateur, :nom, :prenom, :addresse , :num_tel ,  :email , :type_donateur , :nb_don  , :quantite )");
    query.bindValue(":id_donateur", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":addresse" , addresse);
    query.bindValue(":num_tel",  num_tel_string);
    query.bindValue(":email", email);
    query.bindValue(":type_donateur", type_donateur);
    query.bindValue(":nb_don", nb_don_string);
    query.bindValue(":quantite", quantite_string);


    return   query.exec();
}

QSqlQueryModel* Donateur::afficher()
{

    QSqlQueryModel* model = new QSqlQueryModel() ;

          model->setQuery("SELECT* FROM DONATEUR");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Addresse"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero tel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type Donateur"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de don"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("Quantite"));

  return model;
}
bool Donateur::supprimer(int id_donateur)
{
    QSqlQuery query;
    query.prepare("Delete from donateur where id_donateur=:id_donateur");
    query.bindValue(0, id_donateur);

     return   query.exec();
}
bool Donateur::modifier()
{
    // Check if the ID exists in the database
    QSqlQuery check_query;
    check_query.prepare("SELECT id_donateur FROM donateur WHERE id_donateur = ?");
    check_query.addBindValue(id_donateur);
    if (!check_query.exec() || !check_query.next()) {
        // ID does not exist, display an error message and return false
        QMessageBox::critical(nullptr, "Error", "Donor ID does not exist in the database.");
        return false;
    }

    // Check if the name, phone number are not empty
    if (nom.trimmed().isEmpty() && QString::number(num_tel).trimmed().isEmpty()) {
        QMessageBox::critical(nullptr, "Error", "Please fill in all required fields.");
        return false;
    }

    // Check if the phone number is a valid number
    bool ok;
    int num_tel_int = QString::number(num_tel).toInt(&ok);
    if (!ok) {
        QMessageBox::critical(nullptr, "Error", "Please enter a valid phone number.");
        return false;
    }

    // Check if the donation quantity is a valid number
    int quantite_int = QString::number(quantite).toInt(&ok);
    if (!ok || quantite_int <= 0) {
        QMessageBox::critical(nullptr, "Error", "Please enter a valid donation quantity.");
        return false;
    }

    QString id_string=QString::number(id_donateur);
    QString num_tel_string=QString::number(num_tel);
    QString nb_don_string=QString::number(nb_don);
    QString quantite_string=QString::number(quantite);

    QSqlQuery query;
    query.prepare("UPDATE DONATEUR SET nom = :nom, prenom = :prenom, addresse = :addresse, num_tel = :num_tel, email = :email, type_donateur = :type_donateur, nb_don = :nb_don, quantite = :quantite WHERE id_donateur = :id_donateur");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":addresse", addresse);
    query.bindValue(":num_tel", num_tel_string);
    query.bindValue(":email", email);
    query.bindValue(":type_donateur", type_donateur);
    query.bindValue(":nb_don", nb_don_string);
    query.bindValue(":quantite", quantite_string);
    query.bindValue(":id_donateur", id_string);

    return query.exec();
}

