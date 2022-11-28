#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avion.h"
#include <QApplication>
#include <QMessageBox>
#include<QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include<QDateTime>
#include <QTextStream>
#include <smtp.h>
#include<QString>
#include <QtNetwork>
#include <QAbstractSocket>
#include "exportexcelobject.h"
#include <cstdlib>
#include "login.h"
#include "notification.h"
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    ui->le_Num->setValidator(new QIntValidator(0,999,this));
    ui->le_nb_p_changer->setValidator(new QIntValidator(0,6,this));
   ui->le_nb_reparation->setValidator(new QIntValidator(0,20,this));
    //ui->le_vitesse->setValidator(new QIntValidator(0,920,this));
    //ui->tab_avion->setModel(a.afficher());
    ui->stackedWidget->setCurrentIndex(1);
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}



void MainWindow::on_pushConnect_clicked(){


    QString login=ui->linelogin->text();
    QString mdp=ui->linemdp->text();
    if ((login=="ghaith")&&(mdp=="ghaith"))


    {
        ui->stackedWidget->setCurrentIndex(0);
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes.\n" "click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NON"),QObject::tr("mot de passe ou nom d'utilisateur erroné.\n " "click Cancel to exit ."), QMessageBox::Cancel);


}


//////////////////////////////////////////////////////crud

void MainWindow::on_LE_AJOUT_clicked()
{
    int Num=ui->le_Num->text().toInt();
    int vitesse=ui->le_vitesse->text().toInt();
    int nb_reparation=ui->le_nb_reparation->text().toInt();
    int nb_p_changer=ui->le_nb_p_changer->text().toInt();
    QString marque = ui->comboBox_marque->currentText();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
    QString etat = ui->comboBox_ETAT->currentText();
 avion a(Num,vitesse,nb_reparation,nb_p_changer,marque,consom,prix_achat,etat);
 bool test=a.ajouter();

 if(test)
 {
  QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("AJOUT EFFECTUER.\n" "click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_avion->setModel(a.afficher());
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("NON"),QObject::tr("AJOUT NON EFFECTUER.\n " "click Cancel to exit ."), QMessageBox::Cancel);

}



void MainWindow::on_bt_sup_clicked()
{
    int n=ui->le_Num->text().toInt();
         bool test=a.supprimer(n);
         if (test)
         {
             ui->tab_avion->setModel(a.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                          QObject ::tr("suppression effectué\n"
                                       "click cancel to exit"),
                     QMessageBox:: Cancel);

        }
         else
         {
             QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("try again.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
         }
    }




void MainWindow::on_bt_modif_clicked()
{
    int Num=ui->le_Num->text().toInt();
    int vitesse=ui->le_vitesse->text().toInt();
    int nb_reparation=ui->le_nb_reparation->text().toInt();
    int nb_p_changer=ui->le_nb_p_changer->text().toInt();
     QString marque = ui->comboBox_marque->currentText();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
   QString etat = ui->comboBox_ETAT->currentText();

 avion a(Num,vitesse,nb_reparation,nb_p_changer,marque,consom,prix_achat,etat);
 bool test=a.modifier();

               if(test)

           {ui->tab_avion->setModel(a.afficher());


               QMessageBox :: information (nullptr, QObject ::tr("OK"),

                            QObject ::tr("modifier effectué\n"

                                         "click cancel to exit"),

                       QMessageBox:: Cancel);



       }

           else

           {

               QMessageBox::critical(nullptr,QObject::tr("not ok"),

                                    QObject::tr("try again.\n"

                                                "click cancel to exit."),QMessageBox::Cancel);

           }
}



void MainWindow::on_Search_objet_cursorPositionChanged(const QString &arg1)
{
     ui->tab_recherche->setModel(a.recherche(arg1));
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_recherche->setModel(atmp.recherche(arg1));

}

void MainWindow::on_trii_clicked()
{
    switch (ui->comboBox_trii->currentIndex()) {
    case 0:
        ui->tab_recherche->setModel(atmp.tri_Num());
        break;
    case 1:
        ui->tab_recherche->setModel(atmp.tri_vitesse());
        break;
    case 2:
          ui->tab_recherche->setModel(atmp.tri_MARQUE());
        break;
    }

}


void MainWindow::on_PDF_clicked()
{
  QString strStream;
            strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(strStream).suffix().isEmpty())
                    { strStream.append(".pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(strStream);

                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_avion->model()->rowCount();
                      const int columnCount = ui->tab_avion->model()->columnCount();
                      QString TT = QDateTime::currentDateTime().toString();
                      out <<"<html>\n"
                            "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          << "<title>ERP - COMmANDE LIST<title>\n "
                          << "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                            +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />" //path
                          "<h1 style=\"text-align: center;\"><strong> *****LISTE DES AVIONS ***** </strong></h1>"

                          "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                            "</br> </br>";
                      // headers
                      out << "<thead><tr bgcolor=#d6e5ff>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_avion->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_avion->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++)
                        {
                              if (!ui->tab_avion->isColumnHidden(column)) {
                                  QString data =ui->tab_avion->model()->data(ui->tab_avion->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "</body>\n"
                          "</html>\n";

                      QTextDocument document;
                      document.setHtml(strStream);
                      document.print(&printer);
}



/*void MainWindow::on_pb_mail_clicked()
    {
     Smtp* smtp = new Smtp("ghaith.elbenna@esprit.tn", "211JMT8242", "smtp.gmail.com", 465);
     connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
     QString a=ui->Linemail->text();
     QString b=ui->Lineobjet->text();
     QString c=ui->msg->toPlainText();

     smtp->sendMail("ghaith.elbenna@esprit.tn", a , b,c);
    }

*/

void MainWindow::on_alerte_clicked()
{
    if (a.alerte()>0)
                {
                    QString notif=QString::number(a.alerte())+" etat panne .\n""Click Ok to exit.";
                    QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);

                    //notification notification;
                    //notification.setModal(true);
                    //notification.exec();
                     Notification =new notification(this);
                     Notification->show();
                      A.write_to_arduino("1");
    }
        else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("etat non panne  \n""Click Ok to exit."), QMessageBox::Ok);
}




void MainWindow::on_bt_sup_tout_clicked()
{avion ast;
    bool test = ast.supprimerTout();
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes.");
    ui->tab_recherche->setModel(ast.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}


void MainWindow::on_pb_ajou_utilisateur_clicked()
{

    QString nomPrenom=ui->AJOUTER_NOM_PRENOM->text();
    QString mp1=ui->AJOUTER_mot_de_Passe->text();
    QString mp2=ui->AJOUTER_mot_de_Passe2->text();

    login user1(nomPrenom,mp1);
    bool test=user1.createuser();
    if(mp1!=mp2)
        test=0;
    if(test)
    {
        ui->tab_utilisateur->setModel(user1.afficher());


        QMessageBox::information(this,"ok","ajout effectué");
    }
    else
        QMessageBox::warning(this,"not ok","ajout non effectué");
}

void MainWindow::on_pb_modif_utilisateur_clicked()
{
    login l;
    l.setusername(ui->AJOUTER_NOM_PRENOM->text());
    bool test=l.supprimer(l.getusername());

    if(ui->AJOUTER_NOM_PRENOM->text()==NULL)
        test=0;
    if(test)
    {
         QMessageBox::information(this," ok","suppression effectué");
         ui->tab_utilisateur->setModel(l.afficher());
         //ui->comboBox3->setModel(l.afficher());
    }
    else
    QMessageBox::warning(this,"not ok","suppression non effectué");
}


void MainWindow::on_tab_utilisateur_activated(const QModelIndex &index)
{
    QString username=ui->tab_utilisateur->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT* from USER1 where username='"+username+"'");
    if(qry.exec())
        {
            while (qry.next())
                {
                  ui->AJOUTER_NOM_PRENOM->setText(qry.value(0).toString());
                  ui->AJOUTER_NOM_PRENOM->setText(qry.value(1).toString());
                }
        }
}









/*
void MainWindow::on_pushButton_clicked()
{Dialog dialog;
    MainWindow* m;
    dialog.show();
    m->close();
}*/


void MainWindow::on_Onn_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_Off_clicked()
{
    A.write_to_arduino("0");
}
