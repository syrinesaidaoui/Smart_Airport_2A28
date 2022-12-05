/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "webaxwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox;
    QPushButton *Ajouter;
    QPushButton *Modifier;
    QPushButton *Supprimer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LineReff;
    QLineEdit *LineNom;
    QLineEdit *LineType;
    QDateEdit *dateEdit;
    QLineEdit *LineQuant;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_2;
    QTableView *tableView;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *TriNom;
    QPushButton *TriID;
    QPushButton *TriType;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineRecherche;
    QPushButton *Recherche;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *tab_3;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *LineNumTel;
    QTextEdit *textEdit;
    QPushButton *pushEnvoyerSMS;
    QWidget *tab_4;
    WebAxWidget *WebBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1201, 701));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 190, 141, 151));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_4->addWidget(comboBox);

        Ajouter = new QPushButton(layoutWidget);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));

        verticalLayout_4->addWidget(Ajouter);

        Modifier = new QPushButton(layoutWidget);
        Modifier->setObjectName(QStringLiteral("Modifier"));

        verticalLayout_4->addWidget(Modifier);

        Supprimer = new QPushButton(layoutWidget);
        Supprimer->setObjectName(QStringLiteral("Supprimer"));

        verticalLayout_4->addWidget(Supprimer);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 190, 221, 152));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        LineReff = new QLineEdit(layoutWidget1);
        LineReff->setObjectName(QStringLiteral("LineReff"));

        verticalLayout_2->addWidget(LineReff);

        LineNom = new QLineEdit(layoutWidget1);
        LineNom->setObjectName(QStringLiteral("LineNom"));

        verticalLayout_2->addWidget(LineNom);

        LineType = new QLineEdit(layoutWidget1);
        LineType->setObjectName(QStringLiteral("LineType"));

        verticalLayout_2->addWidget(LineType);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        verticalLayout_2->addWidget(dateEdit);

        LineQuant = new QLineEdit(layoutWidget1);
        LineQuant->setObjectName(QStringLiteral("LineQuant"));

        verticalLayout_2->addWidget(LineQuant);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(160, 190, 91, 151));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 1181, 531));
        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(450, 550, 281, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TriNom = new QPushButton(layoutWidget3);
        TriNom->setObjectName(QStringLiteral("TriNom"));

        horizontalLayout_2->addWidget(TriNom);

        TriID = new QPushButton(layoutWidget3);
        TriID->setObjectName(QStringLiteral("TriID"));

        horizontalLayout_2->addWidget(TriID);

        TriType = new QPushButton(layoutWidget3);
        TriType->setObjectName(QStringLiteral("TriType"));

        horizontalLayout_2->addWidget(TriType);

        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 580, 81, 18));
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(110, 580, 121, 18));
        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 550, 281, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LineRecherche = new QLineEdit(layoutWidget4);
        LineRecherche->setObjectName(QStringLiteral("LineRecherche"));

        horizontalLayout->addWidget(LineRecherche);

        Recherche = new QPushButton(layoutWidget4);
        Recherche->setObjectName(QStringLiteral("Recherche"));

        horizontalLayout->addWidget(Recherche);

        layoutWidget5 = new QWidget(tab_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(1050, 550, 131, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(layoutWidget5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_4 = new QPushButton(layoutWidget5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget6 = new QWidget(tab_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(420, 200, 221, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget6);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        LineNumTel = new QLineEdit(layoutWidget6);
        LineNumTel->setObjectName(QStringLiteral("LineNumTel"));

        horizontalLayout_3->addWidget(LineNumTel);

        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(420, 230, 391, 161));
        pushEnvoyerSMS = new QPushButton(tab_3);
        pushEnvoyerSMS->setObjectName(QStringLiteral("pushEnvoyerSMS"));
        pushEnvoyerSMS->setGeometry(QRect(550, 400, 131, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        WebBrowser = new WebAxWidget(tab_4);
        WebBrowser->setControl(QStringLiteral("{8856F961-340A-11D0-A96B-00C04FD705A2}"));
        WebBrowser->setObjectName(QStringLiteral("WebBrowser"));
        WebBrowser->setProperty("focusPolicy", QVariant::fromValue(Qt::StrongFocus));
        WebBrowser->setProperty("geometry", QVariant(QRect(0, 50, 1191, 621)));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 111, 23));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 20, 131, 23));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        Supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Referance", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom Produit", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Type Produit", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Date Expiration", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Quantit\303\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Freeshop informations", Q_NULLPTR));
        TriNom->setText(QApplication::translate("MainWindow", "Tri Nom", Q_NULLPTR));
        TriID->setText(QApplication::translate("MainWindow", "Tri Reff", Q_NULLPTR));
        TriType->setText(QApplication::translate("MainWindow", "Tri Type", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Refferance", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Nom du produit", Q_NULLPTR));
        Recherche->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Stats", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher Tableau", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Num Tel :", Q_NULLPTR));
        pushEnvoyerSMS->setText(QApplication::translate("MainWindow", "Envoyer SMS", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "SMS", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Hamila Duty Free", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "TDF - Tunis Duty Free", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Map", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
