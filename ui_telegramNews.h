/********************************************************************************
** Form generated from reading UI file 'themewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEWIDGET_H
#define UI_THEMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeWidgetForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QLabel *animatedLabel;
    QComboBox *animatedComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *ThemeWidgetForm)
    {
        if (ThemeWidgetForm->objectName().isEmpty())
            ThemeWidgetForm->setObjectName(QStringLiteral("ThemeWidgetForm"));
        ThemeWidgetForm->resize(900, 600);
        gridLayout = new QGridLayout(ThemeWidgetForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        themeLabel = new QLabel(ThemeWidgetForm);
        themeLabel->setObjectName(QStringLiteral("themeLabel"));

        horizontalLayout->addWidget(themeLabel);

        themeComboBox = new QComboBox(ThemeWidgetForm);
        themeComboBox->setObjectName(QStringLiteral("themeComboBox"));

        horizontalLayout->addWidget(themeComboBox);

        animatedLabel = new QLabel(ThemeWidgetForm);
        animatedLabel->setObjectName(QStringLiteral("animatedLabel"));

        horizontalLayout->addWidget(animatedLabel);

        animatedComboBox = new QComboBox(ThemeWidgetForm);
        animatedComboBox->setObjectName(QStringLiteral("animatedComboBox"));

        horizontalLayout->addWidget(animatedComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ThemeWidgetForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);


        retranslateUi(ThemeWidgetForm);
        QObject::connect(animatedComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));
        QObject::connect(themeComboBox, SIGNAL(currentIndexChanged(int)), ThemeWidgetForm, SLOT(updateUI()));

        QMetaObject::connectSlotsByName(ThemeWidgetForm);
    } // setupUi

    void retranslateUi(QWidget *ThemeWidgetForm)
    {
        themeLabel->setText(QApplication::translate("ThemeWidgetForm", "\320\241\321\202\320\270\320\273\321\214:", nullptr));
        animatedLabel->setText(QApplication::translate("ThemeWidgetForm", "\320\242\320\265\320\274\320\260 \321\201\321\202\320\260\321\202\320\265\320\271:", nullptr));
        pushButton->setText(QApplication::translate("ThemeWidgetForm", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        Q_UNUSED(ThemeWidgetForm);
    } // retranslateUi

};

namespace Ui {
    class ThemeWidgetForm: public Ui_ThemeWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEWIDGET_H
