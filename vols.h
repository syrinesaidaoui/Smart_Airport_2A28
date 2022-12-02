#ifndef VOLS_H
#define VOLS_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

#include<QSslSocket>
#include <QAbstractSocket>

class Vols
{
private:
    int numvol;
    int numpilote;
    int numavion;
    QString villedep;
    QString villearr;
    QString heuredep;
    QString heurearr;




public:
    //constructeurs
    Vols();
    Vols(int numvol,int numpilote,int numavion,QString villedep,QString villearr,QString heuredep,QString heurearr);
    //getters
    int getnumvol();
    int getnumpilote();
    int getnumavion();
    QString getvilledep();
    QString getvillarr();
    QString getheuredep();
    QString getheurearr();
    //setters
    void setnumvol(int numvol);
    void setnumpilote(int );
    void setnumavion(int );
    void setvilledep(QString);
    void setvillearr(QString);
    void setheuredep(QString);
    void setheurearr(QString);
    //fonctionnalites
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int numvol);
    bool modifier();
    QSqlQueryModel*recherche (int numvol);
    QSqlQueryModel* trier(QString nom);
    QSqlQueryModel* trier2(QString nom);
    void CREATION_PDF();

};

#endif // VOLS_H
