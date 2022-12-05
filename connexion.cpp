#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetA2");//inserer le nom de la source de données ODBC
    db.setUserName("yassine");//inserer nom de l'utilisateur
    db.setPassword("yassine");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}

void connexion::fermerConnexion(){db.close();}

bool connexion::ourirConnexion(){
    if (db.open())
        return true ;
    else
        return false;

}
