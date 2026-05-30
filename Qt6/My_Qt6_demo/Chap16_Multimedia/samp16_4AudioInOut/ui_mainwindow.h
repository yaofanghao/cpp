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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QAction *actTest;
    QAction *actPlayFile;
    QAction *actPreferFormat;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkBoxShowWave;
    QCheckBox *chkBoxSaveToFile;
    QPushButton *btnGetFile;
    QLineEdit *editFileName;
    QSplitter *splitter;
    QGroupBox *groupBoxDevice;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboDevices;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *actualSampleTypeLabel;
    QComboBox *comboSampFormat;
    QLabel *actualFreqLabel;
    QSpinBox *spinSampRate;
    QLabel *labSampRateRange;
    QLabel *actualChannelLabel;
    QSpinBox *spinChanCount;
    QLabel *labChanCountRange;
    QLabel *actualSampleSizeLabel;
    QSpinBox *spinBytesPerSamp;
    QLabel *actualSampleSizeLabel_2;
    QSpinBox *spinBytesPerFrame;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    TChartView *chartView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labBufferSize;
    QSpacerItem *horizontalSpacer;
    QLabel *labBlockSize;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 482);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actStart = new QAction(MainWindow);
        actStart->setObjectName(QString::fromUtf8("actStart"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/626.bmp"), QSize(), QIcon::Normal, QIcon::Off);
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
        actTest = new QAction(MainWindow);
        actTest->setObjectName(QString::fromUtf8("actTest"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/22.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actTest->setIcon(icon3);
        actPlayFile = new QAction(MainWindow);
        actPlayFile->setObjectName(QString::fromUtf8("actPlayFile"));
        actPlayFile->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Wave Sound.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actPlayFile->setIcon(icon4);
        actPreferFormat = new QAction(MainWindow);
        actPreferFormat->setObjectName(QString::fromUtf8("actPreferFormat"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/237.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        actPreferFormat->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 5, 0, 5);
        chkBoxShowWave = new QCheckBox(frame);
        chkBoxShowWave->setObjectName(QString::fromUtf8("chkBoxShowWave"));
        chkBoxShowWave->setChecked(true);

        horizontalLayout_3->addWidget(chkBoxShowWave);

        chkBoxSaveToFile = new QCheckBox(frame);
        chkBoxSaveToFile->setObjectName(QString::fromUtf8("chkBoxSaveToFile"));
        chkBoxSaveToFile->setChecked(true);

        horizontalLayout_3->addWidget(chkBoxSaveToFile);

        btnGetFile = new QPushButton(frame);
        btnGetFile->setObjectName(QString::fromUtf8("btnGetFile"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnGetFile->setIcon(icon6);

        horizontalLayout_3->addWidget(btnGetFile);

        editFileName = new QLineEdit(frame);
        editFileName->setObjectName(QString::fromUtf8("editFileName"));
        editFileName->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(editFileName);


        verticalLayout_3->addWidget(frame);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBoxDevice = new QGroupBox(splitter);
        groupBoxDevice->setObjectName(QString::fromUtf8("groupBoxDevice"));
        verticalLayout_2 = new QVBoxLayout(groupBoxDevice);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBoxDevice);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboDevices = new QComboBox(groupBoxDevice);
        comboDevices->setObjectName(QString::fromUtf8("comboDevices"));

        horizontalLayout->addWidget(comboDevices);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox = new QGroupBox(groupBoxDevice);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        actualSampleTypeLabel = new QLabel(groupBox);
        actualSampleTypeLabel->setObjectName(QString::fromUtf8("actualSampleTypeLabel"));
        actualSampleTypeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(actualSampleTypeLabel, 0, 0, 1, 1);

        comboSampFormat = new QComboBox(groupBox);
        comboSampFormat->addItem(QString());
        comboSampFormat->addItem(QString());
        comboSampFormat->addItem(QString());
        comboSampFormat->addItem(QString());
        comboSampFormat->addItem(QString());
        comboSampFormat->setObjectName(QString::fromUtf8("comboSampFormat"));

        gridLayout->addWidget(comboSampFormat, 0, 1, 1, 1);

        actualFreqLabel = new QLabel(groupBox);
        actualFreqLabel->setObjectName(QString::fromUtf8("actualFreqLabel"));
        actualFreqLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(actualFreqLabel, 1, 0, 1, 1);

        spinSampRate = new QSpinBox(groupBox);
        spinSampRate->setObjectName(QString::fromUtf8("spinSampRate"));
        spinSampRate->setMinimum(1);
        spinSampRate->setMaximum(10000000);

        gridLayout->addWidget(spinSampRate, 1, 1, 1, 1);

        labSampRateRange = new QLabel(groupBox);
        labSampRateRange->setObjectName(QString::fromUtf8("labSampRateRange"));

        gridLayout->addWidget(labSampRateRange, 2, 1, 1, 1);

        actualChannelLabel = new QLabel(groupBox);
        actualChannelLabel->setObjectName(QString::fromUtf8("actualChannelLabel"));
        actualChannelLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(actualChannelLabel, 3, 0, 1, 1);

        spinChanCount = new QSpinBox(groupBox);
        spinChanCount->setObjectName(QString::fromUtf8("spinChanCount"));
        spinChanCount->setMinimum(1);
        spinChanCount->setMaximum(100);

        gridLayout->addWidget(spinChanCount, 3, 1, 1, 1);

        labChanCountRange = new QLabel(groupBox);
        labChanCountRange->setObjectName(QString::fromUtf8("labChanCountRange"));

        gridLayout->addWidget(labChanCountRange, 4, 1, 1, 1);

        actualSampleSizeLabel = new QLabel(groupBox);
        actualSampleSizeLabel->setObjectName(QString::fromUtf8("actualSampleSizeLabel"));
        actualSampleSizeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(actualSampleSizeLabel, 5, 0, 1, 1);

        spinBytesPerSamp = new QSpinBox(groupBox);
        spinBytesPerSamp->setObjectName(QString::fromUtf8("spinBytesPerSamp"));
        spinBytesPerSamp->setReadOnly(true);
        spinBytesPerSamp->setMinimum(1);
        spinBytesPerSamp->setMaximum(10);

        gridLayout->addWidget(spinBytesPerSamp, 5, 1, 1, 1);

        actualSampleSizeLabel_2 = new QLabel(groupBox);
        actualSampleSizeLabel_2->setObjectName(QString::fromUtf8("actualSampleSizeLabel_2"));
        actualSampleSizeLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(actualSampleSizeLabel_2, 6, 0, 1, 1);

        spinBytesPerFrame = new QSpinBox(groupBox);
        spinBytesPerFrame->setObjectName(QString::fromUtf8("spinBytesPerFrame"));
        spinBytesPerFrame->setReadOnly(true);
        spinBytesPerFrame->setMinimum(1);
        spinBytesPerFrame->setMaximum(10000000);

        gridLayout->addWidget(spinBytesPerFrame, 6, 1, 1, 1);

        gridLayout->setColumnMinimumWidth(1, 1);

        verticalLayout_2->addWidget(groupBox);

        label_2 = new QLabel(groupBoxDevice);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        splitter->addWidget(groupBoxDevice);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        chartView = new TChartView(groupBox_2);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));

        verticalLayout->addWidget(chartView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labBufferSize = new QLabel(groupBox_2);
        labBufferSize->setObjectName(QString::fromUtf8("labBufferSize"));
        labBufferSize->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(labBufferSize);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labBlockSize = new QLabel(groupBox_2);
        labBlockSize->setObjectName(QString::fromUtf8("labBlockSize"));
        labBlockSize->setMinimumSize(QSize(190, 0));

        horizontalLayout_2->addWidget(labBlockSize);


        verticalLayout->addLayout(horizontalLayout_2);

        splitter->addWidget(groupBox_2);

        verticalLayout_3->addWidget(splitter);

        verticalLayout_3->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actPreferFormat);
        mainToolBar->addAction(actTest);
        mainToolBar->addAction(actStart);
        mainToolBar->addAction(actStop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actPlayFile);
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        comboSampFormat->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\345\222\214\346\222\255\346\224\276\345\216\237\345\247\213\351\237\263\351\242\221\346\225\260\346\215\256", nullptr));
        actStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
#if QT_CONFIG(tooltip)
        actStart->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
#if QT_CONFIG(tooltip)
        actStop->setToolTip(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actTest->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\351\237\263\351\242\221\346\240\274\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        actTest->setToolTip(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\230\257\345\220\246\346\224\257\346\214\201\346\211\200\350\256\276\347\275\256\347\232\204\351\237\263\351\242\221\346\240\274\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actPlayFile->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actPlayFile->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actPreferFormat->setText(QCoreApplication::translate("MainWindow", "\351\246\226\351\200\211\351\237\263\351\242\221\346\240\274\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        actPreferFormat->setToolTip(QCoreApplication::translate("MainWindow", "\351\246\226\351\200\211\351\237\263\351\242\221\346\240\274\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        chkBoxShowWave->setText(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\230\276\347\244\272\346\263\242\345\275\242", nullptr));
        chkBoxSaveToFile->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\350\256\260\345\275\225\345\210\260\346\226\207\344\273\266", nullptr));
        btnGetFile->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\226\207\344\273\266", nullptr));
        groupBoxDevice->setTitle(QCoreApplication::translate("MainWindow", "\351\237\263\351\242\221\350\276\223\345\205\245\350\256\276\345\244\207\345\222\214\346\240\274\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\351\237\263\351\242\221\350\276\223\345\205\245\350\256\276\345\244\207", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\237\263\351\242\221\346\240\274\345\274\217\357\274\210QAudioFormat\357\274\211", nullptr));
        actualSampleTypeLabel->setText(QCoreApplication::translate("MainWindow", "\351\207\207\346\240\267\347\202\271\346\240\274\345\274\217", nullptr));
        comboSampFormat->setItemText(0, QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        comboSampFormat->setItemText(1, QCoreApplication::translate("MainWindow", "UInt8", nullptr));
        comboSampFormat->setItemText(2, QCoreApplication::translate("MainWindow", "Int16", nullptr));
        comboSampFormat->setItemText(3, QCoreApplication::translate("MainWindow", "Int32", nullptr));
        comboSampFormat->setItemText(4, QCoreApplication::translate("MainWindow", "Float", nullptr));

        actualFreqLabel->setText(QCoreApplication::translate("MainWindow", "\351\207\207\346\240\267\351\242\221\347\216\207 (Hz)", nullptr));
        labSampRateRange->setText(QCoreApplication::translate("MainWindow", "\350\214\203\345\233\264\357\274\232", nullptr));
        actualChannelLabel->setText(QCoreApplication::translate("MainWindow", "\351\200\232\351\201\223\346\225\260", nullptr));
        labChanCountRange->setText(QCoreApplication::translate("MainWindow", "\350\214\203\345\233\264\357\274\232", nullptr));
        actualSampleSizeLabel->setText(QCoreApplication::translate("MainWindow", "\346\257\217\351\207\207\346\240\267\347\202\271\345\255\227\350\212\202\346\225\260", nullptr));
        actualSampleSizeLabel_2->setText(QCoreApplication::translate("MainWindow", "\346\257\217\345\270\247\345\255\227\350\212\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\263\250\346\204\217\357\274\232\346\273\241\350\266\263\344\273\245\344\270\213\346\235\241\344\273\266\346\211\215\345\217\257\344\273\245\346\230\276\347\244\272\346\233\262\347\272\277</p><p>\351\207\207\346\240\267\347\202\271\346\240\274\345\274\217 == UInt8</p><p>\351\200\232\351\201\223\346\225\260 ==1</p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\351\207\207\351\233\206\347\232\204\351\237\263\351\242\221\346\263\242\345\275\242", nullptr));
        labBufferSize->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\275\225\345\210\266\346\227\266\351\227\264=", nullptr));
        labBlockSize->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\235\227\345\255\227\350\212\202\346\225\260=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
