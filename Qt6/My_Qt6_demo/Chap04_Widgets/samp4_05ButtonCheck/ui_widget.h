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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAlign_Left;
    QPushButton *btnAlign_Center;
    QPushButton *btnAlign_Right;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnFont_Bold;
    QPushButton *btnFont_Italic;
    QPushButton *btnFont_UnderLine;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkBox_Readonly;
    QCheckBox *chkbox_Enable;
    QCheckBox *chkBox_ClearButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;
    QLineEdit *editInput;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(361, 229);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAlign_Left = new QPushButton(Widget);
        btnAlign_Left->setObjectName(QString::fromUtf8("btnAlign_Left"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/508.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnAlign_Left->setIcon(icon);
        btnAlign_Left->setCheckable(true);
        btnAlign_Left->setChecked(true);
        btnAlign_Left->setAutoExclusive(true);
        btnAlign_Left->setFlat(true);

        horizontalLayout->addWidget(btnAlign_Left);

        btnAlign_Center = new QPushButton(Widget);
        btnAlign_Center->setObjectName(QString::fromUtf8("btnAlign_Center"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/510.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnAlign_Center->setIcon(icon1);
        btnAlign_Center->setCheckable(true);
        btnAlign_Center->setChecked(false);
        btnAlign_Center->setAutoExclusive(true);
        btnAlign_Center->setFlat(true);

        horizontalLayout->addWidget(btnAlign_Center);

        btnAlign_Right = new QPushButton(Widget);
        btnAlign_Right->setObjectName(QString::fromUtf8("btnAlign_Right"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/512.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnAlign_Right->setIcon(icon2);
        btnAlign_Right->setCheckable(true);
        btnAlign_Right->setChecked(false);
        btnAlign_Right->setAutoExclusive(true);
        btnAlign_Right->setFlat(true);

        horizontalLayout->addWidget(btnAlign_Right);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnFont_Bold = new QPushButton(Widget);
        btnFont_Bold->setObjectName(QString::fromUtf8("btnFont_Bold"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/500.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnFont_Bold->setIcon(icon3);
        btnFont_Bold->setCheckable(true);

        horizontalLayout_2->addWidget(btnFont_Bold);

        btnFont_Italic = new QPushButton(Widget);
        btnFont_Italic->setObjectName(QString::fromUtf8("btnFont_Italic"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/502.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnFont_Italic->setIcon(icon4);
        btnFont_Italic->setCheckable(true);

        horizontalLayout_2->addWidget(btnFont_Italic);

        btnFont_UnderLine = new QPushButton(Widget);
        btnFont_UnderLine->setObjectName(QString::fromUtf8("btnFont_UnderLine"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/images/504.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnFont_UnderLine->setIcon(icon5);
        btnFont_UnderLine->setCheckable(true);

        horizontalLayout_2->addWidget(btnFont_UnderLine);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        groupBox_2->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 5, -1, 5);
        chkBox_Readonly = new QCheckBox(groupBox_2);
        chkBox_Readonly->setObjectName(QString::fromUtf8("chkBox_Readonly"));

        horizontalLayout_3->addWidget(chkBox_Readonly);

        chkbox_Enable = new QCheckBox(groupBox_2);
        chkbox_Enable->setObjectName(QString::fromUtf8("chkbox_Enable"));
        chkbox_Enable->setChecked(true);

        horizontalLayout_3->addWidget(chkbox_Enable);

        chkBox_ClearButton = new QCheckBox(groupBox_2);
        chkBox_ClearButton->setObjectName(QString::fromUtf8("chkBox_ClearButton"));

        horizontalLayout_3->addWidget(chkBox_ClearButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioBlack = new QRadioButton(groupBox);
        radioBlack->setObjectName(QString::fromUtf8("radioBlack"));
        radioBlack->setChecked(true);

        horizontalLayout_4->addWidget(radioBlack);

        radioRed = new QRadioButton(groupBox);
        radioRed->setObjectName(QString::fromUtf8("radioRed"));

        horizontalLayout_4->addWidget(radioRed);

        radioBlue = new QRadioButton(groupBox);
        radioBlue->setObjectName(QString::fromUtf8("radioBlue"));

        horizontalLayout_4->addWidget(radioBlue);


        verticalLayout->addWidget(groupBox);

        editInput = new QLineEdit(Widget);
        editInput->setObjectName(QString::fromUtf8("editInput"));
        editInput->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(14);
        editInput->setFont(font1);

        verticalLayout->addWidget(editInput);

        verticalLayout->setStretch(5, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\214\211\351\222\256\347\232\204\344\275\277\347\224\250", nullptr));
        btnAlign_Left->setText(QCoreApplication::translate("Widget", "\345\261\205\345\267\246", nullptr));
        btnAlign_Center->setText(QCoreApplication::translate("Widget", "\345\261\205\344\270\255", nullptr));
        btnAlign_Right->setText(QCoreApplication::translate("Widget", "\345\261\205\345\217\263", nullptr));
        btnFont_Bold->setText(QCoreApplication::translate("Widget", "\347\262\227\344\275\223", nullptr));
        btnFont_Italic->setText(QCoreApplication::translate("Widget", "\346\226\234\344\275\223", nullptr));
        btnFont_UnderLine->setText(QCoreApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
        groupBox_2->setTitle(QString());
        chkBox_Readonly->setText(QCoreApplication::translate("Widget", "Readonly", nullptr));
        chkbox_Enable->setText(QCoreApplication::translate("Widget", "Enabled", nullptr));
        chkBox_ClearButton->setText(QCoreApplication::translate("Widget", "ClearButtonEnabled", nullptr));
        groupBox->setTitle(QString());
        radioBlack->setText(QCoreApplication::translate("Widget", "Black", nullptr));
        radioRed->setText(QCoreApplication::translate("Widget", "Red", nullptr));
        radioBlue->setText(QCoreApplication::translate("Widget", "Blue", nullptr));
        editInput->setText(QCoreApplication::translate("Widget", "\346\265\213\350\257\225\346\230\276\347\244\272\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
