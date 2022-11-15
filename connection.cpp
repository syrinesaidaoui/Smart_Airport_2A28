#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("gestion_vols");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("211JFT9152");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeconnection(){db.close();}
