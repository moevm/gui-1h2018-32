/********************************************************************************
** Form generated from reading UI file 'signUp.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_signUp
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *sign)
    {
        if (sign->objectName().isEmpty())
            sign->setObjectName(QStringLiteral("sign"));
        sign->resize(400, 93);
        buttonBox = new QDialogButtonBox(sign);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(sign);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 20, 201, 20));
        lineEdit_2 = new QLineEdit(sign);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 50, 201, 20));
        label = new QLabel(sign);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 21, 16));
        label_2 = new QLabel(sign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 61, 16));

        retranslateUi(sign);
        QObject::connect(buttonBox, SIGNAL(accepted()), sign, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), sign, SLOT(reject()));

        QMetaObject::connectSlotsByName(sign);
    } // setupUi

    void retranslateUi(QDialog *sign)
    {
        sign->setWindowTitle(QApplication::translate("signUp", "Dialog", nullptr));
        label->setText(QApplication::translate("signUp", "login", nullptr));
        label_2->setText(QApplication::translate("signUp", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signUp: public Ui_signUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
