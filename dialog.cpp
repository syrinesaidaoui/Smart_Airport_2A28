#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_connect_clicked()
{   int a=0;
    QString NOM_PRENOM=ui->Nom_PRENOM->text();
    QString MOT_DE_PASSE=ui->MOT_DE_PASSE->text();
    QSqlQuery qry;
    qry.prepare("SELECT* from USER1 where NOM_PRENOM='"+NOM_PRENOM+"'and MOT_DE_PASSE='"+MOT_DE_PASSE+"'");
    if(qry.exec())
      {
        while (qry.next())
        {
         if(NOM_PRENOM==qry.value(0) && MOT_DE_PASSE==qry.value(1))
         {
            QMessageBox::information(this,"login","Username and Password are correct");
            hide();
            mainwindow=new MainWindow(this);
            mainwindow->show();
            a=1;
         }
        }
         if(a==0)
            QMessageBox::warning(this,"login","Username and Password are incorrect");


      }

}

