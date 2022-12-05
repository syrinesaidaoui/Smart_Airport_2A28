/********************************************************************************
** Form generated from reading UI file 'dialog_stats.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STATS_H
#define UI_DIALOG_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog_stats
{
public:
    QCustomPlot *plot;

    void setupUi(QDialog *Dialog_stats)
    {
        if (Dialog_stats->objectName().isEmpty())
            Dialog_stats->setObjectName(QStringLiteral("Dialog_stats"));
        Dialog_stats->resize(1061, 684);
        plot = new QCustomPlot(Dialog_stats);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(0, 0, 1061, 681));

        retranslateUi(Dialog_stats);

        QMetaObject::connectSlotsByName(Dialog_stats);
    } // setupUi

    void retranslateUi(QDialog *Dialog_stats)
    {
        Dialog_stats->setWindowTitle(QApplication::translate("Dialog_stats", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_stats: public Ui_Dialog_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STATS_H
