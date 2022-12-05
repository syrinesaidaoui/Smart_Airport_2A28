#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avion.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QAbstractSocket>
#include "login.h"
#include "notification.h"
#include "dialog.h"
#include "arduino.h"
///OUMAYMA
#include "vols.h"
#include "qrcode.h"
////SYRINE
#include "employes.h"
#include <QMediaPlayer>
#include <QVideoWidget>
////YASSIN
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

///EMANUEL

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
//#include "connexion.h"
#include "statistiques.h"
//#include "WebAxWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /////////////////////////////////////////////////////////////EMMANUEL
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
    void update_labelg();
    void on_Onn_clicked();

    void on_Off_clicked();
////////////////////////////////////////oumayma
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_recherche_clicked();

    void on_pb_modifier_clicked();

   // void on_pushButton_7_clicked();

    void on_pb_pdf_clicked();

       void sendMailO();
       void mailSentO(QString);
       void browseO();

       void on_pb_code_clicked();

       void on_pb_excel_clicked();

       void on_pb_trier_clicked();

       void on_pb_act_clicked();

       void on_deconnexion_clicked();

       void on_deconnexion_2_clicked();
       void on_OFF_ARDUINO_OS_clicked();
       void update_label();
/////////////////////////////////////////////////////////////:syrine

      void on_pb_ajouter_1_clicked();


       void on_pb_supprimer_1_clicked();

      void on_pb_modifier_2_clicked();

       void on_pb_load_name_clicked();

       void on_pb_search_clicked();

       void on_pb_sort_clicked();

      void on_pb_pdf_1_clicked();
/* void on_camera_clicked();

  void on_actionOpen_triggered();
  void on_actionPlay_triggered();
  void on_actionStop_triggered();

*/





      void on_deconnexion_3_clicked();
///////////////////////////////////////////////////////////////////yassinnnnn

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
      /////////////////////////////////////////////////////////////////////////////////////////////////EMMANUEL

     void on_pb_ajouter_2_clicked();


     void on_pb_supprimer_2_clicked();

      void on_pb_stat_clicked();

     void on_pb_recherche_2_clicked();

      void on_tab_passagers_doubleClicked(const QModelIndex &index);

      void on_pb_modifier_3_clicked();

      void on_pb_pdf_2_clicked();

      void on_pb_tri_clicked();

      void on_pb_load_clicked();

      void on_pb_search1_clicked();















      void on_deconnexion_4_clicked();

      void on_deconnexion_5_clicked();





private:
    Ui::MainWindow *ui;
avion a;
avion atmp;
avion tmp;
QStringList files;
login user;
notification *Notification;
Arduino A;
Vols v,vo;
QTcpSocket *socket;
Employes Em;
//QMediaPlayer* player;
//QVideoWidget* vw;
//QProgressBar* bar;
QSlider* slider;
 //camera *c;
freeshop F;
statistiques *s;
QTextDocument *document;
int selected=0;
QByteArray data;
};
#endif // MAINWINDOW_H
