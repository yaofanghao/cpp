/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <tbattery.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    TBattery *battery;
    QSlider *horizontalSlider;
    QLabel *labInfo;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(252, 160);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        battery = new TBattery(Widget);
        battery->setObjectName(QString::fromUtf8("battery"));

        verticalLayout->addWidget(battery);

        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(60);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        labInfo = new QLabel(Widget);
        labInfo->setObjectName(QString::fromUtf8("labInfo"));
        labInfo->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(labInfo);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\207\252\345\256\232\344\271\211\347\225\214\351\235\242\347\273\204\344\273\266", nullptr));
        labInfo->setText(QCoreApplication::translate("Widget", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\23260 %", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
