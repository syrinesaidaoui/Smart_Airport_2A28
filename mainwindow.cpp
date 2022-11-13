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

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Num->setValidator(new QIntValidator(0,999,this));
    //ui->le_vitesse->setValidator(new QIntValidator(0,920,this));
    ui->tab_avion->setModel(a.afficher());
      ui->stackedWidget->setCurrentIndex(1);

}


MainWindow::~MainWindow()
{
    delete ui;
}
////////////////////////////////////////////////Connect

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
    QString marque=ui->le_marque->text();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
    QString etat=ui->le_etat->text();
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
    QString marque=ui->le_marque->text();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
    QString etat=ui->le_etat->text();

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








void MainWindow::on_bt_rech_Num_clicked()
    {
       int Num=ui->chercher_Num->text().toInt();
              {  if (Num==0) {
                    QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter a Number."));
                    return;
                } else {
                ui->tab_recherche->setModel(atmp.recherche_ID(Num));
            }}
    }




void MainWindow::on_bt_rech_ETAT_clicked()
 {
         QString etat=ui->chercher_etat->text();
              {  if (etat==0) {
                    QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter a Number."));
                    return;
                } else {
                ui->tab_recherche->setModel(atmp.recherche_etat(etat));
            }}
    }



void MainWindow::on_bt_rech_MARQUE_clicked()
{

            QString marque=ui->chercher_marque->text();
                 {  if (marque==0) {
                       QMessageBox::information(this, tr("Empty Field"),
                           tr("Please enter a Number."));
                       return;
                   } else {
                   ui->tab_recherche->setModel(atmp.recherche_MARQUE(marque));
               }}
}



void MainWindow::on_bt_tri_num_clicked()
{
    ui->tab_recherche->setModel(atmp.tri_Num());
 }
void MainWindow::on_bt_tri_VITESSE_clicked()
{
     ui->tab_recherche->setModel(atmp.tri_vitesse());
}


void MainWindow::on_etat_clicked()
{
     ui->tab_recherche->setModel(atmp.tri_Etat());
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


void MainWindow::on_pb_mail_clicked()
    {
     Smtp* smtp = new Smtp("ghaith.elbenna@esprit.tn", "211JMT8242", "smtp.gmail.com", 465);
     connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
     QString a=ui->Linemail->text();
     QString b=ui->Lineobjet->text();
     QString c=ui->msg->toPlainText();

     smtp->sendMail("ghaith.elbenna@esprit.tn", a , b,c);
    }



void MainWindow::on_alerte_clicked()
{
    if (a.alerte()>0)
                {
                    QString notif=QString::number(a.alerte())+" etat panne .\n""Click Ok to exit.";
                    QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
                }
        else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("etat non panne  \n""Click Ok to exit."), QMessageBox::Ok);
}


void MainWindow::on_EXPORT_EXCEL_clicked()
{QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                 tr("Excel Files (*.xls)"));
      QString sheetName="test";
ExportExcelObject obj(fileName, sheetName, ui->tab_avion);
obj.addField(0, tr("Num"), "int");
obj.addField(1, tr("VITESSE"), "int");
obj.addField(2, tr("NB_REPARATION"), "int");
obj.addField(3, tr("NB_P_CHANGER"), "int");
obj.addField(4, tr("MARQUE"), "char(20)");
obj.addField(5, tr("CONSOMATION"), "FLOAT");
obj.addField(6, tr("PRIX_ACHAT"), "FLOAT");
obj.addField(7, tr("ETAT"), "char(20)");
obj.export2Excel();
}
