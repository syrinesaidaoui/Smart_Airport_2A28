#include "passagers.h"
#include <QDebug>
#include <QSqlQuery>
#include "connexion.h"

Passagers::Passagers()
{
    Num_passport ="";
    Nom ="";
    Prenom ="";
    Date_naissance ="";
    Sexe ="";
    Email ="";
    Bagage =0;
    Nationalite ="";
}

Passagers::Passagers(QString Num_passport,QString Nom,QString Prenom, QString Date_naissance, QString Sexe, QString Email, int Bagage, QString Nationalite)
{
    this->Num_passport=Num_passport;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Date_naissance=Date_naissance;
    this->Sexe=Sexe;
    this->Email=Email;
    this->Bagage=Bagage;
    this->Nationalite=Nationalite;
}

QString Passagers::get_Num_passport() const
{
    return Num_passport;
}

QString Passagers::get_Nom() const
{
    return Nom;
}

QString Passagers::get_Prenom() const
{
    return Prenom;
}

QString Passagers::get_Date_naissance() const
{
    return Date_naissance;
}

QString Passagers::get_Sexe() const
{
    return Sexe;
}

QString Passagers::get_Email() const
{
    return Email;
}

int Passagers::get_Bagage() const
{
    return Bagage;
}

QString Passagers::get_Nationalite() const
{
    return Nationalite;
}

void Passagers::setNum_passport(QString Num_passport){ this->Num_passport=Num_passport;}
void Passagers::setNom(QString Nom){ this->Nom=Nom;}
void Passagers::setPrenom(QString Prenom){this->Prenom=Prenom;}
void Passagers::setDatenaissance(QString Date_Naissance){this->Date_naissance=Date_Naissance;}
void Passagers::setSexe(QString Sexe){ this->Sexe=Sexe;}
void Passagers::setEmail(QString Email){ this->Email=Email;}
void Passagers::setBagage(int Bagage){ this->Bagage=Bagage;}
void Passagers::setNationalite(QString Nationalite){ this->Nationalite=Nationalite;}

bool Passagers::ajouter()
{
QSqlQuery query;
//QString Date= QString::number(Date_naissance);
QString Bag= QString::number(Bagage);
query.prepare("INSERT INTO passagers (NUM_PASSPORT, NOM, PRENOM, DATE_NAISSANCE, SEXE, EMAIL, BAGAGE, NATIONALITE) "
                    "VALUES (:Num_passport, :Nom, :Prenom, :Date_naissance, :Sexe, :Email, :Bagage, :Nationalite)");
query.bindValue(":Num_passport", Num_passport);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Date_naissance", Date_naissance);
query.bindValue(":Sexe", Sexe);
query.bindValue(":Email", Email);
query.bindValue(":Bagage", Bag);
query.bindValue(":Nationalite", Nationalite);


return    query.exec();
}

QSqlQueryModel * Passagers::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM PASSAGERS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_passport"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Bagage"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalité"));
    return model;
}

QSqlQueryModel* Passagers::recherche()
{
    QSqlQuery query;

    query.prepare("SELECT * FROM PASSAGERS WHERE NUM_PASSPORT = :Num_passport ");
    query.bindValue(":Num_passport", Num_passport);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery(query);
    return model;
}

QSqlQueryModel *Passagers::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PASSAGERS order by NUM_PASSPORT asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_passport"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Bagage"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalité"));
        return model;
}

bool Passagers::supprimer(QString Passport)
{
QSqlQuery query;
query.prepare("DELETE FROM PASSAGERS WHERE NUM_PASSPORT = :Num_passport ");
query.bindValue(":Num_passport", Passport);
return    query.exec();
}

bool Passagers::modifier(QString Passport,QString Nom,QString Prenom, QString Date_naissance, QString Sexe, QString Email, int Bagage, QString Nationalite)
{
QSqlQuery query;
//QString Date= QString::number(Date_naissance);
QString Bag= QString::number(Bagage);
query.prepare("UPDATE PASSAGERS SET NOM=:Nom, PRENOM=:Prenom, DATE_NAISSANCE =:Date_naissance, SEXE =:Sexe, EMAIL =:Email, BAGAGE =:Bagage, NATIONALITE=:Nationalite WHERE NUM_PASSPORT= :Num_passport");
query.bindValue(":Num_passport", Passport);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Date_naissance", Date_naissance);
query.bindValue(":Sexe", Sexe);
query.bindValue(":Email", Email);
query.bindValue(":Bagage", Bag);
query.bindValue(":Nationalite", Nationalite);


return    query.exec();
}

/*QSqlQueryModel* Passagers::RechercheP()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PASSAGERS order by NUM_PASSPORT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_passport"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Bagage"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalité"));
        return model;
}*/
