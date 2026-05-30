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
#include <QtWidgets/QPlainTextEdit>
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
    QLabel *labBoy;
    QSpinBox *spinBoy;
    QPushButton *btnBoyInc;
    QPushButton *btnClassInfo;
    QLabel *labGirl;
    QSpinBox *spinGirl;
    QPushButton *btnGirlInc;
    QPushButton *btnClear;
    QPlainTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(412, 283);
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
        labBoy = new QLabel(groupBox);
        labBoy->setObjectName(QString::fromUtf8("labBoy"));

        gridLayout->addWidget(labBoy, 0, 0, 1, 1);

        spinBoy = new QSpinBox(groupBox);
        spinBoy->setObjectName(QString::fromUtf8("spinBoy"));
        spinBoy->setMinimum(0);
        spinBoy->setMaximum(200);
        spinBoy->setValue(10);

        gridLayout->addWidget(spinBoy, 0, 1, 1, 1);

        btnBoyInc = new QPushButton(groupBox);
        btnBoyInc->setObjectName(QString::fromUtf8("btnBoyInc"));

        gridLayout->addWidget(btnBoyInc, 0, 2, 1, 1);

        btnClassInfo = new QPushButton(groupBox);
        btnClassInfo->setObjectName(QString::fromUtf8("btnClassInfo"));

        gridLayout->addWidget(btnClassInfo, 0, 3, 1, 1);

        labGirl = new QLabel(groupBox);
        labGirl->setObjectName(QString::fromUtf8("labGirl"));

        gridLayout->addWidget(labGirl, 1, 0, 1, 1);

        spinGirl = new QSpinBox(groupBox);
        spinGirl->setObjectName(QString::fromUtf8("spinGirl"));
        spinGirl->setMaximum(200);
        spinGirl->setValue(20);

        gridLayout->addWidget(spinGirl, 1, 1, 1, 1);

        btnGirlInc = new QPushButton(groupBox);
        btnGirlInc->setObjectName(QString::fromUtf8("btnGirlInc"));

        gridLayout->addWidget(btnGirlInc, 1, 2, 1, 1);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        gridLayout->addWidget(btnClear, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        textEdit = new QPlainTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\205\203\345\257\271\350\261\241\347\263\273\347\273\237\347\211\271\346\200\247", nullptr));
        groupBox->setTitle(QString());
        labBoy->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\347\224\267\347\224\237\345\271\264\351\276\204", nullptr));
        btnBoyInc->setText(QCoreApplication::translate("Widget", "boy\351\225\277\345\244\247\344\270\200\345\262\201", nullptr));
        btnClassInfo->setText(QCoreApplication::translate("Widget", "\345\205\203\345\257\271\350\261\241\344\277\241\346\201\257", nullptr));
        labGirl->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\345\245\263\347\224\237\345\271\264\351\276\204", nullptr));
        btnGirlInc->setText(QCoreApplication::translate("Widget", "girl\351\225\277\345\244\247\344\270\200\345\262\201", nullptr));
        btnClear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
