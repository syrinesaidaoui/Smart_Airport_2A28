#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connexion C;
     C.createConnexion();

     show_tables();

    ui->tab_passagers->setModel(P.afficher());

    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");

}

MainWindow::~MainWindow()
{
    delete ui;

      show_tables();
}


void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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
    s = new Statistiques();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}

void MainWindow::on_pb_recherche_clicked()
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

void MainWindow::on_pb_modifier_clicked()
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

void MainWindow::on_pb_pdf_clicked()
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

void MainWindow::on_pb_search_clicked()
{
    Passagers P3;
    QString Num= ui->le_re->text();
    //ui->tri_table->setModel(P3.RechercheP());
}
