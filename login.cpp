#include "login.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QtDebug>
#include<QString>

login::login()
{

}
bool login::createuser()
{
    QSqlQuery query;
    query.prepare("insert into USER1(NOM_PRENOM,MOT_DE_PASSE)"
                  "VALUES(:NOM_PRENOM,:MOT_DE_PASSE)");
    query.bindValue(":NOM_PRENOM",username);
    query.bindValue(":MOT_DE_PASSE",password);
    return query.exec();
}

QSqlQueryModel * login::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT* from USER1");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_PRENOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
return model;
}

bool login::modifier()
{
    QSqlQuery query;
    query.prepare("update USER1 set MOT_DE_PASSE='"+password+"' where NOM_PRENOM='"+username+"' ");
    query.bindValue(1,password);
    return query.exec();
}

bool login::supprimer(QString username)
{
 QSqlQuery query;
 query.prepare("delete from USER1 where NOM_PRENOM= :NOM_PRENOM");
 query.bindValue(0,username);
 return query.exec();
}
