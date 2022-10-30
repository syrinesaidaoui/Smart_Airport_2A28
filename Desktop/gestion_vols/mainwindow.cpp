#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDate>
#include "vols.h"
#include <QIntValidator>
#include <QTabWidget>
#include<QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->le_numvol->setValidator( new QIntValidator(0, 9999999, this));
   ui->le_numpilote->setValidator( new QIntValidator(0, 9999999, this));
   ui->le_numavion->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_vols->setModel(v.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int numvol=ui->le_numvol->text().toInt();
    int numpilote=ui->le_numpilote->text().toInt();
    int numavion=ui->le_numavion->text().toInt();
    QString villedep=ui->le_villedep->text();
    QString villearr=ui->le_villearr->text();
    QString heuredep=ui->le_heuredep->text();
    QString heurearr=ui->le_heurearr->text();

  Vols v(numvol,numpilote,numavion,villedep,villearr,heuredep,heurearr);
  bool test=v.ajouter();
  if(test)
  {
      QMessageBox::information(nullptr, QObject::tr("ok"),
                  QObject::tr("ajout effecté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_vols->setModel(v.afficher());



}
  else
      QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                  QObject::tr("ajout non effecte.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    int numvol=(ui->le_numvol_sup->text().toInt());

   bool test=v.supprimer(numvol);
   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("suppression effecté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_vols->setModel(v.afficher());

 }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                   QObject::tr("suppresion non effecte.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pb_recherche_clicked()
{
   int numvol=(ui->le_numvol_rech->text().toInt());
   bool test=v.recherche(numvol);
   if(test)
{
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr(" numvol deja existe.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}


   else
       QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                   QObject::tr(" numvol  n'existe pas.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_clicked()
{
    int numvol=ui->le_numvol_modifier->text().toInt();
    int numpilote=ui->le_numpilote_new->text().toInt();
    int numavion=ui->le_numavion_new->text().toInt();
    bool test=v.modifier(numvol,numpilote,numavion);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modification effecté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_vols->setModel(v.afficher());



  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("modification non effecte.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
