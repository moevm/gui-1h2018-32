#ifndef NEWSONE_H
#define NEWSONE_H

#include <QStringList>
#include <QDialog>


namespace Ui {
    class newsOne;
}

class newsOne : public QDialog
{
    Q_OBJECT
public:
    QString idNews;

    explicit newsOne(QString ID, QWidget *parent = 0);
    ~newsOne();
public slots:
    void priem(QString, QString);
private:
    QString idForNew;
    Ui::newsOne *ui;
    void getComments();

private slots:
    void handleButton();
};

#endif // NEWSONE_H
