#include "vente.h"
#include <QDate>
#include <QDebug>
#include <QApplication>
#include <QComboBox>

VENTE::VENTE()
{
    cin_cl=0;
    prix=0;
    this->date_vente=QDate::currentDate();
}

VENTE::VENTE(int cin,int prix,QDate dat)
    {
        this->cin_cl=cin;
        this->prix=prix;
    this->date_vente=dat;

    }
VENTE::VENTE(int cin,int prix)
    {
        this->cin_cl=cin;
        this->prix=prix;
    }
    int VENTE::get_cincl(){return  cin_cl;}
    int VENTE::get_prix(){return prix;}
    QDate VENTE::get_datevente(){return date_vente;}


QSqlQueryModel * VENTE::afficher2( )
   {QSqlQueryModel * model= new QSqlQueryModel();


   model->setQuery("select CIN_CLT from VENTE ");

   return model;
   }
QSqlQueryModel * VENTE::affichermatricule( )
   {QSqlQueryModel * model= new QSqlQueryModel();


   model->setQuery("select CIN from CLIENT ");

   return model;
   }
bool VENTE::ajouterV()
    {
    QSqlQuery query;


    query.prepare("INSERT INTO VENTE (CIN_CLT, PRIX, DATE_VENTE) "
                        "VALUES (:cin, :prix, :date_vente)");
    query.bindValue(":cin", cin_cl);
    query.bindValue(":prix", prix);
    query.bindValue(":date_vente", date_vente);

    return    query.exec();
    }

    QSqlQueryModel * VENTE::afficherV()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select CIN_CLT, PRIX, DATE_VENTE from VENTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_CLT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_VENTE"));
        return model;
    }

bool VENTE::supprimerV(int id)
    {
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from VENTE where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
    }

bool VENTE::modifierV(int id)
    {
        QSqlQuery query;
        QString res=QString::number(id);


        query.prepare("update VENTE SET CIN_CLT=:cin,PRIX=:prix where ID=:id");
        query.bindValue(":id",res);
        query.bindValue(":prix",prix);
        query.bindValue(":cin",cin_cl);
        return query.exec();
    }
QSqlQueryModel * VENTE::chercherV(const QString &cin)
{

   QSqlQueryModel * model=new QSqlQueryModel;
   model->setQuery("select * from VENTE where (CIN_CLT LIKE '"+cin+"%') ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE_CLT"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_VENTE"));
       return model;
}
QSqlQueryModel * VENTE::trierV_cin()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("select * from VENTE order by CIN_CLT ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_CLT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_VENTE"));
        return model;
}
QSqlQueryModel * VENTE::trierV_prix()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("select * from VENTE order by PRIX DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_CLT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_VENTE"));
        return model;
}
QSqlQueryModel * VENTE::combo_ID(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ID from vente");
    return model;
}
bool VENTE::Addbonus(int nvbonus,int cincl)
{
    QSqlQuery query;
    query.prepare("update CARD SET BONUS_ACH =:bon where CIN_CLIENT =:CIN");
    query.bindValue(":bon",nvbonus);
    query.bindValue(":CIN",cincl);
    return query.exec();
}
QSqlQueryModel * VENTE::recette(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select sum(PRIX) from vente");
    return model;
}


