#include "newsone.h"
#include "ui_newsone.h"

newsOne::newsOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newsOne)
{
    ui->setupUi(this);
}

newsOne::~newsOne()
{
    delete ui;
}
