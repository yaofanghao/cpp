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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actSurf_Color;
    QAction *actSurf_GradColor1;
    QAction *actSurf_GradColor2;
    QAction *actClose;
    QAction *actPoint_Modify;
    QAction *actPoint_DeleteRow;
    QWidget *centralWidget;
    QFrame *frameSetup;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QComboBox *comboCamera;
    QLabel *label_7;
    QSlider *sliderH;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QToolButton *btnMoveUp;
    QToolButton *btnMoveLeft;
    QToolButton *btnMoveRight;
    QToolButton *btnMoveDown;
    QToolButton *btnResetCamera;
    QLabel *label_8;
    QSlider *sliderV;
    QLabel *label_12;
    QSlider *sliderZoom;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *cBoxTheme;
    QLabel *label_4;
    QSpinBox *spinFontSize;
    QCheckBox *chkBoxBackground;
    QCheckBox *chkBoxGrid;
    QCheckBox *chkBoxShadow;
    QCheckBox *chkBoxAxisTitle;
    QCheckBox *chkBoxReverse;
    QCheckBox *chkBoxAxisBackground;
    QLabel *label_3;
    QComboBox *cBoxSelectionMode;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QComboBox *comboDrawMode;
    QLabel *label_2;
    QComboBox *cBoxBarStyle;
    QCheckBox *chkBoxSmooth;
    QCheckBox *chkBoxItemLabel;
    QCheckBox *chkBoxFlatShading;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(854, 588);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        actSurf_Color = new QAction(MainWindow);
        actSurf_Color->setObjectName(QString::fromUtf8("actSurf_Color"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/211.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actSurf_Color->setIcon(icon);
        actSurf_GradColor1 = new QAction(MainWindow);
        actSurf_GradColor1->setObjectName(QString::fromUtf8("actSurf_GradColor1"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/720.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSurf_GradColor1->setIcon(icon1);
        actSurf_GradColor2 = new QAction(MainWindow);
        actSurf_GradColor2->setObjectName(QString::fromUtf8("actSurf_GradColor2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/726.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSurf_GradColor2->setIcon(icon2);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon3);
        actPoint_Modify = new QAction(MainWindow);
        actPoint_Modify->setObjectName(QString::fromUtf8("actPoint_Modify"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/810.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPoint_Modify->setIcon(icon4);
        actPoint_DeleteRow = new QAction(MainWindow);
        actPoint_DeleteRow->setObjectName(QString::fromUtf8("actPoint_DeleteRow"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/images/318.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPoint_DeleteRow->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frameSetup = new QFrame(centralWidget);
        frameSetup->setObjectName(QString::fromUtf8("frameSetup"));
        frameSetup->setGeometry(QRect(10, 10, 300, 531));
        frameSetup->setMaximumSize(QSize(350, 16777215));
        frameSetup->setFrameShape(QFrame::Panel);
        frameSetup->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameSetup);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        groupBox_2 = new QGroupBox(frameSetup);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        comboCamera = new QComboBox(groupBox_2);
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->setObjectName(QString::fromUtf8("comboCamera"));

        gridLayout->addWidget(comboCamera, 0, 1, 1, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        sliderH = new QSlider(groupBox_2);
        sliderH->setObjectName(QString::fromUtf8("sliderH"));
        sliderH->setMinimum(-180);
        sliderH->setMaximum(180);
        sliderH->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderH, 1, 1, 1, 1);

        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(5);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        btnMoveUp = new QToolButton(frame);
        btnMoveUp->setObjectName(QString::fromUtf8("btnMoveUp"));
        btnMoveUp->setArrowType(Qt::UpArrow);

        gridLayout_4->addWidget(btnMoveUp, 0, 1, 1, 1);

        btnMoveLeft = new QToolButton(frame);
        btnMoveLeft->setObjectName(QString::fromUtf8("btnMoveLeft"));
        btnMoveLeft->setArrowType(Qt::LeftArrow);

        gridLayout_4->addWidget(btnMoveLeft, 1, 0, 1, 1);

        btnMoveRight = new QToolButton(frame);
        btnMoveRight->setObjectName(QString::fromUtf8("btnMoveRight"));
        btnMoveRight->setArrowType(Qt::RightArrow);

        gridLayout_4->addWidget(btnMoveRight, 1, 2, 1, 1);

        btnMoveDown = new QToolButton(frame);
        btnMoveDown->setObjectName(QString::fromUtf8("btnMoveDown"));
        btnMoveDown->setArrowType(Qt::DownArrow);

        gridLayout_4->addWidget(btnMoveDown, 2, 1, 1, 1);

        btnResetCamera = new QToolButton(frame);
        btnResetCamera->setObjectName(QString::fromUtf8("btnResetCamera"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/images/326.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnResetCamera->setIcon(icon6);

        gridLayout_4->addWidget(btnResetCamera, 1, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 2, 3, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        sliderV = new QSlider(groupBox_2);
        sliderV->setObjectName(QString::fromUtf8("sliderV"));
        sliderV->setMinimum(-180);
        sliderV->setMaximum(180);
        sliderV->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderV, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        sliderZoom = new QSlider(groupBox_2);
        sliderZoom->setObjectName(QString::fromUtf8("sliderZoom"));
        sliderZoom->setMinimum(10);
        sliderZoom->setMaximum(500);
        sliderZoom->setValue(100);
        sliderZoom->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderZoom, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frameSetup);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(8);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setIndent(10);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        cBoxTheme = new QComboBox(groupBox_3);
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->addItem(QString());
        cBoxTheme->setObjectName(QString::fromUtf8("cBoxTheme"));

        gridLayout_3->addWidget(cBoxTheme, 0, 1, 1, 2);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setIndent(10);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        spinFontSize = new QSpinBox(groupBox_3);
        spinFontSize->setObjectName(QString::fromUtf8("spinFontSize"));
        spinFontSize->setMinimum(5);
        spinFontSize->setValue(10);

        gridLayout_3->addWidget(spinFontSize, 1, 1, 1, 2);

        chkBoxBackground = new QCheckBox(groupBox_3);
        chkBoxBackground->setObjectName(QString::fromUtf8("chkBoxBackground"));
        chkBoxBackground->setChecked(true);

        gridLayout_3->addWidget(chkBoxBackground, 3, 0, 1, 1);

        chkBoxGrid = new QCheckBox(groupBox_3);
        chkBoxGrid->setObjectName(QString::fromUtf8("chkBoxGrid"));
        chkBoxGrid->setChecked(true);

        gridLayout_3->addWidget(chkBoxGrid, 3, 2, 1, 1);

        chkBoxShadow = new QCheckBox(groupBox_3);
        chkBoxShadow->setObjectName(QString::fromUtf8("chkBoxShadow"));
        chkBoxShadow->setChecked(true);

        gridLayout_3->addWidget(chkBoxShadow, 4, 0, 1, 1);

        chkBoxAxisTitle = new QCheckBox(groupBox_3);
        chkBoxAxisTitle->setObjectName(QString::fromUtf8("chkBoxAxisTitle"));
        chkBoxAxisTitle->setChecked(true);

        gridLayout_3->addWidget(chkBoxAxisTitle, 5, 0, 1, 2);

        chkBoxReverse = new QCheckBox(groupBox_3);
        chkBoxReverse->setObjectName(QString::fromUtf8("chkBoxReverse"));

        gridLayout_3->addWidget(chkBoxReverse, 4, 2, 1, 1);

        chkBoxAxisBackground = new QCheckBox(groupBox_3);
        chkBoxAxisBackground->setObjectName(QString::fromUtf8("chkBoxAxisBackground"));

        gridLayout_3->addWidget(chkBoxAxisBackground, 5, 2, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setIndent(10);

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        cBoxSelectionMode = new QComboBox(groupBox_3);
        cBoxSelectionMode->addItem(QString());
        cBoxSelectionMode->addItem(QString());
        cBoxSelectionMode->addItem(QString());
        cBoxSelectionMode->addItem(QString());
        cBoxSelectionMode->setObjectName(QString::fromUtf8("cBoxSelectionMode"));

        gridLayout_3->addWidget(cBoxSelectionMode, 2, 1, 1, 2);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(frameSetup);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(8);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setIndent(10);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        comboDrawMode = new QComboBox(groupBox_4);
        comboDrawMode->addItem(QString());
        comboDrawMode->addItem(QString());
        comboDrawMode->addItem(QString());
        comboDrawMode->setObjectName(QString::fromUtf8("comboDrawMode"));

        gridLayout_2->addWidget(comboDrawMode, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setIndent(10);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        cBoxBarStyle = new QComboBox(groupBox_4);
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->addItem(QString());
        cBoxBarStyle->setObjectName(QString::fromUtf8("cBoxBarStyle"));

        gridLayout_2->addWidget(cBoxBarStyle, 1, 1, 1, 2);

        chkBoxSmooth = new QCheckBox(groupBox_4);
        chkBoxSmooth->setObjectName(QString::fromUtf8("chkBoxSmooth"));
        chkBoxSmooth->setChecked(true);

        gridLayout_2->addWidget(chkBoxSmooth, 3, 0, 1, 2);

        chkBoxItemLabel = new QCheckBox(groupBox_4);
        chkBoxItemLabel->setObjectName(QString::fromUtf8("chkBoxItemLabel"));
        chkBoxItemLabel->setChecked(true);

        gridLayout_2->addWidget(chkBoxItemLabel, 3, 2, 1, 1);

        chkBoxFlatShading = new QCheckBox(groupBox_4);
        chkBoxFlatShading->setObjectName(QString::fromUtf8("chkBoxFlatShading"));

        gridLayout_2->addWidget(chkBoxFlatShading, 4, 2, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
#if QT_CONFIG(shortcut)
        label_6->setBuddy(comboCamera);
        label_7->setBuddy(sliderH);
        label_8->setBuddy(sliderV);
        label->setBuddy(cBoxTheme);
        label_4->setBuddy(spinFontSize);
        label_2->setBuddy(cBoxBarStyle);
#endif // QT_CONFIG(shortcut)

        toolBar->addAction(actSurf_Color);
        toolBar->addAction(actSurf_GradColor1);
        toolBar->addAction(actSurf_GradColor2);
        toolBar->addSeparator();
        toolBar->addAction(actPoint_Modify);
        toolBar->addAction(actPoint_DeleteRow);
        toolBar->addSeparator();
        toolBar->addAction(actClose);

        retranslateUi(MainWindow);
        QObject::connect(actClose, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        comboCamera->setCurrentIndex(0);
        cBoxSelectionMode->setCurrentIndex(1);
        comboDrawMode->setCurrentIndex(2);
        cBoxBarStyle->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\211\347\273\264\346\233\262\351\235\242\345\233\276", nullptr));
        actSurf_Color->setText(QCoreApplication::translate("MainWindow", "\346\233\262\351\235\242\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actSurf_Color->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\233\262\351\235\242\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actSurf_GradColor1->setText(QCoreApplication::translate("MainWindow", "\346\270\220\345\217\230\350\211\262\344\270\200", nullptr));
#if QT_CONFIG(tooltip)
        actSurf_GradColor1->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\346\270\220\345\217\230\350\211\262\344\270\200", nullptr));
#endif // QT_CONFIG(tooltip)
        actSurf_GradColor2->setText(QCoreApplication::translate("MainWindow", "\346\270\220\345\217\230\350\211\262\344\272\214", nullptr));
#if QT_CONFIG(tooltip)
        actSurf_GradColor2->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\346\270\220\345\217\230\350\211\262\344\272\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actClose->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actClose->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actPoint_Modify->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\202\271\345\235\220\346\240\207", nullptr));
#if QT_CONFIG(tooltip)
        actPoint_Modify->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\202\271\345\235\220\346\240\207(F2)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actPoint_Modify->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actPoint_DeleteRow->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actPoint_DeleteRow->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\344\270\200\350\241\214\347\232\204\347\202\271(Del)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actPoint_DeleteRow->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254\345\222\214\345\271\263\347\247\273", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\256\276\350\247\206\350\247\222", nullptr));
        comboCamera->setItemText(0, QCoreApplication::translate("MainWindow", "FrontLow", nullptr));
        comboCamera->setItemText(1, QCoreApplication::translate("MainWindow", "Front", nullptr));
        comboCamera->setItemText(2, QCoreApplication::translate("MainWindow", "FrontHigh", nullptr));
        comboCamera->setItemText(3, QCoreApplication::translate("MainWindow", "LeftLow", nullptr));
        comboCamera->setItemText(4, QCoreApplication::translate("MainWindow", "Left", nullptr));
        comboCamera->setItemText(5, QCoreApplication::translate("MainWindow", "LeftHigh", nullptr));
        comboCamera->setItemText(6, QCoreApplication::translate("MainWindow", "RightLow", nullptr));
        comboCamera->setItemText(7, QCoreApplication::translate("MainWindow", "Right", nullptr));
        comboCamera->setItemText(8, QCoreApplication::translate("MainWindow", "RightHigh", nullptr));
        comboCamera->setItemText(9, QCoreApplication::translate("MainWindow", "BehindLow", nullptr));
        comboCamera->setItemText(10, QCoreApplication::translate("MainWindow", "Behind", nullptr));
        comboCamera->setItemText(11, QCoreApplication::translate("MainWindow", "BehindHigh", nullptr));
        comboCamera->setItemText(12, QCoreApplication::translate("MainWindow", "IsometricLeft", nullptr));
        comboCamera->setItemText(13, QCoreApplication::translate("MainWindow", "IsometricLeftHigh", nullptr));
        comboCamera->setItemText(14, QCoreApplication::translate("MainWindow", "IsometricRight", nullptr));
        comboCamera->setItemText(15, QCoreApplication::translate("MainWindow", "IsometricRightHigh", nullptr));
        comboCamera->setItemText(16, QCoreApplication::translate("MainWindow", "DirectlyAbove", nullptr));
        comboCamera->setItemText(17, QCoreApplication::translate("MainWindow", "DirectlyAboveCW45", nullptr));
        comboCamera->setItemText(18, QCoreApplication::translate("MainWindow", "DirectlyAboveCCW45", nullptr));
        comboCamera->setItemText(19, QCoreApplication::translate("MainWindow", "FrontBelow", nullptr));
        comboCamera->setItemText(20, QCoreApplication::translate("MainWindow", "LeftBelow", nullptr));
        comboCamera->setItemText(21, QCoreApplication::translate("MainWindow", "RightBelow", nullptr));
        comboCamera->setItemText(22, QCoreApplication::translate("MainWindow", "BehindBelow", nullptr));
        comboCamera->setItemText(23, QCoreApplication::translate("MainWindow", "DirectlyBelow", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\346\227\213\350\275\254", nullptr));
        btnMoveUp->setText(QString());
        btnMoveLeft->setText(QString());
        btnMoveRight->setText(QString());
        btnMoveDown->setText(QString());
#if QT_CONFIG(tooltip)
        btnResetCamera->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215\345\210\260FrontHigh\350\247\206\350\247\222", nullptr));
#endif // QT_CONFIG(tooltip)
        btnResetCamera->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\346\227\213\350\275\254", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\274\251  \346\224\276", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\275\242\346\200\273\344\275\223", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\275\242\344\270\273\351\242\230", nullptr));
        cBoxTheme->setItemText(0, QCoreApplication::translate("MainWindow", "Qt", nullptr));
        cBoxTheme->setItemText(1, QCoreApplication::translate("MainWindow", "Primary Colors", nullptr));
        cBoxTheme->setItemText(2, QCoreApplication::translate("MainWindow", "Digia", nullptr));
        cBoxTheme->setItemText(3, QCoreApplication::translate("MainWindow", "StoneMoss", nullptr));
        cBoxTheme->setItemText(4, QCoreApplication::translate("MainWindow", "ArmyBlue", nullptr));
        cBoxTheme->setItemText(5, QCoreApplication::translate("MainWindow", "Retro", nullptr));
        cBoxTheme->setItemText(6, QCoreApplication::translate("MainWindow", "Ebony", nullptr));
        cBoxTheme->setItemText(7, QCoreApplication::translate("MainWindow", "Isabelle", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\345\244\247\345\260\217", nullptr));
        chkBoxBackground->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\203\214\346\231\257", nullptr));
        chkBoxGrid->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\203\214\346\231\257\347\275\221\346\240\274", nullptr));
        chkBoxShadow->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\351\230\264\345\275\261", nullptr));
        chkBoxAxisTitle->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\275\264\346\240\207\351\242\230", nullptr));
        chkBoxReverse->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264(\345\236\202\347\233\264\346\226\271\345\220\221)\345\217\215\345\220\221", nullptr));
        chkBoxAxisBackground->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\275\264\346\240\207\347\255\276\350\203\214\346\231\257", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\250\241\345\274\217", nullptr));
        cBoxSelectionMode->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        cBoxSelectionMode->setItemText(1, QCoreApplication::translate("MainWindow", "Item", nullptr));
        cBoxSelectionMode->setItemText(2, QCoreApplication::translate("MainWindow", "Row Slice", nullptr));
        cBoxSelectionMode->setItemText(3, QCoreApplication::translate("MainWindow", "Column Slice", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\272\217\345\210\227\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\233\262\351\235\242\346\240\267\345\274\217", nullptr));
        comboDrawMode->setItemText(0, QCoreApplication::translate("MainWindow", "Wireframe", nullptr));
        comboDrawMode->setItemText(1, QCoreApplication::translate("MainWindow", "Surface", nullptr));
        comboDrawMode->setItemText(2, QCoreApplication::translate("MainWindow", "Surface And Wireframe", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\202\271\345\275\242\347\212\266", nullptr));
        cBoxBarStyle->setItemText(0, QCoreApplication::translate("MainWindow", "Bar", nullptr));
        cBoxBarStyle->setItemText(1, QCoreApplication::translate("MainWindow", "Cube", nullptr));
        cBoxBarStyle->setItemText(2, QCoreApplication::translate("MainWindow", "Pyramid", nullptr));
        cBoxBarStyle->setItemText(3, QCoreApplication::translate("MainWindow", "Cone", nullptr));
        cBoxBarStyle->setItemText(4, QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        cBoxBarStyle->setItemText(5, QCoreApplication::translate("MainWindow", "BevelBar", nullptr));
        cBoxBarStyle->setItemText(6, QCoreApplication::translate("MainWindow", "BevelCube", nullptr));
        cBoxBarStyle->setItemText(7, QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        cBoxBarStyle->setItemText(8, QCoreApplication::translate("MainWindow", "Minimal", nullptr));
        cBoxBarStyle->setItemText(9, QCoreApplication::translate("MainWindow", "Arrow", nullptr));
        cBoxBarStyle->setItemText(10, QCoreApplication::translate("MainWindow", "Point", nullptr));

        chkBoxSmooth->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\202\271\345\205\211\346\273\221\346\225\210\346\236\234", nullptr));
        chkBoxItemLabel->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\215\225\347\202\271\346\240\207\347\255\276", nullptr));
        chkBoxFlatShading->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\235\242\347\235\200\350\211\262(FlatShading)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
