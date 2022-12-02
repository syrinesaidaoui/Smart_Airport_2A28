#ifndef FREESHOP_H
#define FREESHOP_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QTableView>
#include <QFile>

class freeshop
{
public:
    freeshop();
    freeshop(int,QString,QString,QDate,int);
    //get
    QString get_NomProduit(){return NOM_PRODUIT;}
    QString get_TypeProduit(){return TYPE_PRODUIT;}
    QDate get_DateEXP(){return DATE_EXP;}
    int get_Reff(){return REFFERANCE;}
    int get_quantite(){return QUANTITE;}
    //set
    void set_NomProduit(QString n){NOM_PRODUIT=n;}
    void set_TypeProduit(QString t){TYPE_PRODUIT=t;}
    void set_DateEXP(QDate dateexp){DATE_EXP=dateexp;}
    void set_Reff(int refferance){REFFERANCE=refferance;}
    void set_quantite(int quantite){QUANTITE=quantite;}
    //fonctions
    bool ajouter();
    bool supprimer(int);
    bool update();
    //affichage
    QSqlQueryModel * afficher();
    QSqlQueryModel* afficher_reff();
    //trier
    QSqlQueryModel* tri_reff();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_type();
    void clearTable(QTableView * table);
    void chercheReff(QTableView *table, int x);
    void chercheNom(QTableView *table, QString x);
private:
    QString NOM_PRODUIT;
    QString TYPE_PRODUIT;
    QDate DATE_EXP;
    int REFFERANCE;
    int QUANTITE;
};

#endif // FREESHOP_H
