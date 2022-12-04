#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();

private:
    Ui::Statistiques *ui;
};

#endif // STATISTIQUES_H
