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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *editTotal;
    QLabel *label_3;
    QLineEdit *editNum;
    QLineEdit *editPrice;
    QPushButton *btnDebug;
    QPushButton *btnCal;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *editDec;
    QPushButton *btnDec;
    QLabel *label_7;
    QLineEdit *editBin;
    QPushButton *btnBin;
    QLabel *label_8;
    QLineEdit *editHex;
    QPushButton *btnHex;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(337, 237);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        editTotal = new QLineEdit(groupBox_2);
        editTotal->setObjectName(QString::fromUtf8("editTotal"));

        gridLayout_2->addWidget(editTotal, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        editNum = new QLineEdit(groupBox_2);
        editNum->setObjectName(QString::fromUtf8("editNum"));

        gridLayout_2->addWidget(editNum, 0, 1, 1, 1);

        editPrice = new QLineEdit(groupBox_2);
        editPrice->setObjectName(QString::fromUtf8("editPrice"));

        gridLayout_2->addWidget(editPrice, 0, 3, 1, 1);

        btnDebug = new QPushButton(groupBox_2);
        btnDebug->setObjectName(QString::fromUtf8("btnDebug"));

        gridLayout_2->addWidget(btnDebug, 2, 1, 1, 1);

        btnCal = new QPushButton(groupBox_2);
        btnCal->setObjectName(QString::fromUtf8("btnCal"));

        gridLayout_2->addWidget(btnCal, 2, 3, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        editDec = new QLineEdit(groupBox);
        editDec->setObjectName(QString::fromUtf8("editDec"));

        gridLayout->addWidget(editDec, 0, 1, 1, 1);

        btnDec = new QPushButton(groupBox);
        btnDec->setObjectName(QString::fromUtf8("btnDec"));

        gridLayout->addWidget(btnDec, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        editBin = new QLineEdit(groupBox);
        editBin->setObjectName(QString::fromUtf8("editBin"));

        gridLayout->addWidget(editBin, 1, 1, 1, 1);

        btnBin = new QPushButton(groupBox);
        btnBin->setObjectName(QString::fromUtf8("btnBin"));

        gridLayout->addWidget(btnBin, 1, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        editHex = new QLineEdit(groupBox);
        editHex->setObjectName(QString::fromUtf8("editHex"));

        gridLayout->addWidget(editHex, 2, 1, 1, 1);

        btnHex = new QPushButton(groupBox);
        btnHex->setObjectName(QString::fromUtf8("btnHex"));

        gridLayout->addWidget(btnHex, 2, 2, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\255\227\347\254\246\344\270\262\344\270\216\346\225\260\345\200\274\344\271\213\351\227\264\347\232\204\350\275\254\346\215\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\225\260\345\200\274\350\276\223\345\205\245\345\222\214\350\276\223\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\225\260 \351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\225 \344\273\267", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\273 \344\273\267", nullptr));
        editNum->setText(QCoreApplication::translate("Widget", "12", nullptr));
        editPrice->setText(QCoreApplication::translate("Widget", "5.32", nullptr));
        btnDebug->setText(QCoreApplication::translate("Widget", "qDebug()\346\265\213\350\257\225", nullptr));
        btnCal->setText(QCoreApplication::translate("Widget", "\350\256\241\347\256\227\346\200\273\344\273\267", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\350\277\233\345\210\266\350\275\254\346\215\242", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\215\201 \350\277\233 \345\210\266", nullptr));
        editDec->setText(QCoreApplication::translate("Widget", "231", nullptr));
        btnDec->setText(QCoreApplication::translate("Widget", "DEC -->\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\344\272\214 \350\277\233 \345\210\266", nullptr));
        btnBin->setText(QCoreApplication::translate("Widget", "BIN -->\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        btnHex->setText(QCoreApplication::translate("Widget", "HEX -->\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
