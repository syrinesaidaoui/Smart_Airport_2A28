#ifndef DIALOG_MAILING_H
#define DIALOG_MAILING_H

#include <QDialog>

namespace Ui {
class dialog_mailing;
}

class dialog_mailing : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_mailing(QWidget *parent = nullptr);
    explicit dialog_mailing(QString,QString,QString,QWidget *parent = nullptr);
    ~dialog_mailing();
private slots:
void set_tmpemail(QString e){tmpemail=e;}

void on_envoyer_dialog_2_clicked();
private:
    Ui::dialog_mailing *ui;
    QString tmpemail;
};

#endif // DIALOG_MAILING_H
