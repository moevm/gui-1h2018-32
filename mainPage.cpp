#include "mainPage.h"
#include "ui_telegramNews.h"

#include <QtCharts/QChartView>

ThemeWidget::ThemeWidget(QWidget *parent) :
    QWidget(parent),
    m_listCount(3),
    m_valueMax(10),
    m_valueCount(7),
    m_ui(new Ui_ThemeWidgetForm)
{
    m_ui->setupUi(this);
    populateThemeBox();
    populateAnimationBox();

    QChartView *chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 1, 0);
    m_charts << chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 1, 1);
    m_charts << chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 1, 2);
    m_charts << chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 2, 0);
    m_charts << chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 2, 1);
    m_charts << chartView;

    chartView = new QChartView(createAreaChart());
    m_ui->gridLayout->addWidget(chartView, 2, 2);
    m_charts << chartView;

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    qApp->setPalette(pal);

    updateUI();
}

ThemeWidget::~ThemeWidget()
{
    delete m_ui;
}

void ThemeWidget::populateThemeBox()
{
    m_ui->themeComboBox->addItem("Светлая", QChart::ChartThemeLight);
    m_ui->themeComboBox->addItem("Голубая", QChart::ChartThemeBlueCerulean);
    m_ui->themeComboBox->addItem("Темная", QChart::ChartThemeDark);
    m_ui->themeComboBox->addItem("Коричневая", QChart::ChartThemeBrownSand);
    m_ui->themeComboBox->addItem("Синяя", QChart::ChartThemeBlueNcs);
    m_ui->themeComboBox->addItem("Оранжевая", QChart::ChartThemeHighContrast);
    m_ui->themeComboBox->addItem("Голубая волна", QChart::ChartThemeBlueIcy);
    m_ui->themeComboBox->addItem("Классическая", QChart::ChartThemeQt);
}

void ThemeWidget::populateAnimationBox()
{
    m_ui->animatedComboBox->addItem("Кино", QChart::NoAnimation);
    m_ui->animatedComboBox->addItem("Музыка", QChart::GridAxisAnimations);
    m_ui->animatedComboBox->addItem("Бизнес", QChart::SeriesAnimations);
    m_ui->animatedComboBox->addItem("Криптовалюта", QChart::AllAnimations);
}

QChart *ThemeWidget::createAreaChart() const
{
    QChart *chart = new QChart();
    chart->setTitle("Area chart");
}

void ThemeWidget::updateUI()
{
    QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(
                m_ui->themeComboBox->itemData(m_ui->themeComboBox->currentIndex()).toInt());
    const auto charts = m_charts;
    if (!m_charts.isEmpty() && m_charts.at(0)->chart()->theme() != theme) {
        for (QChartView *chartView : charts) {
            chartView->chart()->setTheme(theme);
        }

        QPalette pal = window()->palette();
        if (theme == QChart::ChartThemeLight) {
            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        //![8]
        } else if (theme == QChart::ChartThemeDark) {
            pal.setColor(QPalette::Window, QRgb(0x121218));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBlueCerulean) {
            pal.setColor(QPalette::Window, QRgb(0x40434a));
            pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
        } else if (theme == QChart::ChartThemeBrownSand) {
            pal.setColor(QPalette::Window, QRgb(0x9e8965));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeBlueNcs) {
            pal.setColor(QPalette::Window, QRgb(0x018bba));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else if (theme == QChart::ChartThemeHighContrast) {
            pal.setColor(QPalette::Window, QRgb(0xffab03));
            pal.setColor(QPalette::WindowText, QRgb(0x181818));
        } else if (theme == QChart::ChartThemeBlueIcy) {
            pal.setColor(QPalette::Window, QRgb(0xcee7f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        } else {
            pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));
        }
        window()->setPalette(pal);
    }

    QChart::AnimationOptions options(
                m_ui->animatedComboBox->itemData(m_ui->animatedComboBox->currentIndex()).toInt());
    if (!m_charts.isEmpty() && m_charts.at(0)->chart()->animationOptions() != options) {
        for (QChartView *chartView : charts)
            chartView->chart()->setAnimationOptions(options);
    }
}

