#ifndef VOLS_H
#define VOLS_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
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
    bool recherche (int numvol);
    bool modifier(int numvol,int numpilote,int numavion);

};

#endif // VOLS_H
