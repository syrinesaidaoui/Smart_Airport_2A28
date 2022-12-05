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

#include <cstdlib>
#include "login.h"
#include "notification.h"





#include<QDate>
#include "vols.h"
#include <QIntValidator>
#include <QTabWidget>
#include<QApplication>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileInfo>
#include  <QLineEdit>
#include  <QPlainTextEdit>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include "smtp.h"
#include<QSslSocket>
#include <QAbstractSocket>
//***taa il qrcode *******
#include <QPixmap>
#include<QDirModel>
#include <QSvgRenderer>
#include <QtSvg/QSvgRenderer>
#include <fstream>
#include "qrcode.h"
#include<QRegularExpression>
#include "excel.h"

#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQueryModel>
#include <QPrinter>
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include<QPainter>
#include<QImage>
#include<QSqlQuery>
#include<QIntValidator>
#include<QRegExpValidator>


//////////////////////////////
#include "dialog_mailing.h"
#include "freeshop.h"
#include "dialog_stats.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QPdfWriter>
#include <QPainter>
#include <QRadioButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QEventLoop>
#include <QtDebug>


using qrcodegen::QrCode ;
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ///***********BEGIN ARDUINO***********
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    ///***********END ARDUINO***********

    ///////////////////////////////////////////////////////////////////////ghaith
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    ui->le_Num->setValidator(new QIntValidator(0,999,this));
    ui->le_nb_p_changer->setValidator(new QIntValidator(0,6,this));
   ui->le_nb_reparation->setValidator(new QIntValidator(0,20,this));
    //ui->le_vitesse->setValidator(new QIntValidator(0,920,this));
    ui->tab_avion->setModel(a.afficher());
    ui->stackedWidget->setCurrentIndex(5);

    ////////////////////////////////////////////////////////////////////////////////oumayma
    ui->le_numvol->setValidator( new QIntValidator(0, 9999999, this));
    ui->le_numpilote->setValidator( new QIntValidator(0, 9999999, this));
    ui->le_numavion->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_vols->setModel(v.afficher());
    ui->fontComboBox->addItem("NumV");
    ui->fontComboBox->addItem("NumP");
    ui->fontComboBox->addItem("NumA");
    ui->stackedWidget->setCurrentIndex(5);


    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMailO()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browseO()));

//////////////////////////////////////////////////////////////////////////////syrine

    ui->tab_employes->setModel(Em.afficherEmployes());
    //valider que 7 chiffres
    ui->le_idE->setValidator(new QIntValidator(0,9999999, this));
    //valider que les adresses mail
    QRegExp rx("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    QRegExpValidator *valiEmail =new QRegExpValidator(rx,this);
     ui->le_e_mail->setValidator(valiEmail);
   //AFFichage de la statistique
    Employes E;
    ui->VL_statistique->addWidget(E.statistiqueEmployes());
   ui->stackedWidget->setCurrentIndex(5);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushConnect_clicked(){


    QString login=ui->linelogin->text();
    QString mdp=ui->linemdp->text();
    if ((login=="ghaith")&&(mdp=="1")){
        ui->stackedWidget->setCurrentIndex(0);
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes bienvenue au gestion d'avion.\n" "click Cancel to exit."), QMessageBox::Cancel);

     }
    else if ((login=="oumeyma")&&(mdp=="2"))

    {
       ui->stackedWidget->setCurrentIndex(1);
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes.\n" "click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ((login=="syrine")&&(mdp=="3"))

    {
       ui->stackedWidget->setCurrentIndex(2);
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes.\n" "click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ((login=="yassine")&&(mdp=="4"))

    {
       ui->stackedWidget->setCurrentIndex(3);
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes.\n" "click Cancel to exit."), QMessageBox::Cancel);

    }
    else if ((login=="emmanuel")&&(mdp=="5"))

    {
       ui->stackedWidget->setCurrentIndex(4);
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("conncté avec succes.\n" "click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NON"),QObject::tr("mot de passe ou nom d'utilisateur erroné.\n " "click Cancel to exit ."), QMessageBox::Cancel);





}
////////////////////////////////////////////////////////////////////////ghaith
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
 avion a(Num,vitesse,nb_reparation,nb_p_changer,marque,prix_achat,consom,etat);
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

    }
        else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("etat non panne  \n""Click Ok to exit."), QMessageBox::Ok);
}




void MainWindow::on_bt_sup_tout_clicked()
{
    bool test = a.supprimerTout();

    if(test){
        ui->tab_avion->setModel(atmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("la table est vide !\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("suppression non effectué\n""Click to Cancel."), QMessageBox::Cancel);
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






void MainWindow::update_labelg()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_73->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_73->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}


void MainWindow::on_Onn_clicked()
{
    A.write_to_arduino("1");

}

void MainWindow::on_Off_clicked()
{
    A.write_to_arduino("0");
    cout<<"0";
    QMessageBox::information(this," ok","attend 30 sec pour atteindre le buzzer");
}

void MainWindow::on_deconnexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
////////////////////////////////////////////////////////////////////////////////////////////oumayma


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
    ui->tab_vols->setModel(v.recherche(numvol));
   /*int numvol=(ui->le_numvol_rech->text().toInt());
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
                               "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void MainWindow::on_pb_modifier_clicked()
{
    int numvol=ui->le_numvol_modifier->text().toInt();
    int numpilote=ui->le_numpilote_new->text().toInt();
    int numavion=ui->le_numavion_new->text().toInt();
     QString villedep=ui->le_villedep_new->text();
     QString villearr=ui->le_villearr_new->text() ;
     QString heuredep=ui->le_heuredep_new->text() ;
     QString heurearr=ui->le_heurearr_new->text() ;

    Vols v(numvol,numpilote,numavion,villedep,villearr,heuredep,heurearr) ;
    bool test=v.modifier();
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


void MainWindow::on_pb_pdf_clicked()
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

                  const int rowCount = ui->tab_vols->model()->rowCount();
                  const int columnCount = ui->tab_vols->model()->columnCount();
                  QString TT = QDateTime::currentDateTime().toString();
                  out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title>ERP - COMmANDE LIST<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"
                         "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                        +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />"
                      "<h1 style=\"text-align: center;\"><strong> *****LISTE DES VOLS ***** </strong></h1>"

                      "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                        "</br> </br>";
                  // headers
                  out << "<thead><tr bgcolor=#d6e5ff>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tab_vols->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tab_vols->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++)
                    {
                          if (!ui->tab_vols->isColumnHidden(column)) {
                              QString data =ui->tab_vols->model()->data(ui->tab_vols->model()->index(row, column)).toString().simplified();
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


void  MainWindow::browseO()
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
void   MainWindow::sendMailO()
{
    Smtp* smtp = new Smtp("oumeyma.sokkeh@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("oumeyma.sokkeh@esprit.tn", ui->rcpt->text() , ui->subject->text() ,ui->msg1->text(), files );
    else
        smtp->sendMail("oumeyma.sokkeh@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg1->text());
}
void   MainWindow::mailSentO(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



void MainWindow::on_pb_code_clicked()
{
    if(ui->tab_vols->currentIndex().row()==-1)
              QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                       QObject::tr("Veuillez Choisir un vol du Tableau.\n"
                                                   "Click Ok to exit."), QMessageBox::Ok);
          else
          {




                      v.setnumvol(ui->le_numvol ->text().toInt());
                      v.setnumpilote(ui->le_numpilote ->text().toInt());
                      v.setnumavion(ui->le_numavion ->text().toInt());
                      v.setvilledep(ui->le_villedep ->text());
                      v.setvillearr(ui->le_villearr ->text());
                      v.setheuredep(ui->le_heuredep ->text());
                      v.setheurearr(ui->le_heurearr ->text());






            QString  rawQr = "NUMVOL:%1 NUMPILOTE:%2 NUMAVION:%3 VILLEDEP:%4 VILLEARR:%5 HEUREDEP:%6 HEUREARR:%7 " ;
               rawQr = rawQr.arg(v.getnumvol()).arg(v.getnumpilote()).arg(v.getnumavion()).arg(v.getvilledep()).arg(v.getvillarr()).arg(v.getheuredep()).arg(v.getheurearr());
               QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);



               std::ofstream myfile;
               myfile.open ("qrcode.svg") ;
               myfile << qr.toSvgString(1);
               myfile.close();
               QSvgRenderer svgRenderer(QString("qrcode.svg"));
               QPixmap pix( QSize(140, 140) );
               QPainter pixPainter( &pix );
               svgRenderer.render( &pixPainter );
               ui->label_qrcode->setPixmap(pix);
          }
}

void MainWindow::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                          tr("Excel Files (*.xls)"));
          if (fileName.isEmpty())
              return;

          ExportExcelObject obj(fileName, "mydata", ui->tab_vols);   ///

          //colums to export
          obj.addField(2, "numvol", "char(20)");
          obj.addField(3, "numpilote", "char(20)");
          obj.addField(4, "numavion", "char(20)");
          obj.addField(1, "villedep", "char(20)");
          obj.addField(0, "villearr", "char(20)");
          obj.addField(0, "heuredep", "char(20)");
           obj.addField(0, "heurearr", "char(20)");


          int retVal = obj.export2Excel();
          if( retVal > 0)
          {
              QMessageBox::information(this, tr("Done"),
                                       QString(tr("%1 records exported!")).arg(retVal)
                                       );
          }

}

void MainWindow::on_pb_trier_clicked()
{
    QString nom=ui->fontComboBox->currentText();
    if (ui->croissant->isChecked())
    {
    ui->tab_vols->setModel(v.trier(nom));
    }
    else if (ui->decroissant->isChecked())
    {
    ui->tab_vols->setModel(v.trier2(nom));
    }
}

void MainWindow::on_pb_act_clicked()
{
  ui->tab_vols->setModel(v.afficher());
}


void MainWindow::update_label()
{
    QByteRef a=A.read_from_arduino()[0];
    if (a == 'A'){
        //data="";
        qDebug()<<data;
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM VOLS where NUMVOL ="+data);
        qDebug()<<"SELECT * FROM VOLS where NUMVOL ="+data;
        if (model->rowCount()==0){
            A.write_to_arduino("identifiant erroné");
            qDebug()<<"identifiant erroné";
            data="";
        }else{
            QByteArray nom = model->data(model->index(0,0)).toByteArray();
            A.write_to_arduino("   num vol "+nom);
            qDebug()<<"num vol "<<nom;
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("porte ouvert.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }else if (a=='1' || a=='2' || a=='3' || a=='4' || a=='5' || a=='6' || a=='7' || a=='8' || a=='9' )
       {
       data+=a;
       } else if (a == 'X') {

       } else if (a == 'C') {
        QMessageBox::information(nullptr, QObject::tr("distance"),
                        QObject::tr("distance less than 10.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       } else if (a == 'D') {
        QMessageBox::information(nullptr, QObject::tr("distance"),
                        QObject::tr("distance less than 10.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }

   qDebug()<<data;

}
void MainWindow::on_OFF_ARDUINO_OS_clicked()
{
     A.write_to_arduino("a");
}


void MainWindow::on_deconnexion_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



///////////////////////////////////////////////////////////////////syrine
void MainWindow::on_pb_ajouter_1_clicked()
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
void MainWindow::on_pb_supprimer_1_clicked()
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

void MainWindow::on_pb_modifier_2_clicked()
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

void MainWindow::on_pb_load_name_clicked()
{ Employes E1;
   ui->tri_table->setModel(E1.afficherEmployes());
}

void MainWindow::on_pb_search_clicked()
{
    Employes E2;
    QString nomS=ui->le_nom_search->text();
    ui->tri_table->setModel(E2.RechercheEmployes(nomS));

}

void MainWindow::on_pb_sort_clicked()
{
    Employes Et;
    ui->tri_table->setModel(Et.trier());
}


void MainWindow::on_pb_pdf_1_clicked()
{
    QPdfWriter pdf("C:/Users/Syrin/Desktop/QT/FicheDesEmployés.pdf");
    QPainter painter(&pdf);
    int i = 4000;

    QImage img("C:/Users/Syrin/Desktop/QT/Smart Airport.png");
               Q_ASSERT(!img.isNull());
               painter.drawImage(QRect(200, 200, 2000, 2000), img);

                    painter.setPen(Qt::darkBlue);
                    painter.setFont(QFont("euphemia", 40));
                    painter.drawText(2200,1500,"Fiche Des Employés");
                    painter.setPen(Qt::black);
                    painter.setFont(QFont("calibri", 20));
                   // painter.drawRect(100,100,7300,2600);
                    painter.drawRect(0,3000,9600,500);
                    painter.setFont(QFont("consolas", 9));
                    painter.drawText(200,3300,"ID:");
                    painter.drawText(1300,3300,"NOM:");
                    painter.drawText(2400,3300,"PRENOM:");
                    painter.drawText(3500,3300,"ADRESSE:");
                    painter.drawText(4600,3300,"TELEPHONE:");
                    painter.drawText(5700,3300,"E_MAIL:");
                    painter.drawText(7200,3300,"DATE_EMBAUCHE:");
                    QSqlQuery query;
                    query.prepare("select * from employes");
                    query.exec();
                    while (query.next())
                    {
                        painter.drawText(200,i,query.value(0).toString());
                        painter.drawText(1300,i,query.value(1).toString());
                        painter.drawText(2400,i,query.value(2).toString());
                        painter.drawText(3500,i,query.value(3).toString());
                        painter.drawText(4600,i,query.value(4).toString());
                        painter.drawText(5700,i,query.value(5).toString());
                        painter.drawText(7200,i,query.value(6).toString());
                       i = i + 600;
                    }
                    if(painter.end())
                    {
                        QMessageBox::information(nullptr, QObject::tr("FICHE EMPLOYEE"),
                                                 QObject::tr("Fichier employee Genere.\n"
                                                             "Click Ok to exit."), QMessageBox::Ok);
                    }
           }



/*

{
    c= new camera();
       c->show();
}


void MainWindow::on_actionOpen_triggered()
{       //pour videoplayer
    player=new QMediaPlayer(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    QString filename=QFileDialog::getOpenFileName(this,"Open a file","","(*.mpg *.mp4)");
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Stopped");
}*/

void MainWindow::on_deconnexion_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////yassinnnnn
void MainWindow::on_Ajouter_clicked()
{
    int REFFERANCE=ui->LineReff->text().toInt();
    QString NOM_PRODUIT=ui->LineNom->text();
    QString TYPE_PRODUIT=ui->LineType->text();
    QDate DATE_EXP=ui->dateEdit->date();
    int QUANTITE=ui->LineQuant->text().toInt();
    freeshop F(REFFERANCE,NOM_PRODUIT,TYPE_PRODUIT,DATE_EXP,QUANTITE);
    bool test=F.ajouter();
    if(test)
    {
        ui->comboBox->setModel(F.afficher_reff());
        ui->tableView->setModel(F.afficher());
    }
}

void MainWindow::on_Modifier_clicked()
{
    int REFFERANCE=ui->LineReff->text().toInt();
    QString NOM_PRODUIT=ui->LineNom->text();
    QString TYPE_PRODUIT=ui->LineType->text();
    QDate DATE_EXP=ui->dateEdit->date();
    int QUANTITE=ui->LineQuant->text().toInt();
    freeshop F(REFFERANCE,NOM_PRODUIT,TYPE_PRODUIT,DATE_EXP,QUANTITE);
    bool test=F.update();
    if(test)
    {
        ui->comboBox->setModel(F.afficher_reff());
        ui->tableView->setModel(F.afficher());
    }
}

void MainWindow::on_Supprimer_clicked()
{
    freeshop F;
    F.set_Reff(ui->comboBox->currentText().toInt());
    bool test=F.supprimer(F.get_Reff());
    if(test)
    {
        ui->tableView->setModel(F.afficher());
        ui->comboBox->setModel(F.afficher_reff());
    }
}

void MainWindow::on_TriID_clicked()
{
    ui->tableView->setModel(F.tri_reff());
}

void MainWindow::on_TriNom_clicked()
{
    ui->tableView->setModel(F.tri_nom());
}

void MainWindow::on_TriType_clicked()
{
    ui->tableView->setModel(F.tri_type());
}
void MainWindow::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:/Users/MSI/Desktop/projet2A28/Freeshop/Liste.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/alamo/Desktop/yassine/TacheQt/Logo.jpg"));
    painter.drawText(3000,1500,"LISTE DES PRODUITS");
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(2700,200,6300,2600);
    painter.drawRect(0,3000,9600,500);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"REFFERANCE");
    painter.drawText(1800,3300,"NOM_PRODUIT");
    painter.drawText(3300,3300,"TYPE_PRODUIT");
    painter.drawText(4900,3300,"DATE_EXP");
    painter.drawText(6600,3300,"QUANTITE");
    QSqlQuery query;
    query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti=localtime(&tt);
    asctime(ti);
    painter.drawText(500,300, asctime(ti));
    query.prepare("select * from FREESHOP");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(1800,i,query.value(1).toString());
        painter.drawText(3300,i,query.value(2).toString());
        painter.drawText(4900,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());

        i = i +500;
    }
    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI/Desktop/projet2A28/Freeshop/Liste.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    dialog_stats stats;
    stats.setModal(true);
    stats.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    dialog_mailing mail;
    mail.setModal(true);
    mail.exec();
}

void MainWindow::on_Recherche_clicked()
{
    freeshop A;
    QString text;

    if (ui->radioButton->isChecked()==true)
    {
        F.clearTable(ui->tableView);
        int REFFERANCE=ui->LineRecherche->text().toInt();
        F.chercheReff(ui->tableView,REFFERANCE);
    }
    if (ui->radioButton_2->isChecked()==true)
    {
        F.clearTable(ui->tableView);
        QString Nom=ui->LineRecherche->text();
        F.chercheNom(ui->tableView,Nom);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int)
{
    int REFFERANCE=ui->comboBox->currentText().toInt();
    QString REFFERANCE_1=QString::number(REFFERANCE);
    QSqlQuery query1,query2,query3,query4;
    query1.prepare("SELECT * FROM FREESHOP where REFFERANCE='"+REFFERANCE_1+"'");
    if(query1.exec())
    {
        while (query1.next())
        {
            ui->LineReff->setText(query1.value(0).toString());
            ui->LineNom->setText(query1.value(1).toString());
            ui->LineType->setText(query1.value(2).toString());
            ui->dateEdit->setDate(query1.value(3).toDate());
            ui->LineQuant->setText(query1.value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("ECHEC DE chargement .\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::postrequest(QString smsmsg,QString phonenumber)
{

    // create custom temporary event loop on stack
       QEventLoop eventLoop;

       // "quit()" the event-loop, when the network request "finished()"
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

       // the HTTP request
       QNetworkRequest req( QUrl( QString("https://api.orange.com/smsmessaging/v1/outbound/tel%3A%2B322804/requests") ) );

      req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



req.setRawHeader("Authorization", "Bearer xr2ulyME2QIJqpkgl0GcIaVsmx7b");
QJsonObject msg;
msg["message"] = smsmsg;
QJsonObject obj;
obj["address"] = "tel:+216"+phonenumber;
obj["senderAddress"] = "tel:+322804";
obj["outboundSMSTextMessage"] = msg;
QJsonObject body;
body["outboundSMSMessageRequest"] = obj;
QJsonDocument doc(body);
QByteArray data = doc.toJson();
       QNetworkReply *reply = mgr.post(req,data);
       eventLoop.exec(); // blocks stack until "finished()" has been called

       if (reply->error() == QNetworkReply::NoError) {
           //success
           qDebug() << "Success" <<reply->readAll();
           delete reply;
       }
       else {
           //failure
           qDebug() << "Failure" <<reply->errorString() << reply->error();
           delete reply;
       }
}
void MainWindow::on_pushEnvoyerSMS_clicked()
{
    QString numtel=ui->LineNumTel->text();
    QString msg=ui->textEdit->toPlainText();
    postrequest(msg,numtel);
}

void MainWindow::on_pushButton_clicked()
{
    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Hamila+Duty+Free/@36.8558231,10.201266,887m/data=!3m2!1e3!4b1!4m6!3m5!1s0x12fd34cd7b245fbd:0xccc0fd40631b371b!8m2!3d36.8558188!4d10.2034547!16s%2Fg%2F11csqf4nd_");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/TDF+-+Tunis+Duty+Free/@36.8064991,10.1793429,887m/data=!3m2!1e3!4b1!4m6!3m5!1s0x12fd352853ff041d:0x5cd8a36923851ad0!8m2!3d36.8064948!4d10.1815316!16s%2Fg%2F11h_jcdk9c");
}

void MainWindow::on_deconnexion_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


///////////////////////////////////////////////////////////////////////////EMMANUEL
void MainWindow::on_pb_ajouter_2_clicked()
{
    QString Num_passport = ui->le_passport->text();
    QString Nom = ui->le_nom->text();
    QString Prenom = ui->le_prenom->text();
    QString Date_naissance = ui->da_naissance->date().toString("dd.MM.yyyy");
    QString Sexe = ui->le_sexe->currentText();
    QString Email = ui->le_email->text();
    int Bagage = ui->le_bagage->text().toInt();
    QString Nationalite = ui->le_nationalite->text();

    Passagers P(Num_passport, Nom, Prenom, Date_naissance, Sexe, Email, Bagage, Nationalite);
  bool test=P.ajouter();
  if(test)
{

      ui->tab_passagers->setModel(P.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Passagers Ajouter"),
                  QObject::tr("Passagers Ajouter.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Passagers Ajouter"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  show_tables();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QString Num_passport = ui->le_passport_sup->text();
    bool test=P.supprimer(Num_passport);
    if(test)
    {ui->tab_passagers->setModel(P.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("passagers supprimer"),
                    QObject::tr("Passager supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression impossible"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    show_tables();
}

void MainWindow::on_pb_stat_clicked()
{
    s = new statistiques();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}

void MainWindow::on_pb_recherche_2_clicked()
{
    bool test;
    Passagers P2;
        P2.setNum_passport(ui->rech->text());
        test=P2.recherche();
        if(ui->rech->text()==NULL || test==0)
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                     QObject::tr("echec\nclick cancel to exit"),QMessageBox::Cancel);
        else
        ui->tab_passagers->setModel(P2.recherche());
}

void MainWindow::on_tab_passagers_doubleClicked(const QModelIndex &index)
{
    selected=ui->tab_passagers->model()->data(index).toInt();
}

void MainWindow::on_pb_modifier_3_clicked()
{
    Passagers P1;
    P1.setNum_passport(ui->le_id_mod->text());
    QString Nom = ui->le_nom_2->text();
    QString Prenom = ui->le_prenom_2->text();
    QString Date_naissance = ui->da_naissance_2->date().toString("dd.MM.yyyy");
    QString Sexe = ui->le_sexe_2->currentText();
    QString Email = ui->le_email_2->text();
    int Bagage = ui->le_bagage_2->text().toInt();
    QString Nationalite = ui->le_nationalite_2->text();

    bool test=P1.modifier(P1.get_Num_passport(), Nom, Prenom, Date_naissance, Sexe, Email, Bagage, Nationalite);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("passager modifier"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_passagers->setModel(P.afficher());//refresh
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("echec de modification"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_pdf_2_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_passagers->model()->rowCount();
                const int columnCount =ui->tab_passagers->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des Evenements</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_passagers->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_passagers->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_passagers->isColumnHidden(column)) {
                                   QString data = ui->tab_passagers->model()->data(ui->tab_passagers->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("mypdffile.pdf");
        document->print(&printer);
}

void MainWindow::show_tables()
{
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(P.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tab_passagers->setModel(proxy);

}


void MainWindow::on_pb_tri_clicked()
{
    Passagers P;
    ui->tri_table->setModel(P.trier());
}

void MainWindow::on_pb_load_clicked()
{
    Passagers P2;
    ui->tri_table->setModel(P2.afficher());
}

void MainWindow::on_pb_search1_clicked()
{
    Passagers P3;
    QString Num= ui->le_re->text();
    //ui->tri_table->setModel(P3.RechercheP());
}




void MainWindow::on_deconnexion_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}





