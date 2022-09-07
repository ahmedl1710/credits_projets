#ifndef ACHAT_H
#define ACHAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QApplication>
class Achat
{
public:
    Achat();
    Achat(int,int,QString,QDate);
    int get_id();
    QString get_nom_produit();
    int get_prix();
    int get_quantite();
    QDate get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher1();
    QSqlQueryModel * chercher(const QString &);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_quantite();
    QSqlQueryModel * afficherid();
    QSqlQueryModel * combo_ID();



private:
    int id,prix,quantite;
    QString nom_produit;
    QDate date_achat ;
    };
#endif //ACHAT_H
