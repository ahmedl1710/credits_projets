#include "card.h"

card::card()
{
    numero=0;
    bonus_ach=0;
    cin_client=0;
}
card::card(int id,int bonus,int ciin)
{
    this->numero=id;
    this->bonus_ach=bonus;
    this->cin_client=ciin;
}
card::card(int id,int cin)
{
   this->numero=id;
    this->cin_client=cin;
    this->bonus_ach=25;
}
int card::get_numero(){return numero;}
int card::get_bonus(){return bonus_ach;}
int card::get_cinclient(){return cin_client;}

bool card::add_card()
{
    QSqlQuery query;
    query.prepare("INSERT INTO card (numero, bonus_ach, cin_client)"
                  "Values (:num, :bonus, :ciin)");
    query.bindValue(":num",numero);
    query.bindValue(":bonus",bonus_ach);
    query.bindValue(":ciin",cin_client);
    return query.exec();
}

QSqlQueryModel * card::readCard()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from card");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("bonus"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin_client"));


    return model;
}
bool card::delete_card(int NUM)
{
    QSqlQuery query;
    query.prepare("Delete from card where numero = :NUM");
    query.bindValue(":NUM", NUM);
    return query.exec();
}
QSqlQueryModel * card::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select numero from card");
    return model;
}
QSqlQueryModel * card::search_NUM(int NUM){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(NUM);
    model->setQuery("Select * From card WHERE numero = " + res );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("bonus"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin_client"));;

    return model;
}
QSqlQueryModel * card::search_CIN(int CIN){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(CIN);
    model->setQuery("Select * From card WHERE cin_client = " + res );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("bonus"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin_client"));;

    return model;
}


