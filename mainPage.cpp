#include "mainPage.h"
#include "ui_telegramNews.h"
#include "newsone.h"
#include "login.h"
#include "signUp.h"
#include <QtCharts/QChartView>
#include <QMessageBox>

QString ThemeWidget::userIn = "";
int ThemeWidget::newsId = 0;

void ThemeWidget::parseXML(){
    QFile* file = new QFile("lenta.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,   "ThemeWidget::parseXML",
                                      "Couldn't open lenta.xml",
                                      QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xml(file);
    QList<QMap<QString,QString> > items;
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if(xml.name() == "items") {
                           continue;
                       }
            if (xml.name() == "item")
                items.append(ThemeWidget::parseItem(xml));
        }
    }
    if(xml.hasError())
    {
        QMessageBox::critical(this,
                              "ThemeWidget::parseXML",
                              xml.errorString(),
                              QMessageBox::Ok);
    }
    int y = 0, i = 0;

    if (m_ui->animatedComboBox->currentIndex() == 0){
        while (!items.isEmpty()){
            QMap<QString,QString> item = items.takeFirst();
            if (item["category"] == "Путешествия"){
                QChartView *chartView;
                chartView = new QChartView(createAreaChart(item));
                m_ui->gridLayout->addWidget(chartView, i+1, y);
                m_button1 = new QPushButton("Читать полностью", this);
                m_ui->gridLayout->addWidget(m_button1, i+2, y);
                QString id = item["newsId"];
                myform = new newsOne(id);
                QString desc = item["description"];

                connect(this, SIGNAL(otpravka(QString, QString)), myform, SLOT(priem(QString, QString)));
                emit otpravka(desc, id);
                connect(m_button1, SIGNAL(clicked()), myform, SLOT(show()));
                m_charts << chartView;
                y = y+1;
                if (y % 3 == 0){
                    y = 0;
                    i = i+2;
                }
            }
        }
    }

    if (m_ui->animatedComboBox->currentIndex() == 1){
        while (!items.isEmpty()){
            QMap<QString,QString> item = items.takeFirst();
            if (item["category"] == "Культура"){
                QChartView *chartView;
                chartView = new QChartView(createAreaChart(item));
                m_ui->gridLayout->addWidget(chartView, i+1, y);
                m_button1 = new QPushButton("Читать полностью", this);
                m_ui->gridLayout->addWidget(m_button1, i+2, y);
                QString id = item["newsId"];
                myform = new newsOne(id);
                QString desc = item["description"];
                connect(this, SIGNAL(otpravka(QString, QString)), myform, SLOT(priem(QString, QString)));
                emit otpravka(desc, id);
                connect(m_button1, SIGNAL(clicked()), myform, SLOT(show()));
                m_charts << chartView;
                y = y+1;
                if (y % 3 == 0){
                    y = 0;
                    i = i+2;
                }
            }
        }
    }

    if (m_ui->animatedComboBox->currentIndex() == 2){
        while (!items.isEmpty()){
            QMap<QString,QString> item = items.takeFirst();
            if (item["category"] == "Криптовалюта"){
                QChartView *chartView;
                chartView = new QChartView(createAreaChart(item));
                m_ui->gridLayout->addWidget(chartView, i+1, y);
                m_button1 = new QPushButton("Читать полностью", this);
                m_ui->gridLayout->addWidget(m_button1, i+2, y);
                QString id = item["newsId"];
                myform = new newsOne(id);
                QString desc = item["description"];
                connect(this, SIGNAL(otpravka(QString, QString)), myform, SLOT(priem(QString, QString)));
                emit otpravka(desc, id);
                connect(m_button1, SIGNAL(clicked()), myform, SLOT(show()));
                m_charts << chartView;
                y = y+1;
                if (y % 3 == 0){
                    y = 0;
                    i = i+2;
                }
            }
        }
    }

    if (m_ui->animatedComboBox->currentIndex() == 3){
        while (!items.isEmpty()){
            QMap<QString,QString> item = items.takeFirst();
            if (item["category"] == "Мир"){
                QChartView *chartView;
                chartView = new QChartView(createAreaChart(item));
                m_ui->gridLayout->addWidget(chartView, i+1, y);
                m_button1 = new QPushButton("Читать полностью", this);
                m_ui->gridLayout->addWidget(m_button1, i+2, y);
                QString id = item["newsId"];
                myform = new newsOne(id);
                QString desc = item["description"];

                connect(this, SIGNAL(otpravka(QString, QString)), myform, SLOT(priem(QString, QString)));
                emit otpravka(desc, id);
                connect(m_button1, SIGNAL(clicked()), myform, SLOT(show()));
                m_charts << chartView;
                y = y+1;
                if (y % 3 == 0){
                    y = 0;
                    i = i+2;
                }
            }
        }
    }
    xml.clear();
}

QMap<QString, QString> ThemeWidget::parseItem(QXmlStreamReader& xml) {
    QMap<QString, QString> itemNews;
    if (xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "item")
        return itemNews;

    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("id"))
        itemNews["id"] = attributes.value("id").toString();
    xml.readNext();
    while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "item"))
    {
        if (xml.tokenType() == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "title")
                addElementDataToMap(xml, itemNews);
            if (xml.name() == "link")
                addElementDataToMap(xml, itemNews);
            if (xml.name() == "description")
                addElementDataToMap(xml, itemNews);
            if (xml.name() == "category"){
                addElementDataToMap(xml, itemNews);
                newsId += 1;
                QString id = QString::number(newsId);
                itemNews.insert("newsId", id);
  }
        }
        xml.readNext();
    }
    return itemNews;
}

void ThemeWidget::addElementDataToMap(QXmlStreamReader& xml, QMap<QString, QString>& map) const
{
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return;
    QString elementName = xml.name().toString();
    xml.readNext();
    if(xml.tokenType() != QXmlStreamReader::Characters) {
            return;
        }
    map.insert(elementName, xml.text().toString());
}

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


    m_ui->pushButton_3->setVisible(false);
    m_ui->label->setVisible(false);

    connect(m_ui->pushButton, SIGNAL (released()), this, SLOT (handleButtonLogin()));
    connect(m_ui->pushButton_2, SIGNAL (released()), this, SLOT (handleButtonSignUp()));
    connect(m_ui->pushButton_3, SIGNAL (released()), this, SLOT (handleButtonExit()));


    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    qApp->setPalette(pal);

    updateUI();
}

void ThemeWidget::handleButton(QMap<QString,QString> item)
{
    emit sendData(item["description"]);
}

void ThemeWidget::handleButtonLogin()
{
    login *log = new login();
    log->setTheme(this);
    log->show();
}

void ThemeWidget::change() {
    m_ui->pushButton->setVisible(false);
    m_ui->pushButton_2->setVisible(false);
    m_ui->label->setText(userIn);
    m_ui->label->setVisible(true);
    m_ui->pushButton_3->setVisible(true);
}

void ThemeWidget::handleButtonExit()
{
    userIn = "";
    m_ui->label->setVisible(false);
    m_ui->label->setText(userIn);
    m_ui->pushButton_3->setVisible(false);
    m_ui->pushButton->setVisible(true);
    m_ui->pushButton_2->setVisible(true);
}

void ThemeWidget::handleButtonSignUp()
{
    signUp *sign = new signUp;
    sign->show();
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

void ThemeWidget::selectTheme(QString newTheme)
{
    themeNew = newTheme;
}

void ThemeWidget::populateAnimationBox()
{
    m_ui->animatedComboBox->addItem("Путешествия", QChart::NoAnimation);
    m_ui->animatedComboBox->addItem("Культура", QChart::GridAxisAnimations);
    m_ui->animatedComboBox->addItem("Криптовалюта", QChart::SeriesAnimations);
    m_ui->animatedComboBox->addItem("Мир", QChart::AllAnimations);
}

QChart *ThemeWidget::createAreaChart(QMap<QString,QString> item) const
{
    QChart *chart = new QChart();
    //QMap<QString,QString> item = items.takeFirst();
    chart->setTitle(item["title"]);

    return chart;
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

    parseXML();
    newsId = 0;

    QChart::AnimationOptions options(
                m_ui->animatedComboBox->itemData(m_ui->animatedComboBox->currentIndex()).toInt());
    if (!m_charts.isEmpty() && m_charts.at(0)->chart()->animationOptions() != options) {

        for (QChartView *chartView : charts)
            chartView->chart()->setAnimationOptions(options);
    }
}




