#ifndef NEWSONE_H
#define NEWSONE_H

#include <QDialog>

namespace Ui {
    class newsOne;
}

class newsOne : public QDialog
{
    Q_OBJECT

public:
    explicit newsOne(QWidget *parent = 0);
    ~newsOne();

private:
    Ui::newsOne *ui;
};

#endif // NEWSONE_H
