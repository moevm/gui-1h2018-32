#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
    class signUp;
}

class signUp : public QDialog
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = 0);
    ~signUp();

private:
    Ui::signUp *ui;
    void accept();
};

#endif // SIGNUP_H
