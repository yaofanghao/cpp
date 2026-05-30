/********************************************************************************
** Form generated from reading UI file 'tmetadatadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMETADATADIALOG_H
#define UI_TMETADATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TMetaDataDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;

    void setupUi(QDialog *TMetaDataDialog)
    {
        if (TMetaDataDialog->objectName().isEmpty())
            TMetaDataDialog->setObjectName(QString::fromUtf8("TMetaDataDialog"));
        TMetaDataDialog->resize(575, 307);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        TMetaDataDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(TMetaDataDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(TMetaDataDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TMetaDataDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);


        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(1, 1);

        retranslateUi(TMetaDataDialog);

        QMetaObject::connectSlotsByName(TMetaDataDialog);
    } // setupUi

    void retranslateUi(QDialog *TMetaDataDialog)
    {
        TMetaDataDialog->setWindowTitle(QCoreApplication::translate("TMetaDataDialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("TMetaDataDialog", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("TMetaDataDialog", "Author", nullptr));
        label_3->setText(QCoreApplication::translate("TMetaDataDialog", "Description", nullptr));
        label_4->setText(QCoreApplication::translate("TMetaDataDialog", "AlbumTitle", nullptr));
        label_5->setText(QCoreApplication::translate("TMetaDataDialog", "AudioBitRate", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("TMetaDataDialog", "ThumbnailImage", nullptr));
        label_6->setText(QCoreApplication::translate("TMetaDataDialog", "ThumbnailImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TMetaDataDialog: public Ui_TMetaDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMETADATADIALOG_H
