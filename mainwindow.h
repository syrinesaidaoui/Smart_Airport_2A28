#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avion.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QAbstractSocket>
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


    void on_LE_AJOUT_clicked();

    void on_bt_sup_clicked();


    void on_bt_modif_clicked();


    void on_bt_rech_Num_clicked();

    void on_bt_rech_ETAT_clicked();

    void on_bt_rech_MARQUE_clicked();









    void on_bt_tri_num_clicked();

    void on_bt_tri_VITESSE_clicked();



    void on_etat_clicked();


    void on_PDF_clicked();



    void on_pb_mail_clicked();

    void on_alerte_clicked();

    void on_Bt_LOGIN_clicked();

    void on_pushConnect_clicked();

    void on_login_clicked();

    void on_EXPORT_EXCEL_clicked();

private:
    Ui::MainWindow *ui;
avion a;
avion atmp;
avion tmp;
QStringList files;
};
#endif // MAINWINDOW_H
