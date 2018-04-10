#include "signUp.h"
#include "ui_signUp.h"
#include "QDebug"
#include "QtSql"
#include <QMessageBox>

signUp::signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::accept() {
    QString str1 = ui->lineEdit->text();
    if (str1 == "") {
        QMessageBox loginError;
        loginError.setText("The login is empty!");
        loginError.exec();
    }
    else {
        QString str2 = ui->lineEdit_2->text();
        if (str2 == "") {
            QMessageBox passwordError;
            passwordError.setText("The password is empty!");
            passwordError.exec();
        }
        else {
            QSqlQuery a_query;
            QString str_insert = "INSERT INTO users(login, password) "
                        "VALUES ('%1', '%2');";
            QString str = str_insert.arg(str1)
                                    .arg(str2);
            bool b = a_query.exec(str);
            if (!b) {
                qDebug() << "Cannot insert data!";
                QMessageBox error;
                error.setText("Error!");
                error.exec();
            }
            else {
                QMessageBox success;
                success.setText("You have signed up!");
                success.exec();
                this->~signUp();
            }
        }
    }
}




