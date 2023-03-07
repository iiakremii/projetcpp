#ifndef DONATAIRES_H
#define DONATAIRES_H
#include <QString>
#include <QSqlQueryModel>


class Donataire
{
public:
    Donataire();
    Donataire(int,QString,int,int,QString, QString ,QString, int, QString ) ;
      int getId() ;
     void setId(int);

     QString getNom();
     void setNom(QString);

     QString gettype_de_don() ;
     void settype_de_don(QString);

     QString getAdresse();
     void setAdresse(QString);

     int getNum() ;
     void setNum (int);

     QString getMail() ;
     void setMail(QString);

     QString getTypeD() ;
     void setTypeD(QString);

     int getnbDons();
     void setNbDons(int);

     int getquantite_de_don();
     void setquantite_de_don(int);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer (int) ;
     bool modifier(int  ,QString  ,int ,int ,QString, QString ,QString , int   , QString ) ;
     private :
     int id_donataire ;
     QString nom ;
     QString type_de_don ;
     QString adresse ;
     int num_tel ;
     QString besoin ;
     QString type_donataire ;
     int date_de_don ;
     int quantite_de_don ;

};
#endif // DONATAIRES_H
