/********************************************************************************
** Form generated from reading UI file 'wdialogdata.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDIALOGDATA_H
#define UI_WDIALOGDATA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WDialogData
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnSetPhoto;
    QPushButton *btnClearPhoto;
    QPushButton *btnOK;
    QPushButton *btnClose;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *editMemo;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinEmpNo;
    QLabel *label_2;
    QLineEdit *editName;
    QLabel *label_3;
    QComboBox *comboSex;
    QLabel *label_5;
    QDateEdit *editBirth;
    QLabel *label_7;
    QComboBox *comboProvince;
    QLabel *label_6;
    QComboBox *comboDep;
    QLabel *label_12;
    QSpinBox *spinSalary;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *LabPhoto;

    void setupUi(QDialog *WDialogData)
    {
        if (WDialogData->objectName().isEmpty())
            WDialogData->setObjectName(QString::fromUtf8("WDialogData"));
        WDialogData->resize(527, 354);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        WDialogData->setFont(font);
        layoutWidget = new QWidget(WDialogData);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 10, 82, 216));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSetPhoto = new QPushButton(layoutWidget);
        btnSetPhoto->setObjectName(QString::fromUtf8("btnSetPhoto"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/00.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetPhoto->setIcon(icon);

        verticalLayout_2->addWidget(btnSetPhoto);

        btnClearPhoto = new QPushButton(layoutWidget);
        btnClearPhoto->setObjectName(QString::fromUtf8("btnClearPhoto"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearPhoto->setIcon(icon1);

        verticalLayout_2->addWidget(btnClearPhoto);

        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon2);

        verticalLayout_2->addWidget(btnOK);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon3);

        verticalLayout_2->addWidget(btnClose);

        groupBox_3 = new QGroupBox(WDialogData);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(5, 205, 406, 151));
        groupBox_3->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, -1, 3, -1);
        editMemo = new QPlainTextEdit(groupBox_3);
        editMemo->setObjectName(QString::fromUtf8("editMemo"));
        editMemo->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(editMemo);

        widget = new QWidget(WDialogData);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(5, 5, 406, 198));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinEmpNo = new QSpinBox(groupBox_2);
        spinEmpNo->setObjectName(QString::fromUtf8("spinEmpNo"));
        spinEmpNo->setMinimum(1);
        spinEmpNo->setMaximum(10000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinEmpNo);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        editName = new QLineEdit(groupBox_2);
        editName->setObjectName(QString::fromUtf8("editName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editName);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboSex = new QComboBox(groupBox_2);
        comboSex->addItem(QString());
        comboSex->addItem(QString());
        comboSex->setObjectName(QString::fromUtf8("comboSex"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboSex);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        editBirth = new QDateEdit(groupBox_2);
        editBirth->setObjectName(QString::fromUtf8("editBirth"));
        editBirth->setCalendarPopup(true);
        editBirth->setDate(QDate(2017, 2, 20));

        formLayout->setWidget(3, QFormLayout::FieldRole, editBirth);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        comboProvince = new QComboBox(groupBox_2);
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->setObjectName(QString::fromUtf8("comboProvince"));
        comboProvince->setEditable(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboProvince);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        comboDep = new QComboBox(groupBox_2);
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->setObjectName(QString::fromUtf8("comboDep"));
        comboDep->setEditable(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, comboDep);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_12);

        spinSalary = new QSpinBox(groupBox_2);
        spinSalary->setObjectName(QString::fromUtf8("spinSalary"));
        spinSalary->setMinimum(1000);
        spinSalary->setMaximum(50000);
        spinSalary->setSingleStep(100);
        spinSalary->setValue(1000);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinSalary);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabPhoto = new QLabel(groupBox);
        LabPhoto->setObjectName(QString::fromUtf8("LabPhoto"));
        LabPhoto->setMinimumSize(QSize(150, 0));
        LabPhoto->setMaximumSize(QSize(350, 16777215));

        verticalLayout->addWidget(LabPhoto);


        horizontalLayout->addWidget(groupBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(spinEmpNo);
        label_2->setBuddy(editName);
        label_3->setBuddy(comboSex);
        label_5->setBuddy(editBirth);
        label_7->setBuddy(comboProvince);
        label_6->setBuddy(comboDep);
        label_12->setBuddy(spinSalary);
#endif // QT_CONFIG(shortcut)

        retranslateUi(WDialogData);
        QObject::connect(btnClose, &QPushButton::clicked, WDialogData, qOverload<>(&QDialog::reject));
        QObject::connect(btnOK, &QPushButton::clicked, WDialogData, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(WDialogData);
    } // setupUi

    void retranslateUi(QDialog *WDialogData)
    {
        WDialogData->setWindowTitle(QCoreApplication::translate("WDialogData", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
        btnSetPhoto->setText(QCoreApplication::translate("WDialogData", "\345\257\274\345\205\245\347\205\247\347\211\207", nullptr));
        btnClearPhoto->setText(QCoreApplication::translate("WDialogData", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
        btnOK->setText(QCoreApplication::translate("WDialogData", "\347\241\256  \345\256\232", nullptr));
        btnClose->setText(QCoreApplication::translate("WDialogData", "\345\217\226  \346\266\210", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("WDialogData", "\345\244\207   \346\263\250", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("WDialogData", "\345\267\245  \345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("WDialogData", "\345\247\223  \345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("WDialogData", "\346\200\247  \345\210\253", nullptr));
        comboSex->setItemText(0, QCoreApplication::translate("WDialogData", "\347\224\267", nullptr));
        comboSex->setItemText(1, QCoreApplication::translate("WDialogData", "\345\245\263", nullptr));

        label_5->setText(QCoreApplication::translate("WDialogData", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        editBirth->setDisplayFormat(QCoreApplication::translate("WDialogData", "yyyy-MM-dd", nullptr));
        label_7->setText(QCoreApplication::translate("WDialogData", "\345\207\272\347\224\237\347\234\201\344\273\275", nullptr));
        comboProvince->setItemText(0, QCoreApplication::translate("WDialogData", "\345\214\227\344\272\254", nullptr));
        comboProvince->setItemText(1, QCoreApplication::translate("WDialogData", "\344\270\212\346\265\267", nullptr));
        comboProvince->setItemText(2, QCoreApplication::translate("WDialogData", "\345\244\251\346\264\245", nullptr));
        comboProvince->setItemText(3, QCoreApplication::translate("WDialogData", "\351\207\215\345\272\206", nullptr));
        comboProvince->setItemText(4, QCoreApplication::translate("WDialogData", "\345\256\211\345\276\275", nullptr));
        comboProvince->setItemText(5, QCoreApplication::translate("WDialogData", "\346\262\263\345\214\227", nullptr));
        comboProvince->setItemText(6, QCoreApplication::translate("WDialogData", "\346\262\263\345\215\227", nullptr));
        comboProvince->setItemText(7, QCoreApplication::translate("WDialogData", "\346\271\226\345\214\227", nullptr));
        comboProvince->setItemText(8, QCoreApplication::translate("WDialogData", "\346\271\226\345\215\227", nullptr));
        comboProvince->setItemText(9, QCoreApplication::translate("WDialogData", "\345\261\261\350\245\277", nullptr));
        comboProvince->setItemText(10, QCoreApplication::translate("WDialogData", "\345\261\261\344\270\234", nullptr));
        comboProvince->setItemText(11, QCoreApplication::translate("WDialogData", "\351\231\225\350\245\277", nullptr));
        comboProvince->setItemText(12, QCoreApplication::translate("WDialogData", "\346\261\237\350\213\217", nullptr));
        comboProvince->setItemText(13, QCoreApplication::translate("WDialogData", "\346\261\237\350\245\277", nullptr));

        comboProvince->setCurrentText(QCoreApplication::translate("WDialogData", "\345\214\227\344\272\254", nullptr));
        label_6->setText(QCoreApplication::translate("WDialogData", "\351\203\250  \351\227\250", nullptr));
        comboDep->setItemText(0, QCoreApplication::translate("WDialogData", "\351\224\200\345\224\256\351\203\250", nullptr));
        comboDep->setItemText(1, QCoreApplication::translate("WDialogData", "\346\212\200\346\234\257\351\203\250", nullptr));
        comboDep->setItemText(2, QCoreApplication::translate("WDialogData", "\347\224\237\344\272\247\351\203\250", nullptr));
        comboDep->setItemText(3, QCoreApplication::translate("WDialogData", "\350\241\214\346\224\277\351\203\250", nullptr));

        comboDep->setCurrentText(QCoreApplication::translate("WDialogData", "\351\224\200\345\224\256\351\203\250", nullptr));
        label_12->setText(QCoreApplication::translate("WDialogData", "\345\267\245  \350\265\204", nullptr));
        spinSalary->setPrefix(QString());
        groupBox->setTitle(QCoreApplication::translate("WDialogData", "\347\205\247  \347\211\207", nullptr));
        LabPhoto->setText(QCoreApplication::translate("WDialogData", "dbLabPhoto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WDialogData: public Ui_WDialogData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDIALOGDATA_H
