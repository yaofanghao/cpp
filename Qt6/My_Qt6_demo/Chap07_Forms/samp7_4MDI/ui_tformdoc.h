/********************************************************************************
** Form generated from reading UI file 'tformdoc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFORMDOC_H
#define UI_TFORMDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TFormDoc
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *TFormDoc)
    {
        if (TFormDoc->objectName().isEmpty())
            TFormDoc->setObjectName(QString::fromUtf8("TFormDoc"));
        TFormDoc->resize(550, 386);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        TFormDoc->setFont(font);
        verticalLayout = new QVBoxLayout(TFormDoc);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(TFormDoc);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(TFormDoc);

        QMetaObject::connectSlotsByName(TFormDoc);
    } // setupUi

    void retranslateUi(QWidget *TFormDoc)
    {
        TFormDoc->setWindowTitle(QCoreApplication::translate("TFormDoc", "new document", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TFormDoc: public Ui_TFormDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFORMDOC_H
