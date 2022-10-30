#include "vols.h"
#include<QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
#include <QSqlDatabase>
#include <QIntValidator>
Vols::Vols()
{
  numvol=0;
  numpilote=0;
  numavion=0;
  villedep="";
  villearr="";

}
Vols::Vols(int numvol,int numpilote,int numavion ,QString villedep,QString villearr,QString heuredep, QString heurearr)
{
  this->numvol=numvol;
  this->numpilote=numpilote;
  this->numavion=numavion;
  this->villedep=villedep;
  this->villearr=villearr;
  this->heuredep=heuredep;
  this->heurearr=heurearr;


}
int Vols:: getnumvol(){return numvol;}
int Vols:: getnumpilote(){return numpilote;}
int Vols:: getnumavion() {return numavion;}
QString Vols::getvilledep() {return villedep;}
QString Vols::getvillarr() {return villearr;}
QString Vols::getheuredep() {return heuredep;}
QString Vols::getheurearr() {return heurearr;}
void Vols::setnumvol(int numvol){this->numvol=numvol;}
void Vols::setnumpilote(int numpilote ){this->numpilote=numpilote;}
void Vols::setnumavion(int numavion ){this->numavion=numavion;}
void Vols::setvilledep(QString villedep){this->villedep=villedep;}
void Vols::setvillearr(QString villearr){this->villearr=villearr;}
void Vols::setheuredep(QString heuredep ){this->heuredep=heuredep;}
void Vols::setheurearr(QString heurearr){this->heurearr=heurearr;}
bool Vols::ajouter()
{
    QSqlQuery query;
    QString numvol_string = QString::number(numvol);
    QString numpilote_string=QString::number(numpilote);
    QString numavion_string=QString::number(numavion);

          query.prepare("INSERT INTO vols (numvol, numpilote, numavion,villedep,villearr,heuredep,heurearr)  "
                        "VALUES (:numvol, :numpilote, :numavion,:villedep,:villearr,:heuredep,:heurearr)");
          query.bindValue(0,numvol_string );
          query.bindValue(1, numpilote_string);
          query.bindValue(2, numavion_string);
          query.bindValue(3,villedep);
          query.bindValue(4,villearr);
          query.bindValue(5,heuredep);
          query.bindValue(6,heurearr);



    return  query.exec();
}
QSqlQueryModel* Vols::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel() ;


   model->setQuery("SELECT* FROM VOLS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMAVION"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("VILLEDEP"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("VILLEARR"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEUREDEP"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEUREARR"));


   return model;
}

bool Vols::supprimer (int numvol)
{
    QSqlQuery query;
    QString numvol_string = QString::number(numvol);
    query.prepare("Delete from vols where numvol=:numvol");
    query.bindValue(0,numvol );
   return  query.exec();

}
bool Vols::recherche (int numvol)
{
    QSqlQuery query;
    //QString numvol_string = QString::number(numvol);
    query.prepare("select* from vols where numvol=numvol");
    //query.bindValue(0,numvol );
    return query.exec();


}
bool Vols::modifier(int numvol,int numpilote,int numavion)
{
    QSqlQuery query;
    QString numvol_string = QString::number(numvol);
    QString numpilote_string=QString::number(numpilote);
    QString numavion_string=QString::number(numavion);
    query.prepare("update vols set numpilote=:numpilote,numavion=:numavion where numvol=numvol");
   // query.bindValue(0,numvol_string );
    query.bindValue(0, numpilote_string);
    query.bindValue(1, numavion_string);
        return query.exec();


}
