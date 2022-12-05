#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
public:
    connexion();
    bool createconnect();
    bool ourirConnexion();
    void fermerConnexion();
    QSqlDatabase db;
};

#endif // CONNEXION_H
