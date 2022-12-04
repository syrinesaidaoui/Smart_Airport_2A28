#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createConnexion()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("211jme0477");//inserer mot de passe de cet utilisateur


if (db.open()) test = true;


return test;

}

void Connexion::closeConnexion()
{
    db.close();
}
