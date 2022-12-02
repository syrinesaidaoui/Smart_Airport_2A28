#ifndef PASSAGERS_H
#define PASSAGERS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


class Passagers
{
public:

    Passagers();
    Passagers(QString Num_passport,QString Nom,QString Prenom, QString Date_naissance, QString Sexe, QString Email, int Bagage, QString Nationalite);

    QString get_Num_passport() const;
    QString get_Nom() const;
    QString get_Prenom() const;
    QString get_Date_naissance() const;
    QString get_Sexe() const;
    QString get_Email() const;
    int get_Bagage() const;
    QString get_Nationalite() const;

    void setNum_passport(QString);
    void setNom(QString);
    void setPrenom(QString);
    void setDatenaissance(QString);
    void setSexe(QString);
    void setEmail(QString);
    void setBagage(int);
    void setNationalite(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel* recherche();
    QSqlQueryModel* RechercheP();
    bool modifier(QString Num_passport,QString Nom,QString Prenom, QString Date_naissance, QString Sexe, QString Email, int Bagage, QString Nationalite);
    QSqlQueryModel *trier();


private:
    QString Num_passport;
    QString Nom;
    QString Prenom;
    QString Date_naissance;
    QString Sexe;
    QString Email;
    int Bagage;
    QString Nationalite;

};

#endif // PASSAGERS_H
