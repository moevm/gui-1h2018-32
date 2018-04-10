#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainPage.h"

namespace Ui {
    class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    void setTheme(ThemeWidget *wid);
    ~login();

private:
    ThemeWidget *temp;
    Ui::login *ui;
    void accept();
};

#endif // LOGIN_H
