#include "avion.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QSqlQueryModel>

avion::avion()
{
 marque="";Num=0 ; vitesse = 0 ;consom=0; prix_achat=0; nb_reparation = 0 ; nb_p_changer = 0;etat="" ;

}

avion::avion(int Num,int vitesse ,int nb_reparation,int nb_p_changer ,QString marque,float consom,float prix_achat,QString etat )
{
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
           query.prepare("INSERT INTO AVIONS (NUM_AVION, VITESSE,NB_REPARATION,NB_P_CHANGER,MARQUE,CONSOMATION,PRIX_ACHAT,ETAT) "
                         "VALUES (:NUM_AVION, :VITESSE,:NB_REPARATION,:NB_P_CHANGER,:MARQUE,:CONSOMATION,:PRIX_ACHAT,:ETAT)");

           query.bindValue(":NUM_AVION", Num_string);
           query.bindValue(":VITESSE", VITESSE_string);
           query.bindValue(":NB_REPARATION", NB_REPARATION_string);
           query.bindValue(":NB_P_CHANGER", NB_P_string);
           query.bindValue(":MARQUE", marque);
           query.bindValue(":PRIX_ACHAT", PRIX_ACHAT_string);
           query.bindValue(":CONSOMATION", CONSOM_string);
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
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMATION"));
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

QSqlQueryModel* avion::recherche_ID(int Num)
{
    QString res=QString ::number(Num);

       QSqlQueryModel *model=new QSqlQueryModel();
               model->setQuery("select * from joueur where ID_JOUEUR ='"+res+"'");

               model->setQuery("SELECT* FROM AVIONS where NUM_AVION ='"+res+"'");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMATION"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));


      return model;

}

QSqlQueryModel* avion::recherche_etat(QString etat)
{


    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from AVIONS where ETAT ='"+etat+"'");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMATION"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
           model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));

   return model;

}



QSqlQueryModel* avion::recherche_MARQUE(QString marque)
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from AVIONS where ETAT ='"+marque+"'");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_AVION"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("VITESSE"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_REPARATION"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_P_CHANGER"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("MARQUE"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONSOMATION"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
           model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT"));

   return model;

}


QSqlQueryModel* avion::tri_num(int Num)
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from JOUEUR order by ID_Joueur");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationallite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("num"));

   return model;

}
