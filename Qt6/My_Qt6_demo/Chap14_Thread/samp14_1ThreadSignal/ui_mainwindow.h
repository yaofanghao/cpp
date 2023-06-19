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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actThread_Run;
    QAction *actDice_Run;
    QAction *actDice_Pause;
    QAction *actThread_Quit;
    QAction *actClear;
    QAction *actClose;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QLabel *labPic;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(474, 306);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Games.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actThread_Run = new QAction(MainWindow);
        actThread_Run->setObjectName(QString::fromUtf8("actThread_Run"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/flag24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actThread_Run->setIcon(icon1);
        actDice_Run = new QAction(MainWindow);
        actDice_Run->setObjectName(QString::fromUtf8("actDice_Run"));
        actDice_Run->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/play24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDice_Run->setIcon(icon2);
        actDice_Pause = new QAction(MainWindow);
        actDice_Pause->setObjectName(QString::fromUtf8("actDice_Pause"));
        actDice_Pause->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/pause24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDice_Pause->setIcon(icon3);
        actThread_Quit = new QAction(MainWindow);
        actThread_Quit->setObjectName(QString::fromUtf8("actThread_Quit"));
        actThread_Quit->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/block24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actThread_Quit->setIcon(icon4);
        actClear = new QAction(MainWindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon5);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        labPic = new QLabel(centralwidget);
        labPic->setObjectName(QString::fromUtf8("labPic"));
        labPic->setMinimumSize(QSize(160, 0));
        labPic->setPixmap(QPixmap(QString::fromUtf8(":/dice/images/d0.jpg")));
        labPic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labPic);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actThread_Run);
        toolBar->addAction(actDice_Run);
        toolBar->addAction(actDice_Pause);
        toolBar->addAction(actThread_Quit);
        toolBar->addAction(actClear);
        toolBar->addAction(actClose);

        retranslateUi(MainWindow);
        QObject::connect(actClose, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\244\232\347\272\277\347\250\213\357\274\214\344\275\277\347\224\250\344\277\241\345\217\267\344\270\216\344\270\273\347\272\277\347\250\213\351\200\232\344\277\241", nullptr));
        actThread_Run->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\272\277\347\250\213", nullptr));
#if QT_CONFIG(tooltip)
        actThread_Run->setToolTip(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\272\277\347\250\213\350\277\220\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actDice_Run->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
#if QT_CONFIG(tooltip)
        actDice_Run->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\216\267\351\252\260\345\255\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actDice_Pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
#if QT_CONFIG(tooltip)
        actDice_Pause->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\216\267\351\252\260\345\255\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actThread_Quit->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\347\272\277\347\250\213", nullptr));
#if QT_CONFIG(tooltip)
        actThread_Quit->setToolTip(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\347\272\277\347\250\213\350\277\220\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actClose->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        labPic->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
