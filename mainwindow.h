#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QFileDialog>
#include <QDialog>
#include "vols.h"
#include "smtp.h"
#include "qrcode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_recherche_clicked();

    void on_pb_modifier_clicked();

   // void on_pushButton_7_clicked();

    void on_pb_pdf_clicked();

       void sendMail();
       void mailSent(QString);
       void browse();

       void on_pb_code_clicked();

       void on_pb_excel_clicked();

       void on_pb_trier_clicked();

       void on_pb_act_clicked();

private:
    Ui::MainWindow *ui;
    Vols v;
    QStringList files;
    QTcpSocket *socket ;
};

#endif // MAINWINDOW_H
