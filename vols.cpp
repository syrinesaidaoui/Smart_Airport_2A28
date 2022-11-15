#include "vols.h"
#include<QString>
#include <QSqlQuery>
#include<QtDebug>
#include<QDate>
#include<QObject>
#include <QSqlDatabase>
#include <QIntValidator>
/********************** ta3 pdf ***************/
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>


#include <QAbstractSocket>
#include<QSslSocket>

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
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));


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
bool Vols::modifier()
{
    QSqlQuery query;
    QString numvol_string = QString::number(numvol);
    QString numpilote_string=QString::number(numpilote);
    QString numavion_string=QString::number(numavion);
    query.prepare("UPDATE VOLS SET NUMPILOTE='"+numpilote_string+"',VILLEDEP='"+villedep+"',VILLEARR='"+villearr+"',HEUREDEP='"+heuredep+"',HEUREARR='"+heurearr+"',NUMAVION='"+numavion_string+"' WHERE NUMVOL='"+numvol_string+"'");
    query.bindValue(0,numvol_string );
    query.bindValue(1, numpilote_string);
    query.bindValue(2, numavion_string);
     query.bindValue(3,villedep );
     query.bindValue(4,villearr );
     query.bindValue(5,heuredep );
     query.bindValue(6,heurearr );
        return query.exec();


}
QSqlQueryModel* Vols::recherche(int numvol)
{

   QSqlQueryModel* model=new QSqlQueryModel() ;
    QString numvol_string = QString::number(numvol);

   model->setQuery("select * from vols where numvol='"+numvol_string+"'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));


   return model;
}

  QSqlQueryModel* Vols::trier(QString nom)
  {

     QSqlQueryModel* model=new QSqlQueryModel() ;
     if (nom=="NumV")

     {
     model->setQuery("select * from vols  order by  numvol");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="NumA")

     {
     model->setQuery("select * from vols  order by  numavion");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="NumP")

     {
     model->setQuery("select * from vols  order by  numpilote");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="heuredep")

     {
     model->setQuery("select * from vols  order by  heuredep");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="heurearr")

     {
     model->setQuery("select * from vols  order by  heurrearr");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }

     return model;
  }
  QSqlQueryModel* Vols::trier2(QString nom)
  {

     QSqlQueryModel* model=new QSqlQueryModel() ;
     if (nom=="NumV")

     {
     model->setQuery("select * from vols  order by  numvol desc");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="NumA")

     {
     model->setQuery("select * from vols  order by  numavion desc ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="NumP")

     {
     model->setQuery("select * from vols  order by  numpilote desc");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="heuredep")

     {
     model->setQuery("select * from vols  order by  heuredep desc");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }
     if (nom=="heurearr")

     {
     model->setQuery("select * from vols  order by  heurrearr desc");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMVOL"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMPILOTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMAVION"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLEDEP"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("VILLEARR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEUREDEP"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("HEUREARR"));
     }

     return model;
  }



void Vols::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
        { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM VOLS ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE DES VOLS  <br></h1>\n <br> <table>  <tr>  <th>NumV </th> <th>NumP </th> <th>NumA  </th> <th>villedep  </th><th>villearr  </th><th>heuredep   </th><th>heurearr   </th>  </tr>" ;
//br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

    while ( q.next())
        {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);


}
