#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDate>
#include "vols.h"
#include <QIntValidator>
#include <QTabWidget>
#include<QApplication>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QDate>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
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

using qrcodegen::QrCode ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->le_numvol->setValidator( new QIntValidator(0, 9999999, this));
   ui->le_numpilote->setValidator( new QIntValidator(0, 9999999, this));
   ui->le_numavion->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_vols->setModel(v.afficher());
   ui->fontComboBox->addItem("NumV");
   ui->fontComboBox->addItem("NumP");
   ui->fontComboBox->addItem("NumA");



   connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
   connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
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


void  MainWindow::browse()
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
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("oumeyma.sokkeh@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("oumeyma.sokkeh@esprit.tn", ui->rcpt->text() , ui->subject->text() ,ui->msg->text(), files );
    else
        smtp->sendMail("oumeyma.sokkeh@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->text());
}
void   MainWindow::mailSent(QString status)
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
