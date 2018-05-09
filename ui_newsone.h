/********************************************************************************
** Form generated from reading UI file 'newsone.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSONE_H
#define UI_NEWSONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_newsOne
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *newsOne)
    {
        if (newsOne->objectName().isEmpty())
            newsOne->setObjectName(QStringLiteral("newsOne"));
        newsOne->resize(743, 432);
        label = new QLabel(newsOne);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 210, 71, 16));
        lineEdit = new QLineEdit(newsOne);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 230, 331, 31));
        label_2 = new QLabel(newsOne);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 201, 31));
        label_3 = new QLabel(newsOne);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 40, 331, 161));
        textEdit = new QTextEdit(newsOne);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 60, 671, 141));
        pushButton = new QPushButton(newsOne);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 232, 141, 31));
        textBrowser = new QTextBrowser(newsOne);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 270, 671, 131));

        retranslateUi(newsOne);

        QMetaObject::connectSlotsByName(newsOne);
    } // setupUi

    void retranslateUi(QDialog *newsOne)
    {
        newsOne->setWindowTitle(QApplication::translate("newsOne", "Dialog", nullptr));
        label->setText(QApplication::translate("newsOne", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        label_2->setText(QApplication::translate("newsOne", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\320\227\320\260\320\263\320\276\320\262\320\276\320\272 \320\275\320\276\320\262\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
        label_3->setText(QString());
        pushButton->setText(QApplication::translate("newsOne", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newsOne: public Ui_newsOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSONE_H
