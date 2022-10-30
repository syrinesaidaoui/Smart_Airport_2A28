#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_employes->setModel(Em.afficherEmployes());
    ui->le_idE->setValidator(new QIntValidator(0,9999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{  //récupération des informations saisies à travers l'interface graphique
    int idE=ui->le_idE->text().toInt();
    QString nomE=ui->le_nomE->text();
    QString prenomE=ui->le_prenomE->text();
    QString adresse=ui->le_adresse->text();
    QString telephone=ui->le_telephone->text();
    QString e_mail=ui->le_e_mail->text();
    QString date_embauche=ui->le_date_embauche->text();
    QString salaire=ui->le_salaire->text();
    QString prime=ui->le_prime->text();
    QString designation=ui->le_designation->text();

    Employes E(idE,nomE,prenomE,adresse,telephone,e_mail,date_embauche,salaire,prime,designation);
    bool test=E.ajouterEmployes();
    //refresh table view
    ui->tab_employes->setModel(Em.afficherEmployes());

    if(test)
{        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("Ajout bien effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{
    Employes E;
    E.setIDE(ui->le_id_sup->text().toInt());
    bool test=E.supprimerEmployes(E.getIDE());
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                    QObject::tr("Suppression bien effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //refresh table view
        ui->tab_employes->setModel(E.afficherEmployes());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                    QObject::tr("Suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
   Employes Emod;
   Emod.setIDE(ui->le_id_modif->text().toInt());
//récupération des valeurs à changer
   QString adresse=ui->le_nouv_adresse->text();
   QString telephone=ui->le_nouv_tele->text();
   QString salaire=ui->le_nouv_salaire->text();
   QString prime=ui->le_nouv_prime->text();
  bool test=Emod.modifierEmployes(Emod.getIDE(),adresse,telephone,salaire,prime);
  if(test)
  {
          QMessageBox::information(nullptr, QObject::tr("Ok"),
                      QObject::tr("modification bien effectuée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
          //refresh table view
          ui->tab_employes->setModel(Emod.afficherEmployes());

  }
      else
          QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                      QObject::tr("modification non effectuée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
