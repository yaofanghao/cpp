/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <tmylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actCom_Open;
    QAction *actCom_Close;
    QAction *actClose;
    QAction *actCom_Info;
    QAction *actClear;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_Port;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboCom_Port;
    QLabel *label_2;
    QComboBox *comboCom_Buad;
    QLabel *label_3;
    QComboBox *comboCom_DataBit;
    QLabel *label_4;
    QComboBox *comboCom_StopBit;
    QLabel *label_5;
    QComboBox *comboCom_Parity;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_2;
    QToolBox *toolBox;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnWF_Test;
    QPushButton *btnWF_Reset;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *comboWiFi_UartBuad;
    QPushButton *btnWF_UART_Set;
    QPushButton *btnWF_UART_Qry;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnWF_SetAsSTA;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLineEdit *editAP_Name;
    QLabel *label_8;
    QLineEdit *editAP_PWD;
    QPushButton *btnWF_SetAP;
    QPushButton *btnWF_GetAP;
    QSpacerItem *verticalSpacer;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_10;
    QFormLayout *formLayout;
    QLabel *label_9;
    QLineEdit *editServer_IP;
    QLabel *label_10;
    QSpinBox *spinServer_Port;
    QPushButton *btnTCP_SetServer;
    QPushButton *btnTCP_AutoConn;
    QPushButton *btnTCP_Query;
    QPushButton *btnTCP_GetMac;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QPushButton *btnTrans_Exit;
    QPushButton *btnTrans_Enter;
    QPushButton *btnTrans_AutoOnReset;
    QSpacerItem *verticalSpacer_2;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *textCOM;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkBox_NewLine1;
    QPushButton *btnNormSend;
    QSpacerItem *horizontalSpacer_3;
    QPlainTextEdit *plainText_Norm;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *chkBox_NewLine2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_CmdA;
    QGridLayout *gridLayout_2;
    QLineEdit *editCmd_A4;
    TMyLabel *lab_A4;
    QLineEdit *editCmd_A5;
    QLineEdit *editCmd_A1;
    TMyLabel *lab_A3;
    TMyLabel *lab_A5;
    QLineEdit *editCmd_A6;
    TMyLabel *lab_A2;
    QLineEdit *editCmd_A3;
    TMyLabel *lab_A6;
    TMyLabel *lab_A1;
    QLineEdit *editCmd_A2;
    QFrame *frame_CmdB;
    QGridLayout *gridLayout_3;
    QLineEdit *editCmd_B1;
    TMyLabel *lab_B2;
    QLineEdit *editCmd_B5;
    TMyLabel *lab_B3;
    TMyLabel *lab_B4;
    QLineEdit *editCmd_B2;
    TMyLabel *lab_B5;
    QLineEdit *editCmd_B4;
    TMyLabel *lab_B1;
    QLineEdit *editCmd_B6;
    TMyLabel *lab_B6;
    QLineEdit *editCmd_B3;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(847, 576);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/images/Pnp2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actCom_Open = new QAction(MainWindow);
        actCom_Open->setObjectName("actCom_Open");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/images/Pnp4.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCom_Open->setIcon(icon1);
        actCom_Close = new QAction(MainWindow);
        actCom_Close->setObjectName("actCom_Close");
        actCom_Close->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/images/712.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCom_Close->setIcon(icon2);
        actClose = new QAction(MainWindow);
        actClose->setObjectName("actClose");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon3);
        actCom_Info = new QAction(MainWindow);
        actCom_Info->setObjectName("actCom_Info");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/images/714.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCom_Info->setIcon(icon4);
        actClear = new QAction(MainWindow);
        actClear->setObjectName("actClear");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/images/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(2, 2, 2, -1);
        frame_Port = new QFrame(centralwidget);
        frame_Port->setObjectName("frame_Port");
        frame_Port->setEnabled(true);
        frame_Port->setMaximumSize(QSize(16777215, 90));
        frame_Port->setFrameShape(QFrame::Panel);
        frame_Port->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_Port);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(frame_Port);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        comboCom_Port = new QComboBox(frame_Port);
        comboCom_Port->setObjectName("comboCom_Port");
        comboCom_Port->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(comboCom_Port);

        label_2 = new QLabel(frame_Port);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        comboCom_Buad = new QComboBox(frame_Port);
        comboCom_Buad->addItem(QString());
        comboCom_Buad->addItem(QString());
        comboCom_Buad->addItem(QString());
        comboCom_Buad->addItem(QString());
        comboCom_Buad->addItem(QString());
        comboCom_Buad->addItem(QString());
        comboCom_Buad->setObjectName("comboCom_Buad");
        comboCom_Buad->setMinimumSize(QSize(90, 0));
        comboCom_Buad->setEditable(true);

        horizontalLayout_3->addWidget(comboCom_Buad);

        label_3 = new QLabel(frame_Port);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        comboCom_DataBit = new QComboBox(frame_Port);
        comboCom_DataBit->addItem(QString());
        comboCom_DataBit->addItem(QString());
        comboCom_DataBit->addItem(QString());
        comboCom_DataBit->addItem(QString());
        comboCom_DataBit->setObjectName("comboCom_DataBit");
        comboCom_DataBit->setMinimumSize(QSize(60, 0));

        horizontalLayout_3->addWidget(comboCom_DataBit);

        label_4 = new QLabel(frame_Port);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        comboCom_StopBit = new QComboBox(frame_Port);
        comboCom_StopBit->addItem(QString());
        comboCom_StopBit->addItem(QString());
        comboCom_StopBit->addItem(QString());
        comboCom_StopBit->setObjectName("comboCom_StopBit");
        comboCom_StopBit->setMinimumSize(QSize(60, 0));

        horizontalLayout_3->addWidget(comboCom_StopBit);

        label_5 = new QLabel(frame_Port);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        comboCom_Parity = new QComboBox(frame_Port);
        comboCom_Parity->addItem(QString());
        comboCom_Parity->addItem(QString());
        comboCom_Parity->addItem(QString());
        comboCom_Parity->setObjectName("comboCom_Parity");
        comboCom_Parity->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(comboCom_Parity);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(frame_Port);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter_2);
        toolBox->setObjectName("toolBox");
        toolBox->setMinimumSize(QSize(200, 0));
        toolBox->setFrameShadow(QFrame::Sunken);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 183, 463));
        verticalLayout_7 = new QVBoxLayout(page_2);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        btnWF_Test = new QPushButton(groupBox_4);
        btnWF_Test->setObjectName("btnWF_Test");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/images/332.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnWF_Test->setIcon(icon6);

        verticalLayout_8->addWidget(btnWF_Test);

        btnWF_Reset = new QPushButton(groupBox_4);
        btnWF_Reset->setObjectName("btnWF_Reset");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/images/326.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnWF_Reset->setIcon(icon7);

        verticalLayout_8->addWidget(btnWF_Reset);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setIcon(icon5);

        verticalLayout_8->addWidget(pushButton_4);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        comboWiFi_UartBuad = new QComboBox(groupBox);
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->addItem(QString());
        comboWiFi_UartBuad->setObjectName("comboWiFi_UartBuad");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboWiFi_UartBuad->sizePolicy().hasHeightForWidth());
        comboWiFi_UartBuad->setSizePolicy(sizePolicy);
        comboWiFi_UartBuad->setEditable(true);

        horizontalLayout_6->addWidget(comboWiFi_UartBuad);


        verticalLayout_4->addLayout(horizontalLayout_6);

        btnWF_UART_Set = new QPushButton(groupBox);
        btnWF_UART_Set->setObjectName("btnWF_UART_Set");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/images/322.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnWF_UART_Set->setIcon(icon8);

        verticalLayout_4->addWidget(btnWF_UART_Set);

        btnWF_UART_Qry = new QPushButton(groupBox);
        btnWF_UART_Qry->setObjectName("btnWF_UART_Qry");
        btnWF_UART_Qry->setIcon(icon6);

        verticalLayout_4->addWidget(btnWF_UART_Qry);


        verticalLayout_7->addWidget(groupBox);

        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        btnWF_SetAsSTA = new QPushButton(groupBox_5);
        btnWF_SetAsSTA->setObjectName("btnWF_SetAsSTA");
        btnWF_SetAsSTA->setIcon(icon8);

        verticalLayout_6->addWidget(btnWF_SetAsSTA);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        editAP_Name = new QLineEdit(groupBox_5);
        editAP_Name->setObjectName("editAP_Name");

        gridLayout_4->addWidget(editAP_Name, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        editAP_PWD = new QLineEdit(groupBox_5);
        editAP_PWD->setObjectName("editAP_PWD");

        gridLayout_4->addWidget(editAP_PWD, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);

        btnWF_SetAP = new QPushButton(groupBox_5);
        btnWF_SetAP->setObjectName("btnWF_SetAP");
        btnWF_SetAP->setIcon(icon8);

        verticalLayout_6->addWidget(btnWF_SetAP);

        btnWF_GetAP = new QPushButton(groupBox_5);
        btnWF_GetAP->setObjectName("btnWF_GetAP");
        btnWF_GetAP->setIcon(icon6);

        verticalLayout_6->addWidget(btnWF_GetAP);


        verticalLayout_7->addWidget(groupBox_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/images/110.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon9, QString::fromUtf8("WiFi\346\250\241\345\235\227AT\346\214\207\344\273\244\346\223\215\344\275\234--1"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 200, 420));
        verticalLayout_11 = new QVBoxLayout(page_3);
        verticalLayout_11->setObjectName("verticalLayout_11");
        groupBox_7 = new QGroupBox(page_3);
        groupBox_7->setObjectName("groupBox_7");
        verticalLayout_10 = new QVBoxLayout(groupBox_7);
        verticalLayout_10->setObjectName("verticalLayout_10");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName("label_9");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        editServer_IP = new QLineEdit(groupBox_7);
        editServer_IP->setObjectName("editServer_IP");

        formLayout->setWidget(0, QFormLayout::FieldRole, editServer_IP);

        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName("label_10");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        spinServer_Port = new QSpinBox(groupBox_7);
        spinServer_Port->setObjectName("spinServer_Port");
        spinServer_Port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinServer_Port->setMaximum(999999);
        spinServer_Port->setValue(1200);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinServer_Port);


        verticalLayout_10->addLayout(formLayout);

        btnTCP_SetServer = new QPushButton(groupBox_7);
        btnTCP_SetServer->setObjectName("btnTCP_SetServer");
        btnTCP_SetServer->setIcon(icon8);

        verticalLayout_10->addWidget(btnTCP_SetServer);

        btnTCP_AutoConn = new QPushButton(groupBox_7);
        btnTCP_AutoConn->setObjectName("btnTCP_AutoConn");
        btnTCP_AutoConn->setIcon(icon8);

        verticalLayout_10->addWidget(btnTCP_AutoConn);

        btnTCP_Query = new QPushButton(groupBox_7);
        btnTCP_Query->setObjectName("btnTCP_Query");
        btnTCP_Query->setIcon(icon6);

        verticalLayout_10->addWidget(btnTCP_Query);

        btnTCP_GetMac = new QPushButton(groupBox_7);
        btnTCP_GetMac->setObjectName("btnTCP_GetMac");
        btnTCP_GetMac->setIcon(icon6);

        verticalLayout_10->addWidget(btnTCP_GetMac);


        verticalLayout_11->addWidget(groupBox_7);

        groupBox_6 = new QGroupBox(page_3);
        groupBox_6->setObjectName("groupBox_6");
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setObjectName("verticalLayout_9");
        btnTrans_Exit = new QPushButton(groupBox_6);
        btnTrans_Exit->setObjectName("btnTrans_Exit");
        btnTrans_Exit->setIcon(icon8);

        verticalLayout_9->addWidget(btnTrans_Exit);

        btnTrans_Enter = new QPushButton(groupBox_6);
        btnTrans_Enter->setObjectName("btnTrans_Enter");
        btnTrans_Enter->setIcon(icon8);

        verticalLayout_9->addWidget(btnTrans_Enter);

        btnTrans_AutoOnReset = new QPushButton(groupBox_6);
        btnTrans_AutoOnReset->setObjectName("btnTrans_AutoOnReset");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/images/BeIDE.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrans_AutoOnReset->setIcon(icon10);

        verticalLayout_9->addWidget(btnTrans_AutoOnReset);


        verticalLayout_11->addWidget(groupBox_6);

        verticalSpacer_2 = new QSpacerItem(20, 143, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);

        toolBox->addItem(page_3, icon10, QString::fromUtf8("WiFi\346\250\241\345\235\227AT\346\214\207\344\273\244\346\223\215\344\275\234--2"));
        splitter_2->addWidget(toolBox);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName("verticalLayout");
        textCOM = new QPlainTextEdit(groupBox_2);
        textCOM->setObjectName("textCOM");

        verticalLayout->addWidget(textCOM);

        splitter->addWidget(groupBox_2);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 5, -1, 2);
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        chkBox_NewLine1 = new QCheckBox(frame);
        chkBox_NewLine1->setObjectName("chkBox_NewLine1");
        chkBox_NewLine1->setChecked(true);

        horizontalLayout->addWidget(chkBox_NewLine1);

        btnNormSend = new QPushButton(frame);
        btnNormSend->setObjectName("btnNormSend");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/images/828.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnNormSend->setIcon(icon11);

        horizontalLayout->addWidget(btnNormSend);

        horizontalSpacer_3 = new QSpacerItem(502, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(frame);

        plainText_Norm = new QPlainTextEdit(tab);
        plainText_Norm->setObjectName("plainText_Norm");

        verticalLayout_3->addWidget(plainText_Norm);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 5, -1, 2);
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName("frame_4");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setMaximumSize(QSize(16777215, 28));
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 2, -1, 2);
        chkBox_NewLine2 = new QCheckBox(frame_4);
        chkBox_NewLine2->setObjectName("chkBox_NewLine2");
        chkBox_NewLine2->setChecked(true);

        horizontalLayout_5->addWidget(chkBox_NewLine2);

        horizontalSpacer_4 = new QSpacerItem(655, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(frame_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_CmdA = new QFrame(tab_2);
        frame_CmdA->setObjectName("frame_CmdA");
        frame_CmdA->setFrameShape(QFrame::Box);
        frame_CmdA->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_CmdA);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setVerticalSpacing(3);
        gridLayout_2->setContentsMargins(-1, 5, -1, 5);
        editCmd_A4 = new QLineEdit(frame_CmdA);
        editCmd_A4->setObjectName("editCmd_A4");

        gridLayout_2->addWidget(editCmd_A4, 3, 0, 1, 1);

        lab_A4 = new TMyLabel(frame_CmdA);
        lab_A4->setObjectName("lab_A4");
        lab_A4->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A4, 3, 1, 1, 1);

        editCmd_A5 = new QLineEdit(frame_CmdA);
        editCmd_A5->setObjectName("editCmd_A5");

        gridLayout_2->addWidget(editCmd_A5, 4, 0, 1, 1);

        editCmd_A1 = new QLineEdit(frame_CmdA);
        editCmd_A1->setObjectName("editCmd_A1");

        gridLayout_2->addWidget(editCmd_A1, 0, 0, 1, 1);

        lab_A3 = new TMyLabel(frame_CmdA);
        lab_A3->setObjectName("lab_A3");
        lab_A3->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A3, 2, 1, 1, 1);

        lab_A5 = new TMyLabel(frame_CmdA);
        lab_A5->setObjectName("lab_A5");
        lab_A5->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A5, 4, 1, 1, 1);

        editCmd_A6 = new QLineEdit(frame_CmdA);
        editCmd_A6->setObjectName("editCmd_A6");

        gridLayout_2->addWidget(editCmd_A6, 5, 0, 1, 1);

        lab_A2 = new TMyLabel(frame_CmdA);
        lab_A2->setObjectName("lab_A2");
        lab_A2->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A2, 1, 1, 1, 1);

        editCmd_A3 = new QLineEdit(frame_CmdA);
        editCmd_A3->setObjectName("editCmd_A3");

        gridLayout_2->addWidget(editCmd_A3, 2, 0, 1, 1);

        lab_A6 = new TMyLabel(frame_CmdA);
        lab_A6->setObjectName("lab_A6");
        lab_A6->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A6, 5, 1, 1, 1);

        lab_A1 = new TMyLabel(frame_CmdA);
        lab_A1->setObjectName("lab_A1");
        lab_A1->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_2->addWidget(lab_A1, 0, 1, 1, 1);

        editCmd_A2 = new QLineEdit(frame_CmdA);
        editCmd_A2->setObjectName("editCmd_A2");

        gridLayout_2->addWidget(editCmd_A2, 1, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_CmdA);

        frame_CmdB = new QFrame(tab_2);
        frame_CmdB->setObjectName("frame_CmdB");
        frame_CmdB->setFrameShape(QFrame::Box);
        frame_CmdB->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_CmdB);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(3);
        gridLayout_3->setContentsMargins(-1, 5, -1, 5);
        editCmd_B1 = new QLineEdit(frame_CmdB);
        editCmd_B1->setObjectName("editCmd_B1");

        gridLayout_3->addWidget(editCmd_B1, 0, 0, 1, 1);

        lab_B2 = new TMyLabel(frame_CmdB);
        lab_B2->setObjectName("lab_B2");
        lab_B2->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B2, 1, 1, 1, 1);

        editCmd_B5 = new QLineEdit(frame_CmdB);
        editCmd_B5->setObjectName("editCmd_B5");

        gridLayout_3->addWidget(editCmd_B5, 4, 0, 1, 1);

        lab_B3 = new TMyLabel(frame_CmdB);
        lab_B3->setObjectName("lab_B3");
        lab_B3->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B3, 2, 1, 1, 1);

        lab_B4 = new TMyLabel(frame_CmdB);
        lab_B4->setObjectName("lab_B4");
        lab_B4->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B4, 3, 1, 1, 1);

        editCmd_B2 = new QLineEdit(frame_CmdB);
        editCmd_B2->setObjectName("editCmd_B2");

        gridLayout_3->addWidget(editCmd_B2, 1, 0, 1, 1);

        lab_B5 = new TMyLabel(frame_CmdB);
        lab_B5->setObjectName("lab_B5");
        lab_B5->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B5, 4, 1, 1, 1);

        editCmd_B4 = new QLineEdit(frame_CmdB);
        editCmd_B4->setObjectName("editCmd_B4");

        gridLayout_3->addWidget(editCmd_B4, 3, 0, 1, 1);

        lab_B1 = new TMyLabel(frame_CmdB);
        lab_B1->setObjectName("lab_B1");
        lab_B1->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B1, 0, 1, 1, 1);

        editCmd_B6 = new QLineEdit(frame_CmdB);
        editCmd_B6->setObjectName("editCmd_B6");

        gridLayout_3->addWidget(editCmd_B6, 5, 0, 1, 1);

        lab_B6 = new TMyLabel(frame_CmdB);
        lab_B6->setObjectName("lab_B6");
        lab_B6->setPixmap(QPixmap(QString::fromUtf8(":/image/images/828.bmp")));

        gridLayout_3->addWidget(lab_B6, 5, 1, 1, 1);

        editCmd_B3 = new QLineEdit(frame_CmdB);
        editCmd_B3->setObjectName("editCmd_B3");

        gridLayout_3->addWidget(editCmd_B3, 2, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_CmdB);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        splitter_2->addWidget(splitter);

        verticalLayout_5->addWidget(splitter_2);

        verticalLayout_5->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
#if QT_CONFIG(shortcut)
        lab_A4->setBuddy(editCmd_A4);
        lab_A3->setBuddy(editCmd_A3);
        lab_A5->setBuddy(editCmd_A5);
        lab_A2->setBuddy(editCmd_A2);
        lab_A6->setBuddy(editCmd_A6);
        lab_A1->setBuddy(editCmd_A1);
        lab_B2->setBuddy(editCmd_B2);
        lab_B3->setBuddy(editCmd_B3);
        lab_B4->setBuddy(editCmd_B4);
        lab_B5->setBuddy(editCmd_B5);
        lab_B1->setBuddy(editCmd_B1);
        lab_B6->setBuddy(editCmd_B6);
#endif // QT_CONFIG(shortcut)

        toolBar->addAction(actCom_Open);
        toolBar->addAction(actCom_Close);
        toolBar->addAction(actClear);
        toolBar->addSeparator();
        toolBar->addAction(actClose);

        retranslateUi(MainWindow);
        QObject::connect(actClose, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        comboCom_Buad->setCurrentIndex(3);
        comboCom_DataBit->setCurrentIndex(3);
        toolBox->setCurrentIndex(0);
        comboWiFi_UartBuad->setCurrentIndex(3);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QSerialPort\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        actCom_Open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        actCom_Open->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actCom_Close->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        actCom_Close->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actClose->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actClose->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        actCom_Info->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actCom_Info->setToolTip(QCoreApplication::translate("MainWindow", "\346\234\254\347\263\273\347\273\237\347\232\204\344\270\262\345\217\243\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        actClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\346\216\245\346\224\266\346\226\207\346\234\254\346\241\206", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actClear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboCom_Buad->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboCom_Buad->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboCom_Buad->setItemText(2, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboCom_Buad->setItemText(3, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboCom_Buad->setItemText(4, QCoreApplication::translate("MainWindow", "256000", nullptr));
        comboCom_Buad->setItemText(5, QCoreApplication::translate("MainWindow", "460800", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboCom_DataBit->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboCom_DataBit->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboCom_DataBit->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboCom_DataBit->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboCom_StopBit->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboCom_StopBit->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboCom_StopBit->setItemText(2, QCoreApplication::translate("MainWindow", "1.5", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboCom_Parity->setItemText(0, QCoreApplication::translate("MainWindow", "NoParity", nullptr));
        comboCom_Parity->setItemText(1, QCoreApplication::translate("MainWindow", "EvenParity", nullptr));
        comboCom_Parity->setItemText(2, QCoreApplication::translate("MainWindow", "OddParity", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\345\235\227\345\237\272\346\234\254\346\223\215\344\275\234", nullptr));
#if QT_CONFIG(tooltip)
        btnWF_Test->setToolTip(QCoreApplication::translate("MainWindow", "AT+RST", nullptr));
#endif // QT_CONFIG(tooltip)
        btnWF_Test->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\235\227\346\265\213\350\257\225", nullptr));
#if QT_CONFIG(tooltip)
        btnWF_Reset->setToolTip(QCoreApplication::translate("MainWindow", "AT+RST", nullptr));
#endif // QT_CONFIG(tooltip)
        btnWF_Reset->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\235\227\351\207\215\345\220\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", " \346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "WiFi\344\270\262\345\217\243\345\217\202\346\225\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboWiFi_UartBuad->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboWiFi_UartBuad->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboWiFi_UartBuad->setItemText(2, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboWiFi_UartBuad->setItemText(3, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboWiFi_UartBuad->setItemText(4, QCoreApplication::translate("MainWindow", "256000", nullptr));
        comboWiFi_UartBuad->setItemText(5, QCoreApplication::translate("MainWindow", "460800", nullptr));

        btnWF_UART_Set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256UART\345\217\202\346\225\260", nullptr));
        btnWF_UART_Qry->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242UART\345\217\202\346\225\260", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
        btnWF_SetAsSTA->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\272STA", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\345\220\215\347\247\260", nullptr));
        editAP_Name->setText(QCoreApplication::translate("MainWindow", "CU_5NPf", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\257\206  \347\240\201", nullptr));
        editAP_PWD->setText(QCoreApplication::translate("MainWindow", "t2wbr5ns", nullptr));
        btnWF_SetAP->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\267\257\347\224\261\345\231\250", nullptr));
        btnWF_GetAP->setText(QCoreApplication::translate("MainWindow", " \346\237\245\350\257\242\350\267\257\347\224\261\345\231\250\345\217\202\346\225\260", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "WiFi\346\250\241\345\235\227AT\346\214\207\344\273\244\346\223\215\344\275\234--1", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "TCP\346\234\215\345\212\241\345\231\250\345\217\202\346\225\260", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "IP\345\234\260\345\235\200", nullptr));
        editServer_IP->setText(QCoreApplication::translate("MainWindow", "192.168.1.13", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", " \347\253\257\345\217\243", nullptr));
        btnTCP_SetServer->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\234\215\345\212\241\345\231\250\345\217\202\346\225\260", nullptr));
        btnTCP_AutoConn->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\220\257\345\220\216\350\207\252\345\212\250\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        btnTCP_Query->setText(QCoreApplication::translate("MainWindow", " \346\237\245\350\257\242\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        btnTCP_GetMac->setText(QCoreApplication::translate("MainWindow", " \346\237\245\350\257\242MAC\345\222\214IP\345\234\260\345\235\200", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\351\200\217\344\274\240", nullptr));
        btnTrans_Exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\351\200\217\344\274\240\346\250\241\345\274\217", nullptr));
        btnTrans_Enter->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\351\200\217\344\274\240\346\250\241\345\274\217", nullptr));
        btnTrans_AutoOnReset->setText(QCoreApplication::translate("MainWindow", "\345\274\200\346\234\272\350\207\252\345\212\250\350\277\236\346\216\245\345\222\214\351\200\217\344\274\240", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "WiFi\346\250\241\345\235\227AT\346\214\207\344\273\244\346\223\215\344\275\234--2", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        textCOM->setPlainText(QCoreApplication::translate("MainWindow", "\345\246\202\346\236\234\345\217\221\351\200\201AT\346\214\207\344\273\244\346\227\266\357\274\214WiFi\346\250\241\345\235\227\346\227\240\344\273\273\344\275\225\345\223\215\345\272\224\357\274\214\345\217\257\350\203\275\346\230\257\345\233\240\344\270\272WiFi\346\250\241\345\235\227\345\244\204\344\272\216\351\200\217\344\274\240\346\250\241\345\274\217\343\200\202\350\277\231\346\227\266\357\274\214\351\234\200\350\246\201\345\205\210\351\200\200\345\207\272\351\200\217\344\274\240\346\250\241\345\274\217\357\274\214\345\206\215\346\265\213\350\257\225AT\346\214\207\344\273\244", nullptr));
        chkBox_NewLine1->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\236\350\275\246\346\215\242\350\241\214", nullptr));
        btnNormSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        plainText_Norm->setPlainText(QCoreApplication::translate("MainWindow", "hello", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\351\200\232\347\224\250\345\217\221\351\200\201", nullptr));
        chkBox_NewLine2->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\236\350\275\246\346\215\242\350\241\214", nullptr));
        editCmd_A4->setText(QCoreApplication::translate("MainWindow", "AT+CWJAP?", nullptr));
        lab_A4->setText(QString());
        editCmd_A5->setText(QCoreApplication::translate("MainWindow", "AT+CIFSR", nullptr));
        editCmd_A1->setText(QCoreApplication::translate("MainWindow", "AT+CIPMODE?", nullptr));
        lab_A3->setText(QString());
        lab_A5->setText(QString());
        editCmd_A6->setText(QCoreApplication::translate("MainWindow", "AT+CIPSTATUS", nullptr));
        lab_A2->setText(QString());
        editCmd_A3->setText(QCoreApplication::translate("MainWindow", "AT+CWMODE?", nullptr));
        lab_A6->setText(QString());
        lab_A1->setText(QString());
        editCmd_A2->setText(QCoreApplication::translate("MainWindow", "AT+UART?", nullptr));
        editCmd_B1->setText(QCoreApplication::translate("MainWindow", "AT+CIPMODE=0", nullptr));
        lab_B2->setText(QString());
        editCmd_B5->setText(QCoreApplication::translate("MainWindow", "AT+CIPSTART=\"TCP\",\"192.168.1.13\",8080", nullptr));
        lab_B3->setText(QString());
        lab_B4->setText(QString());
        editCmd_B2->setText(QCoreApplication::translate("MainWindow", "AT+UART=115200,8,1,0,0", nullptr));
        lab_B5->setText(QString());
        editCmd_B4->setText(QCoreApplication::translate("MainWindow", "AT+CWJAP=\"CU_5NPf\",\"t2wbr5ns\"", nullptr));
        lab_B1->setText(QString());
        editCmd_B6->setText(QCoreApplication::translate("MainWindow", "AT+SAVETRANSLINK=1,\"192.168.1.13\",8080,\"TCP\"", nullptr));
        lab_B6->setText(QString());
        editCmd_B3->setText(QCoreApplication::translate("MainWindow", "AT+CWMODE=1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250AT\346\214\207\344\273\244", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
