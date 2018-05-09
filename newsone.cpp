#include "newsone.h"
#include "ui_newsone.h"
#include "QDebug"
#include "QtSql"
#include "mainPage.h"
#include <QDateTime>

newsOne::newsOne(QString id, QWidget *parent) :
    QDialog(parent),
    idForNew(id),
    ui(new Ui::newsOne)

{
    ui->setupUi(this);

    if (ThemeWidget::userIn == "") {
        ui->textBrowser->setVisible(false);
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
    else {
        ui->textBrowser->setVisible(true);
        ui->lineEdit->setEnabled(true);
        ui->pushButton->setEnabled(true);
    }
    connect(ui->pushButton, SIGNAL (released()), this, SLOT (handleButton()));
    getComments();
}

void newsOne::priem(QString str, QString newsId)
{
    ui->textEdit->setText(str);
    this->idNews = newsId;
}

void newsOne::handleButton()
{
    QString comment = ui->lineEdit->text();
    QString s = this->idForNew;
    QSqlQuery a_query;
    QString str_insert = "INSERT INTO comments(newsId, userId, date, comment) "
                "VALUES ('%1', '%2', '%3', '%4');";
    QString str = str_insert.arg(s)
                            .arg(ThemeWidget::userIn)
                            .arg(QDateTime::currentDateTime().toString())
                            .arg(comment);
    bool b = a_query.exec(str);
    if (!b) {
        qDebug() << "Cannot insert data!";
    }
    else {
        getComments();
        ui->lineEdit->setText("");
    }
}

void newsOne::getComments()
{
    QString str1 = this->idForNew;
    QSqlQuery query1("SELECT userId, date, comment FROM comments WHERE newsId='" + str1 + "';");
    QString comment = "";
    while (query1.next()) {
        comment += query1.value(0).toString();
        comment += " " + query1.value(1).toString();
        comment += " " + query1.value(2).toString() + "\n";
    }
    if (comment != "") {
        ui->textBrowser->setText(comment);
    }
}

newsOne::~newsOne()
{
    delete ui;
}
