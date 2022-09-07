#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>



class Client
{
public:
    Client();
    Client(int,QString,QString);
    Client(int,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_cin();
    QDate get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * combo_box();
    QSqlQueryModel * recherche_CIN(int CIN);
    QSqlQueryModel * recherche_nom(QString nom);
    QSqlQueryModel * trier_CIN();

private:
    int cin;
    QString nom;
    QString prenom;
    QDate Date_insc;


};

#endif // CLIENT_H
