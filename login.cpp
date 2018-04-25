#include "login.h"
#include "ui_login.h"
#include "QDebug"
#include "QtSql"
#include "mainPage.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::setTheme(ThemeWidget *wid) {
    temp = wid;
}

void login::accept() {
    QString str1 = ui->lineEdit->text();
    QSqlQuery query1("SELECT login FROM users;");
    bool exist = 0;
    while (query1.next() && !exist) {
        QString log = query1.value(0).toString();
        if (log == str1) {
            exist = 1;
            break;
        }
    }
    if (exist) {
        qDebug() << "LOGIN OK";
        QString str2 = ui->lineEdit_2->text();
        QSqlQuery query2("SELECT password FROM users WHERE login='" + str1 + "';");
        query2.first();
        if (query2.value(0).toString() == str2) {
            qDebug() << "PASSWORD OK";
            QMessageBox success;
            success.setText("You have logged in!");
            success.exec();
            ThemeWidget::userIn = str1;
            this->~login();
            temp->change();
        }
        else {
            QMessageBox passwordError;
            passwordError.setText("This password doesn`t match!");
            passwordError.exec();
        }
    }
    else {
        QMessageBox loginError;
        loginError.setText("This login doesn`t exist!");
        loginError.exec();
    }
}



