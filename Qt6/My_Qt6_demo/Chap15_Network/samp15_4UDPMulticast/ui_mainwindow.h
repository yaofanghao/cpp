/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QAction *actClear;
    QAction *actHostInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinPort;
    QLabel *label_3;
    QComboBox *comboIP;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *editMsg;
    QPushButton *btnMulticast;
    QPlainTextEdit *textEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(425, 270);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actStart = new QAction(MainWindow);
        actStart->setObjectName(QString::fromUtf8("actStart"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(MainWindow);
        actStop->setObjectName(QString::fromUtf8("actStop"));
        actStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(MainWindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        actHostInfo = new QAction(MainWindow);
        actHostInfo->setObjectName(QString::fromUtf8("actHostInfo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinPort = new QSpinBox(centralWidget);
        spinPort->setObjectName(QString::fromUtf8("spinPort"));
        spinPort->setMinimum(1);
        spinPort->setMaximum(65535);
        spinPort->setValue(35320);

        horizontalLayout->addWidget(spinPort);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        comboIP = new QComboBox(centralWidget);
        comboIP->addItem(QString());
        comboIP->addItem(QString());
        comboIP->addItem(QString());
        comboIP->setObjectName(QString::fromUtf8("comboIP"));
        comboIP->setMinimumSize(QSize(150, 0));
        comboIP->setEditable(true);
        comboIP->setDuplicatesEnabled(false);

        horizontalLayout->addWidget(comboIP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        editMsg = new QLineEdit(centralWidget);
        editMsg->setObjectName(QString::fromUtf8("editMsg"));

        horizontalLayout_2->addWidget(editMsg);

        btnMulticast = new QPushButton(centralWidget);
        btnMulticast->setObjectName(QString::fromUtf8("btnMulticast"));
        btnMulticast->setEnabled(false);

        horizontalLayout_2->addWidget(btnMulticast);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QPlainTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actStart);
        mainToolBar->addAction(actStop);
        mainToolBar->addAction(actClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UDP Multicast", nullptr));
        actStart->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\347\273\204\346\222\255", nullptr));
#if QT_CONFIG(tooltip)
        actStart->setToolTip(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\347\273\204\346\222\255", nullptr));
#endif // QT_CONFIG(tooltip)
        actStop->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\273\204\346\222\255", nullptr));
#if QT_CONFIG(tooltip)
        actStop->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\273\204\346\222\255", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actHostInfo->setText(QCoreApplication::translate("MainWindow", "\346\234\254\346\234\272\345\234\260\345\235\200", nullptr));
#if QT_CONFIG(tooltip)
        actHostInfo->setToolTip(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "\347\273\204\346\222\255\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\204\346\222\255IP\345\234\260\345\235\200", nullptr));
        comboIP->setItemText(0, QCoreApplication::translate("MainWindow", "239.255.43.21", nullptr));
        comboIP->setItemText(1, QCoreApplication::translate("MainWindow", "239.255.100.1", nullptr));
        comboIP->setItemText(2, QCoreApplication::translate("MainWindow", "239.255.255.100", nullptr));

        btnMulticast->setText(QCoreApplication::translate("MainWindow", "\347\273\204\346\222\255\346\266\210\346\201\257", nullptr));
        textEdit->setPlainText(QCoreApplication::translate("MainWindow", "239.0.0.0\357\275\236239.255.255.255\344\270\272\346\234\254\345\234\260\347\256\241\347\220\206\347\273\204\346\222\255\345\234\260\345\235\200\350\214\203\345\233\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
