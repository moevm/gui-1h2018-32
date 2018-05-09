#include "mainPage.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("TelegramNews.sqlite");

    if (!db.open()){
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Success!";
    }
    QSqlQuery a_query;
    QString str = "CREATE TABLE users ("
                "login VARCHAR(255) PRIMARY KEY NOT NULL, "
                "password VARCHAR(255) NOT NULL"
                ");";
    bool b = a_query.exec(str);
    if (!b) {
        qDebug() << "Cannot create table!";
    }
    QSqlQuery b_query;
    QString stri = "CREATE TABLE comments ("
                 "newsId VARCHAR(255) NOT NULL, "
                 "userId VARCHAR(255) NOT NULL, "
                 "date DATETIME NOT NULL, "
                 "comment VARCHAR(255) NOT NULL"
                 ");";
    bool c = b_query.exec(stri);
    if (!c) {
       qDebug() << "Cannot create table!";
    }


    QMainWindow window;
    ThemeWidget *widget = new ThemeWidget();
    window.setCentralWidget(widget);
    window.resize(900, 600);
    window.show();
    return a.exec();
}

