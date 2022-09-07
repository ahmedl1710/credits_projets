#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "card.h"
#include "vente.h"
#include "achat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addc_clicked();
    void on_delc_clicked();
    void on_updc_clicked();
    void on_combocin_activated(const QString &);
    void on_rechnom_clicked();
    void on_rechcnom_windowIconTextChanged(const QString &arg);
    void on_rechcinn_clicked();
    void on_rechcin_windowIconTextChanged(const QString &arg);
    void on_trier_cin_clicked();

    void on_tricin_clicked();

    void on_tabWidget_3_tabBarClicked(int index);

    void on_Qaddcarte_clicked();

    void on_tabWidget_4_currentChanged(int index);
    void on_delcard_clicked();

    void on_saveach_clicked();

    void on_tabWidget_6_tabBarClicked(int index);

    void on_modifiervente_clicked();

    //void on_modelv_clicked();

    void on_delvente_clicked();

    void on_ajouterP_clicked();

    void on_modcombo_clicked();

    void on_tabWidget_7_tabBarClicked(int index);

    void on_suppbutt_clicked();

    void on_idcombo_activated(const QString &);

    void on_idvente_activated(const QString &arg1);

    void on_refrech_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpclient;
    card tmpcard;
    VENTE tmpvente;
    Achat tmpachat;
};
#endif // MAINWINDOW_H
