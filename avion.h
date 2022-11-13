#ifndef AVION_H
#define AVION_H
#include<QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <iostream>
using namespace std;

class avion
{
public:
    avion();
    avion(int Num,int vitesse,int nb_reparation,int nb_p_changer,QString marque,float consom,float prix_achat,QString etat);
    int getNum();
    int getvitesse();
    int getnb_reparation();
    int getnb_p_changer();
    QString getmarque();
    QString getetat();
    float getconsom();
    float getprix_achat();
    void setNum(int);
    void setvitesse(int);
    void setnb_reparation(int);
    void setnb_p_changer(int);
    void setmarque(QString);
     void setetat(QString);
    void setconsom(float);
    void setprix_achat(float);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    /////////////////////////////////////////////recherche

    QSqlQueryModel *recherche_ID(int);
    QSqlQueryModel *recherche_etat(QString );
    QSqlQueryModel *recherche_MARQUE(QString );

    ////////////////////////////////////tri

    QSqlQueryModel *tri_Num();
    QSqlQueryModel *tri_Etat();
    QSqlQueryModel *tri_vitesse();

    //////////////////////////////////alerte
   int alerte();
    //////////////////////////////////pdf
    void creation_pdf();
    ////////////////////////////
     bool login();

private:
    QString marque;
    QString etat;
    int Num;
    int vitesse;
    float consom ;
    float prix_achat;
    int nb_reparation;
    int nb_p_changer;

};

#endif // AVION_H
