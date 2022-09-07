#ifndef CARD_H
#define CARD_H
#include <QSqlQuery>
#include <QSqlQueryModel>


class card
{
public:
    card();
    card(int,int,int);
    card(int,int);
    int get_numero();
    int get_bonus();
    int get_cinclient();
    bool add_card();
    QSqlQueryModel * readCard();
    bool delete_card(int);
    bool update_crard(int);
    bool update_bonus(int );
    QSqlQueryModel * combo_box();
    QSqlQueryModel * search_CIN(int CIN);
    QSqlQueryModel * search_NUM(int num);


private:
    int numero;
    int bonus_ach;
    int cin_client;


};

#endif // CARD_H
