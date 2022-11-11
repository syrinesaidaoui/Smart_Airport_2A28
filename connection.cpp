#include "connection.h"

connection::connection(){}

bool connection::createconnection()
{ bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("1234");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return test;
}
void connection::closeconnection(){db.close();}
