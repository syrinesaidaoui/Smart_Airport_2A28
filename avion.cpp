#include "avion.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSqlQuery>
#include <iostream>
#include <QTextStream>
#define STR_EQUAL 0
#include <cstdlib>
using namespace std;
avion::avion(){
    marque="";
    Num=0 ;
    vitesse = 0 ;
    consom=0;
    prix_achat=0;
    nb_reparation = 0 ;
    nb_p_changer = 0;
    etat="";
}

avion::avion(int Num,int vitesse ,int nb_reparation,int nb_p_changer ,QString marque,float consom,float prix_achat,QString etat ){
    this->marque=marque;
    this->Num=Num;
    this->vitesse=vitesse;
    this->consom=consom;
    this->prix_achat=prix_achat;
    this->nb_reparation=nb_reparation;
    this->nb_p_changer=nb_p_changer;
    this->etat=etat;
}
int avion::getNum()
{
    return Num;
};
int avion::getvitesse()
{
    return vitesse;
}
int avion::getnb_reparation()
{
    return nb_reparation;
}
int avion::getnb_p_changer()
{
    return nb_p_changer;
}
QString avion::getmarque()
{
    return marque;
}
float avion::getconsom(){
    return consom;
}
float avion::getprix_achat()
{
    return prix_achat;
}
QString avion::getetat()
{
    return etat;
}
void avion::setNum(int Num)
{
    this->Num=Num;
}
void avion::setvitesse(int vitesse)
{
    this->vitesse=vitesse;
}
void avion::setnb_reparation(int nb_reparation)
{
    this->nb_reparation=nb_reparation;
}
void avion::setnb_p_changer(int nb_p_changer)
{
    this->nb_p_changer=nb_p_changer;
}
void avion::setmarque(QString marque)
{
    this->marque=marque;
}
void avion::setconsom(float consom)
{
    this->consom=consom;
}
void avion::setprix_achat(float prix_achat)
{
    this->prix_achat=prix_achat;
}
void avion::setetat(QString etat)
{
    this->etat=etat;
}
 bool avion::ajouter()
 {
     QSqlQuery query;
     QString Num_string=QString::number(Num);
     QString VITESSE_string=QString::number(vitesse);
     QString NB_P_string=QString::number(nb_p_changer);
     QString NB_REPARATION_string=QString::number(nb_reparation);
     QString CONSOM_string=QString::number(consom);
     QString PRIX_ACHAT_string=QString::number(prix_achat);
           query.prepare("INSERT INTO AVIONS (NUM_AVION, VITESSE,NB_REPARATION,NB_P_CHANGER,MARQUE,CONSOMMATION,PRIX_ACHAT,ETAT) "
                         "VALUES (:NUM_AVION, :VITESSE,:NB_REPARATION,:NB_P_CHANGER,:MARQUE,:CONSOMMATION,:PRIX_ACHAT,:ETAT)");

           query.bindValue(":NUM_AVION", Num_string);
           query.bindValue(":VITESSE", VITESSE_string);
           query.bindValue(":NB_REPARATION", NB_REPARATION_string);
           query.bindValue(":NB_P_CHANGER", NB_P_string);
           query.bindValue(":MARQUE", marque);
           query.bindValue(":PRIX_ACHAT", PRIX_ACHAT_string);
           query.bindValue(":CONSOMMATION", CONSOM_string);
           query.bindValue(":ETAT", etat);

          return query.exec();
 };
bool avion::supprimer(int n)
     {
     QSqlQuery query;

           query.prepare("Delete from AVIONS where NUM_AVION=:Num");

           query.bindValue(":Num",n);


          return query.exec();
 }


QSqlQueryModel* avion::afficher(){
     QSqlQueryModel* model=new QSqlQueryModel();
           model->setQuery("SELECT* FROM AVIONS");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMMATION"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));

           return model;
}

bool avion::modifier()
{
    QSqlQuery query;
    QString Num_string=QString::number(Num);
    QString VITESSE_string=QString::number(vitesse);
    QString NB_P_string=QString::number(nb_p_changer);
    QString NB_REPARATION_string=QString::number(nb_reparation);
    QString consom_string=QString::number(consom);
    QString prix_string=QString::number(prix_achat);
          query.prepare("UPDATE AVIONS SET VITESSE=:vitesse, NB_REPARATION =:nb_reparation , NB_P_CHANGER=:nb_p_changer, MARQUE=:marque  ,CONSOMATION=:consom , PRIX_ACHAT=:prix_achat , ETAT=:etat  WHERE NUM_AVION =:Num ");

          query.bindValue(":Num", Num_string);
          query.bindValue(":vitesse", VITESSE_string);
          query.bindValue(":nb_reparation", NB_REPARATION_string);
          query.bindValue(":nb_p_changer",NB_P_string );
          query.bindValue(":marque", marque);
          query.bindValue(":consom", consom_string);
          query.bindValue(":prix_achat",prix_string);
          query.bindValue(":etat", etat);

         return query.exec();
}

QSqlQueryModel * avion::recherche(QString res)
     {


         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM AVIONS WHERE ( NUM_AVION LIKE '%"+res+"%' OR VITESSE LIKE '%"+res+"%' OR NB_REPARATION LIKE '%"+res+"%' OR NB_P_CHANGER LIKE '%"+res+"%' OR MARQUE LIKE '%"+res+"%' OR CONSOMMATION LIKE '%"+res+"%' OR PRIX_ACHAT LIKE '%"+res+"%' OR ETAT LIKE '%"+res+"%' ) ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMMATION"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));

         return model;
     }


QSqlQueryModel* avion::tri_Num()
{

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from AVIONS order by NUM_AVION");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMMATION"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
           model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));


   return model;

}

QSqlQueryModel * avion::tri_MARQUE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM AVIONS ORDER BY MARQUE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMMATION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel * avion::tri_vitesse()
{
    QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM AVIONS ORDER BY VITESSE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMMATION"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}


bool avion::supprimerTout()
{
    QSqlQuery query;
          query.prepare("TRUNCATE TABLE AVIONS");
          return query.exec();

}


  int avion::alerte()
{
    QSqlQuery query;
    int i=0;
    QString testing;

    query.prepare(QString("SELECT ETAT FROM AVIONS"));
    query.exec();
    QString panne="PANNE";
    while(query.next()){

        cout<<"etat de la ligne "<<query.value(0).toString().toStdString()<<"  ";
        cout<<(QString::compare(query.value(0).toString(), panne, Qt::CaseInsensitive)== STR_EQUAL)<<endl;

        if(QString::compare(query.value(0).toString(), panne, Qt::CaseInsensitive)== STR_EQUAL)
        {
            i++;
        }
    }

    cout<<"valeur de i "<<i<<endl;

    return i;
}



 void avion::creation_pdf()
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
       q.prepare("SELECT * FROM CITOYEN ");
       q.exec();
       QString pdf="<br> <h1  style='color:blue'>LISTE DES AVIONS  <br></h1>\n <br> <table>  <tr>  <th>NUM_AVION  </th> <th>VITESSE  </th> <th>NB_REPARATION  </th><th>NB_P_CHANGER  </th><th>MARQUE  </th><th>CONSOMATION </th><th>PRIX_ACHAT </th><th>ETAT </th> </tr>" ;
   //br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

       while ( q.next())
           {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +"  <td>"  +q.value(6).toString() +" <td>" +q.value(7).toString() +" <td>" +q.value(8).toString() +"  "" " "</td> </td>" ;
       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
 }

