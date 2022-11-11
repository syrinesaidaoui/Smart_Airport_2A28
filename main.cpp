#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool teste=c.createconnection();
    MainWindow w;
    if(teste)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("data base is open"),QObject::tr("connection successful.\n" "click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed.\n " "click Cancel to exit ."), QMessageBox::Cancel);
    return a.exec();
}
