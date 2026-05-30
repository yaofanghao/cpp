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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labPic;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(392, 387);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        Widget->setFont(font);
        Widget->setAcceptDrops(true);
        labPic = new QLabel(Widget);
        labPic->setObjectName(QString::fromUtf8("labPic"));
        labPic->setGeometry(QRect(5, 155, 376, 226));
        labPic->setScaledContents(true);
        labPic->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(5, 5, 381, 140));
        plainTextEdit->setMinimumSize(QSize(0, 140));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\244\226\351\203\250\346\226\207\344\273\266\346\213\226\346\224\276", nullptr));
        labPic->setText(QCoreApplication::translate("Widget", "Pic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
