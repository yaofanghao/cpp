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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actFile_Open;
    QAction *actFile_Quit;
    QAction *actFile_Save;
    QAction *actImg_RotateLeft;
    QAction *actImg_RotateRight;
    QAction *actImg_FlipUD;
    QAction *actImg_FlipLR;
    QAction *actFile_Reload;
    QAction *actFile_SaveAs;
    QAction *actFile_Print;
    QAction *actFile_Preview;
    QAction *actImg_ZoomIn;
    QAction *actImg_ZoomOut;
    QWidget *centralwidget;
    QSplitter *splitter;
    QFrame *frameLeft;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *editImg_Format;
    QLabel *label_3;
    QLineEdit *editImg_Width;
    QLabel *label_4;
    QLineEdit *editImg_Height;
    QLabel *label_5;
    QLineEdit *editImg_Depth;
    QLabel *label_6;
    QLineEdit *editImg_BitPlane;
    QLabel *label;
    QLineEdit *editImg_SizeByte;
    QCheckBox *chkBox_GrayScale;
    QCheckBox *chkBox_Alpha;
    QLineEdit *editImg_DPM;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboFormat;
    QPushButton *btnFormatConvert;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioLSB;
    QRadioButton *radioMSB;
    QPushButton *btnGetRGB565;
    QPushButton *btnSaveDataFile;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *labPic;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainText;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(862, 587);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setIconSize(QSize(16, 16));
        actFile_Open = new QAction(MainWindow);
        actFile_Open->setObjectName(QString::fromUtf8("actFile_Open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/001.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Open->setIcon(icon);
        actFile_Quit = new QAction(MainWindow);
        actFile_Quit->setObjectName(QString::fromUtf8("actFile_Quit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Quit->setIcon(icon1);
        actFile_Save = new QAction(MainWindow);
        actFile_Save->setObjectName(QString::fromUtf8("actFile_Save"));
        actFile_Save->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Save->setIcon(icon2);
        actImg_RotateLeft = new QAction(MainWindow);
        actImg_RotateLeft->setObjectName(QString::fromUtf8("actImg_RotateLeft"));
        actImg_RotateLeft->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/rotateleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_RotateLeft->setIcon(icon3);
        actImg_RotateRight = new QAction(MainWindow);
        actImg_RotateRight->setObjectName(QString::fromUtf8("actImg_RotateRight"));
        actImg_RotateRight->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/rotateright.png"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_RotateRight->setIcon(icon4);
        actImg_FlipUD = new QAction(MainWindow);
        actImg_FlipUD->setObjectName(QString::fromUtf8("actImg_FlipUD"));
        actImg_FlipUD->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/flip-vertical.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_FlipUD->setIcon(icon5);
        actImg_FlipLR = new QAction(MainWindow);
        actImg_FlipLR->setObjectName(QString::fromUtf8("actImg_FlipLR"));
        actImg_FlipLR->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/flip-horizontal.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_FlipLR->setIcon(icon6);
        actFile_Reload = new QAction(MainWindow);
        actFile_Reload->setObjectName(QString::fromUtf8("actFile_Reload"));
        actFile_Reload->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/126.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Reload->setIcon(icon7);
        actFile_SaveAs = new QAction(MainWindow);
        actFile_SaveAs->setObjectName(QString::fromUtf8("actFile_SaveAs"));
        actFile_SaveAs->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/save-as24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_SaveAs->setIcon(icon8);
        actFile_Print = new QAction(MainWindow);
        actFile_Print->setObjectName(QString::fromUtf8("actFile_Print"));
        actFile_Print->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/print1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Print->setIcon(icon9);
        actFile_Preview = new QAction(MainWindow);
        actFile_Preview->setObjectName(QString::fromUtf8("actFile_Preview"));
        actFile_Preview->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/preview1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Preview->setIcon(icon10);
        actImg_ZoomIn = new QAction(MainWindow);
        actImg_ZoomIn->setObjectName(QString::fromUtf8("actImg_ZoomIn"));
        actImg_ZoomIn->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_ZoomIn->setIcon(icon11);
        actImg_ZoomOut = new QAction(MainWindow);
        actImg_ZoomOut->setObjectName(QString::fromUtf8("actImg_ZoomOut"));
        actImg_ZoomOut->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actImg_ZoomOut->setIcon(icon12);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(15, 35, 796, 471));
        splitter->setOrientation(Qt::Horizontal);
        frameLeft = new QFrame(splitter);
        frameLeft->setObjectName(QString::fromUtf8("frameLeft"));
        frameLeft->setEnabled(true);
        frameLeft->setMaximumSize(QSize(300, 16777215));
        frameLeft->setFrameShape(QFrame::Panel);
        frameLeft->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frameLeft);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(frameLeft);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        editImg_Format = new QLineEdit(groupBox);
        editImg_Format->setObjectName(QString::fromUtf8("editImg_Format"));
        editImg_Format->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editImg_Format);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        editImg_Width = new QLineEdit(groupBox);
        editImg_Width->setObjectName(QString::fromUtf8("editImg_Width"));
        editImg_Width->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, editImg_Width);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        editImg_Height = new QLineEdit(groupBox);
        editImg_Height->setObjectName(QString::fromUtf8("editImg_Height"));
        editImg_Height->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, editImg_Height);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        editImg_Depth = new QLineEdit(groupBox);
        editImg_Depth->setObjectName(QString::fromUtf8("editImg_Depth"));
        editImg_Depth->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, editImg_Depth);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        editImg_BitPlane = new QLineEdit(groupBox);
        editImg_BitPlane->setObjectName(QString::fromUtf8("editImg_BitPlane"));
        editImg_BitPlane->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, editImg_BitPlane);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label);

        editImg_SizeByte = new QLineEdit(groupBox);
        editImg_SizeByte->setObjectName(QString::fromUtf8("editImg_SizeByte"));
        editImg_SizeByte->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, editImg_SizeByte);

        chkBox_GrayScale = new QCheckBox(groupBox);
        chkBox_GrayScale->setObjectName(QString::fromUtf8("chkBox_GrayScale"));
        chkBox_GrayScale->setEnabled(true);

        formLayout_2->setWidget(7, QFormLayout::LabelRole, chkBox_GrayScale);

        chkBox_Alpha = new QCheckBox(groupBox);
        chkBox_Alpha->setObjectName(QString::fromUtf8("chkBox_Alpha"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, chkBox_Alpha);

        editImg_DPM = new QLineEdit(groupBox);
        editImg_DPM->setObjectName(QString::fromUtf8("editImg_DPM"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, editImg_DPM);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_7);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frameLeft);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        comboFormat = new QComboBox(groupBox_2);
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->setObjectName(QString::fromUtf8("comboFormat"));

        verticalLayout_5->addWidget(comboFormat);

        btnFormatConvert = new QPushButton(groupBox_2);
        btnFormatConvert->setObjectName(QString::fromUtf8("btnFormatConvert"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/824.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnFormatConvert->setIcon(icon13);

        verticalLayout_5->addWidget(btnFormatConvert);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frameLeft);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioLSB = new QRadioButton(groupBox_3);
        radioLSB->setObjectName(QString::fromUtf8("radioLSB"));
        radioLSB->setChecked(true);

        horizontalLayout->addWidget(radioLSB);

        radioMSB = new QRadioButton(groupBox_3);
        radioMSB->setObjectName(QString::fromUtf8("radioMSB"));

        horizontalLayout->addWidget(radioMSB);


        verticalLayout_3->addLayout(horizontalLayout);

        btnGetRGB565 = new QPushButton(groupBox_3);
        btnGetRGB565->setObjectName(QString::fromUtf8("btnGetRGB565"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/116.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnGetRGB565->setIcon(icon14);

        verticalLayout_3->addWidget(btnGetRGB565);

        btnSaveDataFile = new QPushButton(groupBox_3);
        btnSaveDataFile->setObjectName(QString::fromUtf8("btnSaveDataFile"));
        btnSaveDataFile->setEnabled(false);
        btnSaveDataFile->setIcon(icon2);

        verticalLayout_3->addWidget(btnSaveDataFile);


        verticalLayout_6->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        splitter->addWidget(frameLeft);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 471, 436));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labPic = new QLabel(scrollAreaWidgetContents);
        labPic->setObjectName(QString::fromUtf8("labPic"));
        labPic->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labPic);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        tabWidget->addTab(tab, icon13, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainText = new QPlainTextEdit(tab_2);
        plainText->setObjectName(QString::fromUtf8("plainText"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(12);
        plainText->setFont(font1);

        verticalLayout->addWidget(plainText);

        tabWidget->addTab(tab_2, icon14, QString());
        splitter->addWidget(tabWidget);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actFile_Open);
        toolBar->addAction(actFile_Reload);
        toolBar->addAction(actFile_Save);
        toolBar->addAction(actFile_SaveAs);
        toolBar->addAction(actFile_Preview);
        toolBar->addAction(actFile_Print);
        toolBar->addSeparator();
        toolBar->addAction(actImg_ZoomIn);
        toolBar->addAction(actImg_ZoomOut);
        toolBar->addAction(actImg_RotateLeft);
        toolBar->addAction(actImg_RotateRight);
        toolBar->addAction(actImg_FlipUD);
        toolBar->addAction(actImg_FlipLR);
        toolBar->addSeparator();
        toolBar->addAction(actFile_Quit);

        retranslateUi(MainWindow);
        QObject::connect(actFile_Quit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\224\250QIamge\350\277\233\350\241\214\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        actFile_Open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Open->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFile_Open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actFile_Quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Quit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        actFile_Save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Save->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\210\260\345\275\223\345\211\215\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFile_Save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actImg_RotateLeft->setText(QCoreApplication::translate("MainWindow", "\345\267\246\346\227\213", nullptr));
#if QT_CONFIG(tooltip)
        actImg_RotateLeft->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210\346\227\213\350\275\25490\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        actImg_RotateRight->setText(QCoreApplication::translate("MainWindow", "\345\217\263\346\227\213", nullptr));
#if QT_CONFIG(tooltip)
        actImg_RotateRight->setToolTip(QCoreApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\25490\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        actImg_FlipUD->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(tooltip)
        actImg_FlipUD->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", nullptr));
#endif // QT_CONFIG(tooltip)
        actImg_FlipLR->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(tooltip)
        actImg_FlipLR->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", nullptr));
#endif // QT_CONFIG(tooltip)
        actFile_Reload->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\350\275\275\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Reload->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\350\275\275\345\205\245\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actFile_SaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actFile_SaveAs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\345\233\276\347\211\207\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actFile_Print->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Print->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actFile_Preview->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", nullptr));
#if QT_CONFIG(tooltip)
        actFile_Preview->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFile_Preview->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actImg_ZoomIn->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actImg_ZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actImg_ZoomIn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        actImg_ZoomOut->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actImg_ZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actImg_ZoomOut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\261\236\346\200\247", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\240\274\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\256\275\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\351\253\230\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\267\261\345\272\246", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QCoreApplication::translate("MainWindow", "bitPlaneCount", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\275\215\345\271\263\351\235\242\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\247\345\260\217", nullptr));
        chkBox_GrayScale->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\345\233\276", nullptr));
        chkBox_Alpha->setText(QCoreApplication::translate("MainWindow", "\345\205\267\346\234\211Alpha\351\200\232\351\201\223", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "DPI\345\210\206\350\276\250\347\216\207", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", " \345\233\276\345\203\217\346\240\274\345\274\217\350\275\254\346\215\242", nullptr));
        comboFormat->setItemText(0, QCoreApplication::translate("MainWindow", "16-bit RGB565 format", nullptr));
        comboFormat->setItemText(1, QCoreApplication::translate("MainWindow", "24-bit RGB888 format", nullptr));
        comboFormat->setItemText(2, QCoreApplication::translate("MainWindow", "32-bit RGB format", nullptr));
        comboFormat->setItemText(3, QCoreApplication::translate("MainWindow", "8-bit grayscale format", nullptr));
        comboFormat->setItemText(4, QCoreApplication::translate("MainWindow", "16-bit grayscale format", nullptr));
        comboFormat->setItemText(5, QCoreApplication::translate("MainWindow", "8-bit indexes into a colormap", nullptr));

        btnFormatConvert->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\240\274\345\274\217\350\275\254\346\215\242", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "RGB565\346\225\260\346\215\256", nullptr));
        radioLSB->setText(QCoreApplication::translate("MainWindow", "\344\275\216\345\255\227\350\212\202\345\234\250\345\211\215", nullptr));
        radioMSB->setText(QCoreApplication::translate("MainWindow", "\351\253\230\345\255\227\350\212\202\345\234\250\345\211\215", nullptr));
        btnGetRGB565->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220RGB565\346\225\260\346\215\256", nullptr));
        btnSaveDataFile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256\346\226\207\344\273\266", nullptr));
        labPic->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", " \345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "RGB565\346\225\260\346\215\256", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
