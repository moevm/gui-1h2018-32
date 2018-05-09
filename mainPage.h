#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QtXml>
#include <QXmlStreamReader>
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtSql>
#include <QPushButton>
#include "newsone.h"

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
    static QString userIn;
    void change();
    static int newsId;

private Q_SLOTS:
    void updateUI();
    void handleButton(QMap<QString,QString>);

private:
    void populateThemeBox();
    void populateAnimationBox();
    void connectSignals();
    QString themeNew;

    QChart *createAreaChart(QMap<QString,QString> items) const;

signals:
    void sendData(QString str);
    void otpravka(QString, QString);

private:
    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    QList<QChartView *> m_charts;
    Ui_ThemeWidgetForm *m_ui;
    QSqlDatabase db;

private slots:

    void handleButtonLogin();
    void handleButtonSignUp();
    void handleButtonExit();

    void parseXML();
    void selectTheme(QString);

private:
    QPushButton *m_button1;
    newsOne *myform;
    QMap<QString, QString> parseItem(QXmlStreamReader& xml);
    void addElementDataToMap(QXmlStreamReader& xml,
                                 QMap<QString, QString>& map) const;
};

#endif
