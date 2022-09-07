#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"




#include <QApplication>
#include <QDate>
#include <QString>
#include <QDateEdit>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableclient->setModel(tmpclient.afficher());
    ui->comcin->setModel(tmpclient.combo_box());
    ui->combocin->setModel(tmpclient.combo_box());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//****************************************client*****************************************
void MainWindow::on_addc_clicked()
{

    QString nom= ui->Qnom->text();
    QString prenom= ui->Qprenom->text();
    int CIN = ui->Qcin->text().toInt();



  Client c(CIN,nom,prenom);
  if(CIN < 99999999 && CIN > 0 ){
  bool test=c.ajouter();
  if(test)
{
      //ui->ajouter_matricule->setModel(tmpvente.affichermatricule());
      ui->comcin->setModel(tmpclient.combo_box());
      ui->combocin->setModel(tmpclient.combo_box());
      ui->tableclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
 }
  else {
          QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                      QObject::tr("6 premier chiffres = CIN!.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void MainWindow::on_delc_clicked()
{
    int CIN = ui->comcin->currentText().toInt();
    bool test=tmpclient.supprimer(CIN);
    if(test)
    {
        //ui->ajouter_matricule->setModel(tmpvente.affichermatricule());
        ui->comcin->setModel(tmpclient.combo_box());
        ui->combocin->setModel(tmpclient.combo_box());
        ui->tableclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_updc_clicked()
{
    int CIN = ui->combocin->currentText().toInt();
    QString nom= ui->Qmnom->text();
    QString prenom= ui->Qmprenom->text();
  Client c(CIN,nom,prenom,1);
  bool test=c.modifier();
  if(test)
{    // ui->ajouter_matricule->setModel(tmpvente.affichermatricule());
      ui->comcin->setModel(tmpclient.combo_box());
      ui->combocin->setModel(tmpclient.combo_box());
      ui->tableclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_combocin_activated(const QString &)
{

        QString var=ui->combocin->currentText();
          QSqlQuery query1;
          query1.prepare("select * from CLIENT where CIN=:CIN");
          query1.bindValue(":CIN", var);

          if (query1.exec())
          {

              while (query1.next()) {



                   ui->combocin->setCurrentText(query1.value(0).toString());
                   ui->Qmnom->setText(query1.value(2).toString());
                   ui->Qmprenom->setText(query1.value(3).toString());

              }
          }
}

void MainWindow::on_rechnom_clicked()
{
    QString nom = ui->rechcnom->text();
    ui->tableclient->setModel(tmpclient.recherche_nom(nom));
}

void MainWindow::on_rechcnom_windowIconTextChanged(const QString &arg)
{
    ui->tableclient->setModel(tmpclient.recherche_nom(arg));
}

void MainWindow::on_rechcinn_clicked()
{
    int CIN = ui->rechcin->text().toInt();
    ui->tableclient->setModel(tmpclient.recherche_CIN(CIN));
}

void MainWindow::on_rechcin_windowIconTextChanged(const QString &arg)
{
    int CIN = arg.toInt();
     ui->tableclient->setModel(tmpclient.recherche_CIN(CIN));
}
void MainWindow::on_trier_cin_clicked()
{
    ui->tableclient->setModel(tmpclient.trier_CIN());
}
void MainWindow::on_tricin_clicked()
{
     ui->tableclient->setModel(tmpclient.trier_CIN());
}

void MainWindow::on_tabWidget_3_tabBarClicked(int index)
{
    if (index == 1)
        ui->tableclient->setModel(tmpclient.afficher());
    if (index == 2)
        ui->combocin->setModel(tmpclient.combo_box());
    if (index == 3)
        ui->comcin->setModel(tmpclient.combo_box());

}
//******************************************************carte***********************************************


void MainWindow::on_Qaddcarte_clicked()
{
    int CIN = ui->Qcinclient->currentText().toUInt();
   int numero = ui->Qnumcarte->text().toUInt();



    card c(numero,CIN);
    if(numero < 99999999 && numero > 0 ){
    bool test=c.add_card();
                    if(test)
                  {
                        ui->Qnumcard->setModel(tmpcard.combo_box());


                    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                                      QObject::tr("Client ajouté.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);}
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                   }
                    else {
                            QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                                        QObject::tr("6 premier chiffres = CIN!.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                        }




}
void MainWindow::on_delcard_clicked()
{
    int num = ui->Qnumcard->currentText().toInt();
    bool test=tmpcard.delete_card(num);
    if(test)
    {
        ui->Qnumcard->setModel(tmpcard.combo_box());
        ui->tvcardd->setModel(tmpcard.readCard());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("carte supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_tabWidget_4_currentChanged(int index)
{
    if (index == 0 )
        ui->Qcinclient->setModel(tmpclient.combo_box());
    if (index == 1)
        ui->tvcardd->setModel(tmpcard.readCard());
    if (index ==2)
        ui->Qnumcard->setModel(tmpcard.combo_box());

}

//******************************************************VENTE***************************************************

void MainWindow::on_saveach_clicked()
{
    int cin_cl = ui->cinachat->currentText().toInt();
    int prix = ui->prixtot->text().toInt();
    QDate dat= QDate::currentDate();
    VENTE v(cin_cl,prix,dat);
    int addedbon =prix / 1000;

    if(prix < 99999999 && prix > 0 ){
    bool test=v.ajouterV();

        if(test)
      {
            //ici en va ajouter les instructions de calcuol de bonus achat  metier
            QSqlQuery query1;
            query1.prepare("Select BONUS_ACH from CARD where CIN_CLIENT=:CIN");
            query1.bindValue(":CIN",cin_cl);
                query1.exec();
                     while (query1.next()) {
                   int oldbon=query1.value(0).toInt();



                   int nvb=addedbon+oldbon;
                    v.Addbonus(nvb,cin_cl);

             break;
                 }
                     //si le client n'a pas carte rien ne ce passe au noveau de bonus

            //QSqlQuery query2;
           // query2.prepare("UPDATE card SET bonus_ach =:bon WHERE cin_client =:CIN");
            //query2.bindValue(":bon", nvb);
            //query2.bindValue(":CIN", cin_cl);

            //query2.exec();


             QMessageBox::information(nullptr, QObject::tr("enregistrer une vente "),
                          QObject::tr("achat enregistré.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("enregistrer une vente"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }
        else {
                QMessageBox::critical(nullptr, QObject::tr("Error !"),
                            QObject::tr("check price !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }


}

void MainWindow::on_tabWidget_6_tabBarClicked(int index)
{
    if (index==0)
    {
    ui->cinachat->setModel(tmpclient.combo_box());
    }
    if (index ==1)//affichage
    {
        ui->tabvente->setModel(tmpvente.afficherV());
    }
    if (index ==2)
    {
        ui->idvente->setModel(tmpvente.combo_ID());
        ui->modcomcinvente->setModel(tmpclient.combo_box());
    }
        if (index ==3)
            ui->suppventeid->setModel(tmpvente.combo_ID());

}
void MainWindow::on_idvente_activated(const QString &)
{
    QString var=ui->idvente->currentText();
      QSqlQuery query1;
      query1.prepare("select CIN_CLT, PRIX from vente where ID=:id");
      query1.bindValue(":id", var);

      if (query1.exec())
      {

          while (query1.next()) {

               ui->modprixvente->setText(query1.value(1).toString());
               ui->modcomcinvente->setCurrentText(query1.value(0).toString());
          }
      }
}

void MainWindow::on_modifiervente_clicked()
{
    int id = ui->idvente->currentText().toInt();
    int CIN = ui->modcomcinvente->currentText().toInt();
    int prix= ui->modprixvente->text().toInt();
  VENTE v(CIN,prix);
  bool test=v.modifierV(id);
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Modifier une vente"),
                  QObject::tr("vente modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une vente"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_delvente_clicked()
{
    int ID = ui->suppventeid->currentText().toInt();
    bool test=tmpvente.supprimerV(ID);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Supprimer une vente"),
                    QObject::tr("vente supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une vente"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
//******************************************************ACHAT***************************************************

void MainWindow::on_ajouterP_clicked()
{
    QString nomP= ui->nompA->text();
    int prixP= ui->prixpA->text().toInt();
    int Qt= ui->quapA->text().toInt();
    QDate dat= QDate::currentDate();

    Achat C(prixP,Qt,nomP,dat);
    if(prixP < 99999999 && prixP > 0 ){
        if(Qt < 99999999 && Qt > 0 ){
    bool test=C.ajouter();

        if(test)
      {
            //ici en va ajouter les instructions de calcuol de bonus achat
             QMessageBox::information(nullptr, QObject::tr("enregistrer un achat "),
                          QObject::tr("achat enregistré.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("enregistrer un achat"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }
        else {
                QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                            QObject::tr("verifier la quantite!.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else {
                QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                            QObject::tr("verifier le prix!.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }


}

void MainWindow::on_modcombo_clicked()
{
    int id = ui->idcombo->currentText().toInt();
    QString nom = ui->nomcombo->text();
    int prix= ui->prixcombo->text().toInt();
    int Qt= ui->qtcombo->text().toInt();
    QDate dat= QDate::currentDate();

  Achat c(prix,Qt,nom,dat);
  if(prix < 99999999 && prix > 0 ){
      if(Qt < 99999999 && Qt > 0 ){
  bool test=c.modifier(id);
  if(test)
{
      //ici en va ajouter les instructions de calcuol de bonus achat
       QMessageBox::information(nullptr, QObject::tr("enregistrer un achat "),
                    QObject::tr("achat enregistré.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
  else
      QMessageBox::critical(nullptr, QObject::tr("enregistrer un achat"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
 }
  else {
          QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                      QObject::tr("verifier la quantite!.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
  }
  else {
          QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                      QObject::tr("verifier le prix!.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }


}

void MainWindow::on_tabWidget_7_tabBarClicked(int index)
{
    if (index==1){
        ui->tvachat->setModel(tmpachat.afficher());
        QSqlQuery query1;
        query1.prepare("Select sum(PRIX * QUANTITE) from achat");

        if (query1.exec())
        {

            while (query1.next()) {
                 ui->masrouf->setText(query1.value(0).toString());
                     }
        }

    }
    if (index==2)
        ui->idcombo->setModel(tmpachat.combo_ID());
    if (index==3)
        ui->delcombid->setModel(tmpachat.combo_ID());
}

void MainWindow::on_suppbutt_clicked()
{
    int ID = ui->delcombid->currentText().toInt();
    bool test=tmpachat.supprimer(ID);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Supprimer un achat"),
                    QObject::tr("achat supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un achat"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_idcombo_activated(const QString &)
{
    QString var=ui->idcombo->currentText();
      QSqlQuery query1;
      query1.prepare("select NOMPROD, PRIX, QUANTITE from achat where ID=:id");
      query1.bindValue(":id", var);

      if (query1.exec())
      {

          while (query1.next()) {



               ui->nomcombo->setText(query1.value(0).toString());
               ui->prixcombo->setText(query1.value(1).toString());
               ui->qtcombo->setText(query1.value(2).toString());

          }
      }

}



void MainWindow::on_refrech_clicked()
{
    QSqlQuery query1;
    query1.prepare("Select sum(PRIX) from vente");

    if (query1.exec())
    {

        while (query1.next()) {
             ui->recett->setText(query1.value(0).toString());
                 }
    }

}
