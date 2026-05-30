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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpen_IODevice;
    QAction *actOpen_TextStream;
    QAction *actQuit;
    QAction *actSave_IODevice;
    QAction *actSave_TextStream;
    QAction *actSave_TextSafe;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *textEditDevice;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *textEditStream;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(693, 450);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        actOpen_IODevice = new QAction(MainWindow);
        actOpen_IODevice->setObjectName(QString::fromUtf8("actOpen_IODevice"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/804.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen_IODevice->setIcon(icon);
        actOpen_TextStream = new QAction(MainWindow);
        actOpen_TextStream->setObjectName(QString::fromUtf8("actOpen_TextStream"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen_TextStream->setIcon(icon1);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actSave_IODevice = new QAction(MainWindow);
        actSave_IODevice->setObjectName(QString::fromUtf8("actSave_IODevice"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave_IODevice->setIcon(icon3);
        actSave_TextStream = new QAction(MainWindow);
        actSave_TextStream->setObjectName(QString::fromUtf8("actSave_TextStream"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/floppy.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave_TextStream->setIcon(icon4);
        actSave_TextSafe = new QAction(MainWindow);
        actSave_TextSafe->setObjectName(QString::fromUtf8("actSave_TextSafe"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/066.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        actSave_TextSafe->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 651, 371));
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        textEditDevice = new QPlainTextEdit(tab);
        textEditDevice->setObjectName(QString::fromUtf8("textEditDevice"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(11);
        textEditDevice->setFont(font1);

        verticalLayout->addWidget(textEditDevice);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/29.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        textEditStream = new QPlainTextEdit(tab_2);
        textEditStream->setObjectName(QString::fromUtf8("textEditStream"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(0, 0, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(0, 0, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        QBrush brush5(QColor(0, 0, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        textEditStream->setPalette(palette);
        textEditStream->setFont(font1);

        verticalLayout_2->addWidget(textEditStream);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/133.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon7, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actOpen_IODevice);
        mainToolBar->addAction(actSave_IODevice);
        mainToolBar->addAction(actSave_TextSafe);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actOpen_TextStream);
        mainToolBar->addAction(actSave_TextStream);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\346\226\207\344\273\266\350\257\273\345\206\231", nullptr));
        actOpen_IODevice->setText(QCoreApplication::translate("MainWindow", "QFile\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actOpen_IODevice->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250QFile\346\211\223\345\274\200\346\226\207\346\234\254\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actOpen_IODevice->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\250QFile\346\211\223\345\274\200\346\226\207\346\234\254\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        actOpen_TextStream->setText(QCoreApplication::translate("MainWindow", "QTextStream\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actOpen_TextStream->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250QTextStream\346\211\223\345\274\200\346\226\207\346\234\254\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actOpen_TextStream->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\250QTextStream\346\211\223\345\274\200\346\226\207\346\234\254\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actSave_IODevice->setText(QCoreApplication::translate("MainWindow", "QFile\345\217\246\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actSave_IODevice->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250QFile\347\233\264\346\216\245\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actSave_IODevice->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\250QFile\347\233\264\346\216\245\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        actSave_TextStream->setText(QCoreApplication::translate("MainWindow", "QTextStream\345\217\246\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actSave_TextStream->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250QTextStream\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actSave_TextStream->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\250QTextStream\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        actSave_TextSafe->setText(QCoreApplication::translate("MainWindow", "QSaveFile\345\217\246\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actSave_TextSafe->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250QSaveFile\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actSave_TextSafe->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\250QSaveFile\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "QFile\347\233\264\346\216\245\346\223\215\344\275\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "QTextStream\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
