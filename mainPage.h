#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtSql>
#include <QPushButton>


QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

QT_CHARTS_USE_NAMESPACE

class ThemeWidget: public QWidget
{
    Q_OBJECT
public:
    explicit ThemeWidget(QWidget *parent = 0);
    ~ThemeWidget();

private Q_SLOTS:
    void updateUI();

private:
    void populateThemeBox();
    void populateAnimationBox();
    void connectSignals();

    QChart *createAreaChart() const;

private:
    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    QList<QChartView *> m_charts;

    Ui_ThemeWidgetForm *m_ui;
    QSqlDatabase db;

private slots:
    void handleButton();
    void handleButtonLogin();

private:
    QPushButton *m_button1;
//    QPushButton *pushButton;
};

#endif
