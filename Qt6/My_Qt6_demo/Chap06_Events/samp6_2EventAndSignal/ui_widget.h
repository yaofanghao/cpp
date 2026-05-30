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
#include <QtWidgets/QWidget>
#include <tmylabel.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    TMyLabel *lab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(332, 120);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        lab = new TMyLabel(Widget);
        lab->setObjectName(QString::fromUtf8("lab"));
        lab->setGeometry(QRect(10, 40, 221, 19));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(14);
        font1.setBold(true);
        lab->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\272\213\344\273\266\344\270\216\344\277\241\345\217\267", nullptr));
        lab->setText(QCoreApplication::translate("Widget", "\345\217\214\345\207\273\346\210\221\345\225\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
