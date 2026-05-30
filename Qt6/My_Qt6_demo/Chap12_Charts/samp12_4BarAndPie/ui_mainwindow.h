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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <tchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_13;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolBtn_GenData;
    QToolButton *toolBtn_Counting;
    QLabel *label_7;
    QComboBox *comboTheme;
    QLabel *label_8;
    QComboBox *comboAnimation;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolBtn_Quit;
    QSplitter *splitter_2;
    QFrame *frameData;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSpinBox *spinCount;
    QSpacerItem *horizontalSpacer_6;
    QTableView *tableView;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBuildBarChart;
    QPushButton *btnBuildBarChartH;
    QSpacerItem *horizontalSpacer_2;
    TChartView *chartViewBar;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnBuildStackedBar;
    QPushButton *btnBuildStackedBarH;
    QSpacerItem *horizontalSpacer_3;
    TChartView *chartViewStackedBar;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnPercentBar;
    QPushButton *btnPercentBarH;
    QSpacerItem *horizontalSpacer_4;
    TChartView *chartViewPercentBar;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboCourse;
    QPushButton *btnDrawPieChart;
    QLabel *label_2;
    QDoubleSpinBox *spinHoleSize;
    QLabel *label_3;
    QDoubleSpinBox *spinPieSize;
    QCheckBox *chkBox_PieLegend;
    QSpacerItem *horizontalSpacer;
    TChartView *chartViewPie;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 543);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_13 = new QVBoxLayout(centralWidget);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(2, 2, 2, 2);
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMaximumSize(QSize(16777215, 40));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 5, -1, 5);
        toolBtn_GenData = new QToolButton(frame_6);
        toolBtn_GenData->setObjectName(QString::fromUtf8("toolBtn_GenData"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/828.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtn_GenData->setIcon(icon);
        toolBtn_GenData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(toolBtn_GenData);

        toolBtn_Counting = new QToolButton(frame_6);
        toolBtn_Counting->setObjectName(QString::fromUtf8("toolBtn_Counting"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/216.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtn_Counting->setIcon(icon1);
        toolBtn_Counting->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(toolBtn_Counting);

        label_7 = new QLabel(frame_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        comboTheme = new QComboBox(frame_6);
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->setObjectName(QString::fromUtf8("comboTheme"));
        comboTheme->setMinimumSize(QSize(120, 0));

        horizontalLayout_7->addWidget(comboTheme);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        comboAnimation = new QComboBox(frame_6);
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->setObjectName(QString::fromUtf8("comboAnimation"));

        horizontalLayout_7->addWidget(comboAnimation);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        toolBtn_Quit = new QToolButton(frame_6);
        toolBtn_Quit->setObjectName(QString::fromUtf8("toolBtn_Quit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtn_Quit->setIcon(icon2);
        toolBtn_Quit->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(toolBtn_Quit);


        verticalLayout_13->addWidget(frame_6);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frameData = new QFrame(splitter_2);
        frameData->setObjectName(QString::fromUtf8("frameData"));
        frameData->setFrameShape(QFrame::Panel);
        frameData->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameData);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        splitter = new QSplitter(frameData);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 2, -1, 2);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_5);

        spinCount = new QSpinBox(frame_2);
        spinCount->setObjectName(QString::fromUtf8("spinCount"));
        spinCount->setMinimum(2);
        spinCount->setMaximum(5000);
        spinCount->setValue(10);

        horizontalLayout_6->addWidget(spinCount);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(frame_2);

        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setDefaultSectionSize(80);
        tableView->verticalHeader()->setDefaultSectionSize(27);

        verticalLayout->addWidget(tableView);

        splitter->addWidget(groupBox);
        groupBox_7 = new QGroupBox(splitter);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_2 = new QVBoxLayout(groupBox_7);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        treeWidget = new QTreeWidget(groupBox_7);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignCenter);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(0, Qt::AlignCenter);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setTextAlignment(0, Qt::AlignCenter);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem4->setTextAlignment(0, Qt::AlignCenter);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(16777215, 300));
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setIndentation(0);
        treeWidget->header()->setDefaultSectionSize(90);

        verticalLayout_2->addWidget(treeWidget);

        splitter->addWidget(groupBox_7);

        verticalLayout_3->addWidget(splitter);

        splitter_2->addWidget(frameData);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_9 = new QVBoxLayout(tab);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        btnBuildBarChart = new QPushButton(frame);
        btnBuildBarChart->setObjectName(QString::fromUtf8("btnBuildBarChart"));

        horizontalLayout->addWidget(btnBuildBarChart);

        btnBuildBarChartH = new QPushButton(frame);
        btnBuildBarChartH->setObjectName(QString::fromUtf8("btnBuildBarChartH"));

        horizontalLayout->addWidget(btnBuildBarChartH);

        horizontalSpacer_2 = new QSpacerItem(662, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_8->addWidget(frame);

        chartViewBar = new TChartView(widget);
        chartViewBar->setObjectName(QString::fromUtf8("chartViewBar"));
        chartViewBar->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

        verticalLayout_8->addWidget(chartViewBar);


        verticalLayout_9->addWidget(widget);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_10 = new QVBoxLayout(tab_3);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(2, 2, 2, 2);
        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(widget_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 5, -1, 5);
        btnBuildStackedBar = new QPushButton(frame_3);
        btnBuildStackedBar->setObjectName(QString::fromUtf8("btnBuildStackedBar"));

        horizontalLayout_3->addWidget(btnBuildStackedBar);

        btnBuildStackedBarH = new QPushButton(frame_3);
        btnBuildStackedBarH->setObjectName(QString::fromUtf8("btnBuildStackedBarH"));

        horizontalLayout_3->addWidget(btnBuildStackedBarH);

        horizontalSpacer_3 = new QSpacerItem(536, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_5->addWidget(frame_3);

        chartViewStackedBar = new TChartView(widget_2);
        chartViewStackedBar->setObjectName(QString::fromUtf8("chartViewStackedBar"));

        verticalLayout_5->addWidget(chartViewStackedBar);


        verticalLayout_10->addWidget(widget_2);

        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/281.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_12 = new QVBoxLayout(tab_5);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(2, 2, 2, 2);
        widget_4 = new QWidget(tab_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(widget_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(12);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 5, -1, 5);
        btnPercentBar = new QPushButton(frame_5);
        btnPercentBar->setObjectName(QString::fromUtf8("btnPercentBar"));

        horizontalLayout_4->addWidget(btnPercentBar);

        btnPercentBarH = new QPushButton(frame_5);
        btnPercentBarH->setObjectName(QString::fromUtf8("btnPercentBarH"));

        horizontalLayout_4->addWidget(btnPercentBarH);

        horizontalSpacer_4 = new QSpacerItem(523, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_6->addWidget(frame_5);

        chartViewPercentBar = new TChartView(widget_4);
        chartViewPercentBar->setObjectName(QString::fromUtf8("chartViewPercentBar"));

        verticalLayout_6->addWidget(chartViewPercentBar);


        verticalLayout_12->addWidget(widget_4);

        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/images/f4.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_5, icon5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_11 = new QVBoxLayout(tab_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(2, 2, 2, 2);
        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(widget_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, 5);
        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        comboCourse = new QComboBox(frame_4);
        comboCourse->addItem(QString());
        comboCourse->addItem(QString());
        comboCourse->addItem(QString());
        comboCourse->setObjectName(QString::fromUtf8("comboCourse"));
        comboCourse->setMinimumSize(QSize(60, 0));

        horizontalLayout_2->addWidget(comboCourse);

        btnDrawPieChart = new QPushButton(frame_4);
        btnDrawPieChart->setObjectName(QString::fromUtf8("btnDrawPieChart"));

        horizontalLayout_2->addWidget(btnDrawPieChart);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinHoleSize = new QDoubleSpinBox(frame_4);
        spinHoleSize->setObjectName(QString::fromUtf8("spinHoleSize"));
        spinHoleSize->setMinimumSize(QSize(70, 0));
        spinHoleSize->setDecimals(2);
        spinHoleSize->setMaximum(1.000000000000000);
        spinHoleSize->setSingleStep(0.100000000000000);

        horizontalLayout_2->addWidget(spinHoleSize);

        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinPieSize = new QDoubleSpinBox(frame_4);
        spinPieSize->setObjectName(QString::fromUtf8("spinPieSize"));
        spinPieSize->setMinimumSize(QSize(70, 0));
        spinPieSize->setMaximum(1.000000000000000);
        spinPieSize->setSingleStep(0.100000000000000);
        spinPieSize->setValue(0.700000000000000);

        horizontalLayout_2->addWidget(spinPieSize);

        chkBox_PieLegend = new QCheckBox(frame_4);
        chkBox_PieLegend->setObjectName(QString::fromUtf8("chkBox_PieLegend"));
        chkBox_PieLegend->setChecked(true);

        horizontalLayout_2->addWidget(chkBox_PieLegend);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(frame_4);

        chartViewPie = new TChartView(widget_3);
        chartViewPie->setObjectName(QString::fromUtf8("chartViewPie"));

        verticalLayout_4->addWidget(chartViewPie);


        verticalLayout_11->addWidget(widget_3);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/images/43.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon6, QString());
        splitter_2->addWidget(tabWidget);

        verticalLayout_13->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(toolBtn_Quit, &QToolButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\245\274\345\233\276\345\222\214\346\237\261\347\212\266\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        toolBtn_GenData->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\347\224\237\346\210\220\346\225\260\346\215\256\345\271\266\347\273\237\350\256\241", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBtn_GenData->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\347\224\237\346\210\220\346\225\260\346\215\256", nullptr));
#if QT_CONFIG(tooltip)
        toolBtn_Counting->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\347\273\237\350\256\241", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBtn_Counting->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\347\273\237\350\256\241", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\233\276\350\241\250\344\270\273\351\242\230", nullptr));
        comboTheme->setItemText(0, QCoreApplication::translate("MainWindow", "Light", nullptr));
        comboTheme->setItemText(1, QCoreApplication::translate("MainWindow", "BlueCerulean", nullptr));
        comboTheme->setItemText(2, QCoreApplication::translate("MainWindow", "Dark", nullptr));
        comboTheme->setItemText(3, QCoreApplication::translate("MainWindow", "BrownSand", nullptr));
        comboTheme->setItemText(4, QCoreApplication::translate("MainWindow", "BlueNcs", nullptr));
        comboTheme->setItemText(5, QCoreApplication::translate("MainWindow", "HighContrast", nullptr));
        comboTheme->setItemText(6, QCoreApplication::translate("MainWindow", "BlueIcy", nullptr));
        comboTheme->setItemText(7, QCoreApplication::translate("MainWindow", "Qt", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "\345\233\276\350\241\250\345\212\250\347\224\273\346\225\210\346\236\234", nullptr));
        comboAnimation->setItemText(0, QCoreApplication::translate("MainWindow", "NoAnimation", nullptr));
        comboAnimation->setItemText(1, QCoreApplication::translate("MainWindow", "GridAxisAnimations", nullptr));
        comboAnimation->setItemText(2, QCoreApplication::translate("MainWindow", "SeriesAnimations", nullptr));
        comboAnimation->setItemText(3, QCoreApplication::translate("MainWindow", "AllAnimations", nullptr));

        toolBtn_Quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\345\210\206\346\225\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\344\272\272\346\225\260", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\344\272\272\346\225\260\347\273\237\350\256\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "\350\213\261\350\257\255", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\350\257\255\346\226\207", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\346\225\260\345\255\246", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260\346\256\265", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "60\345\210\206\344\273\245\344\270\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "60-69\345\210\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "70-79\345\210\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "80-89\345\210\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "90\345\210\206\344\273\245\344\270\212", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        btnBuildBarChart->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\346\237\261\347\212\266\345\233\276", nullptr));
        btnBuildBarChartH->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\346\260\264\345\271\263\346\237\261\347\212\266\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "BarChart", nullptr));
        btnBuildStackedBar->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\345\240\206\345\217\240\346\237\261\347\212\266\345\233\276", nullptr));
        btnBuildStackedBarH->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\346\260\264\345\271\263\345\240\206\345\217\240\346\237\261\347\212\266\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "StackedBar", nullptr));
        btnPercentBar->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\347\231\276\345\210\206\346\257\224\346\237\261\347\212\266\345\233\276", nullptr));
        btnPercentBarH->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\346\260\264\345\271\263\347\231\276\345\210\206\346\257\224\346\237\261\347\212\266\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "PercentBar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\236\220\346\225\260\346\215\256", nullptr));
        comboCourse->setItemText(0, QCoreApplication::translate("MainWindow", "\346\225\260\345\255\246", nullptr));
        comboCourse->setItemText(1, QCoreApplication::translate("MainWindow", "\350\257\255\346\226\207", nullptr));
        comboCourse->setItemText(2, QCoreApplication::translate("MainWindow", "\350\213\261\350\257\255", nullptr));

        btnDrawPieChart->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\351\245\274\345\233\276", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "HoleSize", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PieSize", nullptr));
        chkBox_PieLegend->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\233\276\344\276\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "PieChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
