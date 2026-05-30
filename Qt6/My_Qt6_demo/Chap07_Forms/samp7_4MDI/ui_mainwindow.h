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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actDoc_New;
    QAction *actQuit;
    QAction *actDoc_Open;
    QAction *actFont;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actViewMode;
    QAction *actCascade;
    QAction *actTile;
    QAction *actCloseALL;
    QAction *actDoc_Save;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 480);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        actDoc_New = new QAction(MainWindow);
        actDoc_New->setObjectName(QString::fromUtf8("actDoc_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_New->setIcon(icon);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actDoc_Open = new QAction(MainWindow);
        actDoc_Open->setObjectName(QString::fromUtf8("actDoc_Open"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Open->setIcon(icon2);
        actFont = new QAction(MainWindow);
        actFont->setObjectName(QString::fromUtf8("actFont"));
        actFont->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/506.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFont->setIcon(icon3);
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QString::fromUtf8("actCut"));
        actCut->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/200.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon4);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QString::fromUtf8("actCopy"));
        actCopy->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/202.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon5);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QString::fromUtf8("actPaste"));
        actPaste->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/204.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon6);
        actViewMode = new QAction(MainWindow);
        actViewMode->setObjectName(QString::fromUtf8("actViewMode"));
        actViewMode->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/230.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actViewMode->setIcon(icon7);
        actCascade = new QAction(MainWindow);
        actCascade->setObjectName(QString::fromUtf8("actCascade"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/400.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCascade->setIcon(icon8);
        actTile = new QAction(MainWindow);
        actTile->setObjectName(QString::fromUtf8("actTile"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/406.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTile->setIcon(icon9);
        actCloseALL = new QAction(MainWindow);
        actCloseALL->setObjectName(QString::fromUtf8("actCloseALL"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCloseALL->setIcon(icon10);
        actDoc_Save = new QAction(MainWindow);
        actDoc_Save->setObjectName(QString::fromUtf8("actDoc_Save"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Save->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(30, 20, 371, 186));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAutoFillBackground(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actDoc_New);
        mainToolBar->addAction(actDoc_Open);
        mainToolBar->addAction(actDoc_Save);
        mainToolBar->addAction(actCloseALL);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actCut);
        mainToolBar->addAction(actCopy);
        mainToolBar->addAction(actPaste);
        mainToolBar->addAction(actFont);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actViewMode);
        mainToolBar->addAction(actCascade);
        mainToolBar->addAction(actTile);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MDI\345\272\224\347\224\250\347\250\213\345\272\217", nullptr));
        actDoc_New->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        actDoc_New->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\346\241\243\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actDoc_New->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        actDoc_Open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actDoc_Open->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actDoc_Open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actFont->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        actCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        actCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        actPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actViewMode->setText(QCoreApplication::translate("MainWindow", "MDI\346\250\241\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        actViewMode->setToolTip(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\346\250\241\345\274\217\346\210\226\351\241\265\351\235\242\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actCascade->setText(QCoreApplication::translate("MainWindow", "\347\272\247\350\201\224\345\261\225\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actCascade->setToolTip(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\347\272\247\350\201\224\345\261\225\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        actTile->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\261\225\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actTile->setToolTip(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\345\271\263\351\223\272\345\261\225\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        actCloseALL->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\345\205\250\351\203\250", nullptr));
#if QT_CONFIG(tooltip)
        actCloseALL->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actDoc_Save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actDoc_Save->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actDoc_Save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
