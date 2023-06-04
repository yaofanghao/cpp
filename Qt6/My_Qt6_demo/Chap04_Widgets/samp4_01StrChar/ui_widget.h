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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnCharJudge;
    QLabel *label_2;
    QLineEdit *editStr;
    QLabel *label;
    QLineEdit *editChar;
    QPushButton *btnGetChars;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QPushButton *btnConvLatin1;
    QPushButton *btnConvUTF16;
    QPushButton *btnCompare;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chkDigit;
    QCheckBox *chkLetter;
    QCheckBox *chkLetterOrNumber;
    QCheckBox *chkUpper;
    QCheckBox *chkLower;
    QCheckBox *chkMark;
    QCheckBox *chkSpace;
    QCheckBox *chkSymbol;
    QCheckBox *chkPunct;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(459, 465);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnCharJudge = new QPushButton(groupBox);
        btnCharJudge->setObjectName(QString::fromUtf8("btnCharJudge"));

        gridLayout->addWidget(btnCharJudge, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editStr = new QLineEdit(groupBox);
        editStr->setObjectName(QString::fromUtf8("editStr"));

        gridLayout->addWidget(editStr, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editChar = new QLineEdit(groupBox);
        editChar->setObjectName(QString::fromUtf8("editChar"));

        gridLayout->addWidget(editChar, 1, 1, 1, 1);

        btnGetChars = new QPushButton(groupBox);
        btnGetChars->setObjectName(QString::fromUtf8("btnGetChars"));

        gridLayout->addWidget(btnGetChars, 0, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnConvLatin1 = new QPushButton(groupBox_3);
        btnConvLatin1->setObjectName(QString::fromUtf8("btnConvLatin1"));

        gridLayout_2->addWidget(btnConvLatin1, 0, 0, 1, 1);

        btnConvUTF16 = new QPushButton(groupBox_3);
        btnConvUTF16->setObjectName(QString::fromUtf8("btnConvUTF16"));

        gridLayout_2->addWidget(btnConvUTF16, 0, 1, 1, 1);

        btnCompare = new QPushButton(groupBox_3);
        btnCompare->setObjectName(QString::fromUtf8("btnCompare"));

        gridLayout_2->addWidget(btnCompare, 1, 0, 1, 1);

        btnClear = new QPushButton(groupBox_3);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        gridLayout_2->addWidget(btnClear, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chkDigit = new QCheckBox(groupBox_4);
        chkDigit->setObjectName(QString::fromUtf8("chkDigit"));

        verticalLayout_2->addWidget(chkDigit);

        chkLetter = new QCheckBox(groupBox_4);
        chkLetter->setObjectName(QString::fromUtf8("chkLetter"));

        verticalLayout_2->addWidget(chkLetter);

        chkLetterOrNumber = new QCheckBox(groupBox_4);
        chkLetterOrNumber->setObjectName(QString::fromUtf8("chkLetterOrNumber"));

        verticalLayout_2->addWidget(chkLetterOrNumber);

        chkUpper = new QCheckBox(groupBox_4);
        chkUpper->setObjectName(QString::fromUtf8("chkUpper"));

        verticalLayout_2->addWidget(chkUpper);

        chkLower = new QCheckBox(groupBox_4);
        chkLower->setObjectName(QString::fromUtf8("chkLower"));

        verticalLayout_2->addWidget(chkLower);

        chkMark = new QCheckBox(groupBox_4);
        chkMark->setObjectName(QString::fromUtf8("chkMark"));

        verticalLayout_2->addWidget(chkMark);

        chkSpace = new QCheckBox(groupBox_4);
        chkSpace->setObjectName(QString::fromUtf8("chkSpace"));

        verticalLayout_2->addWidget(chkSpace);

        chkSymbol = new QCheckBox(groupBox_4);
        chkSymbol->setObjectName(QString::fromUtf8("chkSymbol"));

        verticalLayout_2->addWidget(chkSymbol);

        chkPunct = new QCheckBox(groupBox_4);
        chkPunct->setObjectName(QString::fromUtf8("chkPunct"));

        verticalLayout_2->addWidget(chkPunct);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "QChar\345\270\270\347\224\250\345\212\237\350\203\275", nullptr));
        groupBox->setTitle(QString());
        btnCharJudge->setText(QCoreApplication::translate("Widget", "\345\215\225\344\270\252\345\255\227\347\254\246\347\211\271\346\200\247\345\210\244\346\226\255", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\215\225\344\270\252\345\255\227\347\254\246", nullptr));
        editStr->setText(QCoreApplication::translate("Widget", "Hello,\351\235\222\345\262\233", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262", nullptr));
        editChar->setText(QCoreApplication::translate("Widget", "a", nullptr));
        btnGetChars->setText(QCoreApplication::translate("Widget", "\346\257\217\344\270\252\345\255\227\347\254\246\347\232\204Unicode", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\345\205\266\344\273\226\346\265\213\350\257\225\345\222\214\345\212\237\350\203\275", nullptr));
        btnConvLatin1->setText(QCoreApplication::translate("Widget", "\344\270\216Latin1\347\232\204\350\275\254\346\215\242", nullptr));
        btnConvUTF16->setText(QCoreApplication::translate("Widget", "\344\270\216UTF-16\347\232\204\350\275\254\346\215\242", nullptr));
        btnCompare->setText(QCoreApplication::translate("Widget", "QChar\346\257\224\350\276\203\345\222\214\346\233\277\346\215\242", nullptr));
        btnClear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\347\273\223\346\236\234\346\230\276\347\244\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "QChar\347\211\271\346\200\247\345\210\244\346\226\255", nullptr));
        chkDigit->setText(QCoreApplication::translate("Widget", "isDigit", nullptr));
        chkLetter->setText(QCoreApplication::translate("Widget", "isLetter", nullptr));
        chkLetterOrNumber->setText(QCoreApplication::translate("Widget", "isLetterOrNumber", nullptr));
        chkUpper->setText(QCoreApplication::translate("Widget", "isUpper", nullptr));
        chkLower->setText(QCoreApplication::translate("Widget", "isLower", nullptr));
        chkMark->setText(QCoreApplication::translate("Widget", "isMark", nullptr));
        chkSpace->setText(QCoreApplication::translate("Widget", "isSpace", nullptr));
        chkSymbol->setText(QCoreApplication::translate("Widget", "isSymbol", nullptr));
        chkPunct->setText(QCoreApplication::translate("Widget", "isPunct", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
