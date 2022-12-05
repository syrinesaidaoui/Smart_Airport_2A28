#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "freeshop.h"
#include <QDataStream>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

    void on_TriID_clicked();

    void on_TriNom_clicked();

    void on_TriType_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_Recherche_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushEnvoyerSMS_clicked(); void postrequest(QString smsmsg,QString phonenumber);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    freeshop F;
};
#endif // MAINWINDOW_H
