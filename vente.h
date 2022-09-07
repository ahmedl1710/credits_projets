#ifndef VENTE_H
#define VENTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QApplication>
class VENTE
{
public:
    VENTE();
    VENTE(int,int,QDate);
    VENTE(int,int);
    int get_cincl();
    int get_prix();
    QDate get_datevente();
    bool ajouterV();
    QSqlQueryModel * afficherV();
    bool supprimerV(int);
    bool modifierV(int);
    QSqlQueryModel * afficher2();
    QSqlQueryModel * chercherV(const QString &);
    QSqlQueryModel * trierV_cin();
    QSqlQueryModel * trierV_prix();
    QSqlQueryModel * affichermatricule();
    QSqlQueryModel * combo_ID();
    bool Addbonus(int,int);
    QSqlQueryModel * recette();



private:
    int cin_cl,prix;
    QDate date_vente ;
};
#endif // VENTE_H
