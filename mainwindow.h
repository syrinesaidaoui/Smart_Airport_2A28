#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avion.h"
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


    void on_LE_AJOUT_clicked();

    void on_bt_sup_clicked();


    void on_bt_modif_clicked();


    void on_bt_rech_Num_clicked();

    void on_bt_rech_ETAT_clicked();

    void on_bt_rech_MARQUE_clicked();

    void on_bt_tri_clicked();

    void on_bt_recH_PRIX_clicked();

private:
    Ui::MainWindow *ui;
avion a;
avion atmp,btmp,ctmp,dtmp;
};
#endif // MAINWINDOW_H
