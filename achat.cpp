#include "achat.h"
#include <QDate>
#include <QDebug>
#include <QApplication>
#include <QComboBox>
Achat::Achat()
{
   nom_produit="";
   prix=0;
   quantite=0;
   date_achat=date_achat.currentDate();
}

Achat::Achat(int prix,int quantite,QString nomprod,QDate date_achat)
{
   this->prix=prix;
   this->nom_produit=nomprod;
   this->quantite=quantite;
   this->date_achat=date_achat;
}

int Achat::get_id(){return  id;}
int Achat::get_prix(){return  prix;}
QString Achat::get_nom_produit(){return nom_produit;}
int Achat::get_quantite(){return quantite;}
QDate Achat::get_date(){return date_achat;}

QSqlQueryModel * Achat::afficher1( )
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID_FOURNISSEUR from ACHAT ");

   return model;
}
QSqlQueryModel * Achat::afficherid( )
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select idF from FOURNISSEUR ");

   return model;
}

bool Achat::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO ACHAT (PRIX, NOMPROD, QUANTITE, DATE_ACHAT) "
                   "VALUES (:prix, :nomprod, :quantite, :date_achat)");
query.bindValue(":prix", prix);
query.bindValue(":nomprod",nom_produit);
query.bindValue(":quantite", quantite);
query.bindValue(":date_achat", date_achat);

return    query.exec();
}

QSqlQueryModel * Achat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACHAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMPROD"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
   return model;
}

bool Achat::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from ACHAT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Achat::modifier(int id)
{
   QSqlQuery query;
   QString res=QString::number(id);

   query.prepare("update ACHAT SET PRIX=:prix,QUANTITE=:quantite,NOMPROD=:nomprod,DATE_ACHAT=:date_achat where ID=:id");
   query.bindValue(":id",res);
   query.bindValue(":prix",prix);
   query.bindValue(":quantite",quantite);
   query.bindValue(":nomprod",nom_produit);
   query.bindValue(":date_achat",date_achat);
   return query.exec();
}
QSqlQueryModel * Achat::chercher(const QString &id)
{

  QSqlQueryModel * model=new QSqlQueryModel;
  model->setQuery("select * from ACHAT where (ID LIKE '"+id+"%') ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMPROD"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
      return model;
}
QSqlQueryModel * Achat::trier_id()
{
   QSqlQueryModel * model=new QSqlQueryModel;
   model->setQuery("select * from ACHAT order by DATE_ACHAT ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMPROD"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
       return model;
}
QSqlQueryModel * Achat::trier_quantite()
{
   QSqlQueryModel * model=new QSqlQueryModel;
   model->setQuery("select * from ACHAT order by QUANTITE DESC ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMPROD"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ACHAT"));
       return model;
}
QSqlQueryModel * Achat::combo_ID(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ID from achat");
    return model;
}
