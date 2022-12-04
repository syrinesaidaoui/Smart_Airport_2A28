#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDataStream>
#include <QMainWindow>
#include <QTextDocument>
#include <QMessageBox>

#include "passagers.h"
#include "connexion.h"
#include "statistiques.h"
#include "WebAxWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Passagers P;

    QSortFilterProxyModel *proxy;

    void show_tables();
    QString get_Num_passport() const;
    QString get_Nom() const;
    QString get_Prenom() const;
    QString get_Date_naissance() const;
    QString get_Sexe() const;
    QString get_Email() const;
    QString get_Bagage() const;
    QString get_Nationalite() const;
    void setNum_passport(QString);
    void setNom(QString);
    void setPrenom(QString);
    void setDatenaissance(QString);
    void setSexe(QString);
    void setEmail(QString);
    void setBagage(int);
    void setNationalite(QString);

    void fill_form(QString);

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_stat_clicked();

    void on_pb_recherche_clicked();

    void on_tab_passagers_doubleClicked(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_pdf_clicked();

    void on_pb_tri_clicked();

    void on_pb_load_clicked();

    void on_pb_search_clicked();

private:

    Ui::MainWindow *ui;
    Statistiques *s;
    QTextDocument *document;
    int selected=0;
};

#endif // MAINWINDOW_H
