#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avion.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QAbstractSocket>
#include "login.h"
#include "notification.h"
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

    void on_PDF_clicked();

   // void on_pb_mail_clicked();

    void on_alerte_clicked();


    void on_pushConnect_clicked();





    void on_bt_sup_tout_clicked();



    void on_Search_objet_cursorPositionChanged(const QString &arg1);



    void on_trii_clicked();

    void on_pb_ajou_utilisateur_clicked();

    void on_pb_modif_utilisateur_clicked();

    void on_tab_utilisateur_activated(const QModelIndex &index);



    void on_lineEdit_textChanged(const QString &arg1);



    void sendMail();
    void mailSent(QString);
    void browse();

    //void on_sendBtn_clicked();




private:
    Ui::MainWindow *ui;
avion a;
avion atmp;
avion tmp;
QStringList files;
login user;
notification *Notification;

};
#endif // MAINWINDOW_H
