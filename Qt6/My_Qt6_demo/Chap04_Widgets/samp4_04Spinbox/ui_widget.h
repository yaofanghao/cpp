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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinNum;
    QLabel *label_2;
    QDoubleSpinBox *spinPrice;
    QPushButton *btnCal;
    QLabel *label_3;
    QDoubleSpinBox *spinTotal;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_6;
    QSpinBox *spinBin;
    QSpinBox *spinHex;
    QSpinBox *spinDec;
    QLabel *label_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(299, 211);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinNum = new QSpinBox(groupBox);
        spinNum->setObjectName(QString::fromUtf8("spinNum"));
        spinNum->setFrame(true);
        spinNum->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinNum->setProperty("showGroupSeparator", QVariant(false));
        spinNum->setMaximum(1000);
        spinNum->setValue(4);

        gridLayout->addWidget(spinNum, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        spinPrice = new QDoubleSpinBox(groupBox);
        spinPrice->setObjectName(QString::fromUtf8("spinPrice"));
        spinPrice->setMinimumSize(QSize(90, 0));
        spinPrice->setMaximum(10000.000000000000000);
        spinPrice->setValue(12.430000000000000);

        gridLayout->addWidget(spinPrice, 0, 3, 1, 1);

        btnCal = new QPushButton(groupBox);
        btnCal->setObjectName(QString::fromUtf8("btnCal"));

        gridLayout->addWidget(btnCal, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        spinTotal = new QDoubleSpinBox(groupBox);
        spinTotal->setObjectName(QString::fromUtf8("spinTotal"));
        spinTotal->setMaximum(100000.000000000000000);

        gridLayout->addWidget(spinTotal, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        spinBin = new QSpinBox(groupBox_2);
        spinBin->setObjectName(QString::fromUtf8("spinBin"));
        spinBin->setMaximum(65535);
        spinBin->setValue(12);
        spinBin->setDisplayIntegerBase(2);

        gridLayout_2->addWidget(spinBin, 1, 1, 1, 1);

        spinHex = new QSpinBox(groupBox_2);
        spinHex->setObjectName(QString::fromUtf8("spinHex"));
        spinHex->setMaximum(65535);
        spinHex->setValue(12);
        spinHex->setDisplayIntegerBase(16);

        gridLayout_2->addWidget(spinHex, 2, 1, 1, 1);

        spinDec = new QSpinBox(groupBox_2);
        spinDec->setObjectName(QString::fromUtf8("spinDec"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinDec->sizePolicy().hasHeightForWidth());
        spinDec->setSizePolicy(sizePolicy);
        spinDec->setMinimumSize(QSize(100, 0));
        spinDec->setMaximum(65535);
        spinDec->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinDec->setValue(12);

        gridLayout_2->addWidget(spinDec, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "SpinBox\346\265\213\350\257\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\225\260\345\200\274\350\276\223\345\205\245\350\276\223\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\225\260 \351\207\217", nullptr));
        spinNum->setSuffix(QCoreApplication::translate("Widget", " kg", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\225 \344\273\267", nullptr));
        spinPrice->setPrefix(QCoreApplication::translate("Widget", "$ ", nullptr));
        btnCal->setText(QCoreApplication::translate("Widget", "\350\256\241\347\256\227", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\273 \344\273\267", nullptr));
        spinTotal->setPrefix(QCoreApplication::translate("Widget", "$ ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\215\201 \350\277\233 \345\210\266", nullptr));
        spinBin->setPrefix(QCoreApplication::translate("Widget", "Bin ", nullptr));
        spinHex->setPrefix(QCoreApplication::translate("Widget", "Hex ", nullptr));
        spinDec->setSuffix(QString());
        spinDec->setPrefix(QCoreApplication::translate("Widget", "Dec ", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\344\272\214 \350\277\233 \345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
