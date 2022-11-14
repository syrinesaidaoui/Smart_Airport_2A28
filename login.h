#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "QtDebug"
#include "QtSql"
#include "QFileInfo"
#include "avion.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:


private:
    Ui::Login *ui;
    QSqlDatabase mydb;
};

#endif // LOGIN_H
