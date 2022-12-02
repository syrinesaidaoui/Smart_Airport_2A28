#include "freeshop.h"

freeshop::freeshop()
{

}
freeshop::freeshop(int REFFERANCE,QString NOM_PRODUIT,QString TYPE_PRODUIT,QDate DATE_EXP,int QUANTITE)
{
    this->NOM_PRODUIT=NOM_PRODUIT;
    this->TYPE_PRODUIT=TYPE_PRODUIT;
    this->QUANTITE=QUANTITE;
    this->REFFERANCE=REFFERANCE;
    this->DATE_EXP=DATE_EXP;

}
QSqlQueryModel * freeshop::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from FREESHOP ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFFERANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EXP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));

    return model;

}
QSqlQueryModel* freeshop ::afficher_reff()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT REFFERANCE from FREESHOP");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFFERANCE"));
    return model;
}
bool freeshop:: ajouter()
{
    QSqlQuery query;
    QString REFFERANCE_string=QString::number(REFFERANCE);
    query.prepare("INSERT INTO FREESHOP(REFFERANCE,QUANTITE,NOM_PRODUIT,TYPE_PRODUIT,DATE_EXP)" "VALUES (:REFFERANCE,:QUANTITE,:NOM_PRODUIT,:TYPE_PRODUIT,:DATE_EXP)");
    query.bindValue(":REFFERANCE", REFFERANCE);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":NOM_PRODUIT",NOM_PRODUIT);
    query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
    query.bindValue(":DATE_EXP",DATE_EXP);

    return query.exec();
}
bool freeshop:: supprimer(int REFFERANCE)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FREESHOP where REFFERANCE=:REFFERANCE");
    query.bindValue(":REFFERANCE", REFFERANCE);
    return   query.exec();


}
bool freeshop::update()
{
    QSqlQuery query;
            query.prepare("UPDATE FREESHOP SET NOM_PRODUIT=:NOM_PRODUIT, TYPE_PRODUIT=:TYPE_PRODUIT,QUANTITE=:QUANTITE, DATE_EXP=:DATE_EXP WHERE REFFERANCE=:REFFERANCE ");
            query.bindValue(":REFFERANCE", REFFERANCE);
            query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);
            query.bindValue(":TYPE_PRODUIT", TYPE_PRODUIT);
            query.bindValue(":QUANTITE", QUANTITE);
            query.bindValue(":DATE_EXP", DATE_EXP);
        return query.exec();
}
QSqlQueryModel *freeshop::tri_reff()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from FREESHOP order by REFFERANCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFFERANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EXP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));


    return model;

}
QSqlQueryModel *freeshop::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from FREESHOP order by NOM_PRODUIT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFFERANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EXP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;
}
QSqlQueryModel *freeshop::tri_type()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from FREESHOP order by TYPE_PRODUIT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFFERANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EXP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;
}
void freeshop::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
void freeshop::chercheReff(QTableView *table, int x)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from FREESHOP where regexp_like(REFFERANCE,:REFFERANCE);");
    query->bindValue(":REFFERANCE",x);
    if(x==0)
    {
        query->prepare("select * from FREESHOP;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void freeshop::chercheNom(QTableView *table, QString x)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from FREESHOP where regexp_like(NOM_PRODUIT,:NOM_PRODUIT);");
    query->bindValue(":NOM_PRODUIT",x);
    if(x==0)
    {
        query->prepare("select * from FREESHOP;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
