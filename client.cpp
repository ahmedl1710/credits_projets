#include "client.h"
#include<QDate>




    Client::Client()
    {
     cin=0;
     nom="";
     prenom="";
     Date_insc.setDate(0,0,0);
    }
    Client::Client(int cin,QString nom,QString prenom)
    {
        this->cin=cin;
        this->nom=nom;
        this->prenom=prenom;
        this->Date_insc=QDate::currentDate();
    }
    Client::Client(int cin,QString nom,QString prenom,int i)
    {
        this->cin=cin;
        this->nom=nom;
        this->prenom=prenom;

    }
    QString Client::get_nom(){return nom;}
    QString Client::get_prenom(){return prenom;}
    int Client::get_cin(){return cin;}
    QDate Client::get_date(){return Date_insc;}

    bool Client::ajouter()
    {
        QSqlQuery query;
        //QString res= QString::number(cin);
        //QString dd=
        QDate dd=QDate::currentDate();
        query.prepare("INSERT INTO client (cin, nom, prenom,Date_insc)"
                      "Values (:cin, :nom, :prenom, :Date_insc)");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":Date_insc",dd);
        return query.exec();
    }
    QSqlQueryModel * Client::afficher()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("Select * from client");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_insc"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));


        return model;
    }
    bool Client::supprimer(int CIN)
    {
        QSqlQuery query;
        //QString res= QString::number(CIN);
        query.prepare("Delete from client where CIN = :CIN");
        query.bindValue(":CIN", CIN);
        return query.exec();
    }
    bool Client::modifier()
    {
        QSqlQuery query;
        int CIN=this->cin;
        QString nom= this->nom;
        QString prenom= this->prenom;
        query.prepare("UPDATE client SET nom =:nom , prenom=:prenom  WHERE cin =:CIN");
        query.bindValue(":CIN",CIN);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        return  query.exec();
    }
    QSqlQueryModel * Client::combo_box(){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select CIN from client");
        return model;
    }
    QSqlQueryModel * Client::recherche_CIN(int CIN){
        QSqlQueryModel * model = new QSqlQueryModel();
        QString res = QString::number(CIN);
        model->setQuery("Select * From client WHERE CIN = " + res );
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_insc"));

        return model;
    }

    QSqlQueryModel * Client::recherche_nom(QString nom){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * From client WHERE nom ='" +nom+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_insc"));

        return model;
    }

    QSqlQueryModel * Client::trier_CIN()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("Select * from client\
                             Order by CIN DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_insc"));


        return model;
    }
