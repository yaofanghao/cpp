/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actDraw;
    QAction *actQuit;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actZoomReset;
    QWidget *centralWidget;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QPushButton *btnTitleSetText;
    QLineEdit *editTitle;
    QPushButton *btnTitleColor;
    QPushButton *btnTitleFont;
    QGroupBox *groupBox_Legend;
    QGridLayout *gridLayout_7;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *btnLegendlabelColor;
    QPushButton *btnLegendFont;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinMarginLeft;
    QLabel *label_2;
    QSpinBox *spinMarginRight;
    QLabel *label_3;
    QSpinBox *spinMarginTop;
    QLabel *label_4;
    QSpinBox *spinMarginBottom;
    QPushButton *btnSetMargin;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_10;
    QLabel *label_6;
    QComboBox *comboAnimation;
    QComboBox *comboTheme;
    QLabel *label_8;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioSeries0;
    QRadioButton *radioSeries1;
    QGroupBox *groupBox_Series;
    QGridLayout *gridLayout_3;
    QPushButton *btnSeriesName;
    QLineEdit *editSeriesName;
    QPushButton *btnSeriesColor;
    QPushButton *btnSeriesPen;
    QCheckBox *chkkBoxUseOpenGL;
    QLabel *label_5;
    QSlider *sliderOpacity;
    QGroupBox *groupBox_Points;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *btnPointColor;
    QGroupBox *groupBox_PointLabel;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnSeriesLabColor;
    QPushButton *btnSeriesLabFont;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioSeriesLabFormat0;
    QRadioButton *radioSeriesLabFormat1;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_SelectAxis;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioAxisX;
    QRadioButton *radioAxisY;
    QGroupBox *groupBox_Axis;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *spinAxisMin;
    QLabel *label_11;
    QDoubleSpinBox *spinAxisMax;
    QPushButton *btnSetAxisRange;
    QCheckBox *chkBoxAxisReverse;
    QGroupBox *groupBox_AxisTitle;
    QGridLayout *gridLayout_2;
    QPushButton *btnAxisSetTitle;
    QLineEdit *editAxisTitle;
    QPushButton *btnAxisTitleColor;
    QPushButton *btnAxisTitleFont;
    QGroupBox *groupBox_AxisLabel;
    QGridLayout *gridLayout_6;
    QPushButton *btnAxisLabelFormat;
    QLineEdit *editAxisLabelFormat;
    QPushButton *btnAxisLabelColor;
    QPushButton *btnAxisLabelFont;
    QGroupBox *groupBox_Ticks;
    QGridLayout *gridLayout_5;
    QSpinBox *spinTick_Count;
    QDoubleSpinBox *spinTick_Anchor;
    QPushButton *btnAxisLinePen;
    QRadioButton *radioTick_Dynamic;
    QRadioButton *radioTick_Fixed;
    QPushButton *btnAxisLinePenColor;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_14;
    QDoubleSpinBox *spinTick_Intv;
    QGroupBox *groupBox_GridLine;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnGridLinePen;
    QPushButton *btnGridLineColor;
    QGroupBox *groupBox_MinorGrid;
    QGridLayout *gridLayout_8;
    QLabel *label_10;
    QSpinBox *spinMinorTickCount;
    QPushButton *btnMinorPen;
    QPushButton *btnMinorColor;
    QFrame *frame_chart;
    QVBoxLayout *verticalLayout;
    QChartView *chartView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 633);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton,QComboBox{\n"
"	min-height:22px	\n"
"}\n"
"\n"
"QSpinBox, QDoubleSpinBox{\n"
"	min-height:20px	\n"
"}\n"
""));
        actDraw = new QAction(MainWindow);
        actDraw->setObjectName(QString::fromUtf8("actDraw"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/828.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDraw->setIcon(icon);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actZoomIn = new QAction(MainWindow);
        actZoomIn->setObjectName(QString::fromUtf8("actZoomIn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/418.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon2);
        actZoomOut = new QAction(MainWindow);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/416.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon3);
        actZoomReset = new QAction(MainWindow);
        actZoomReset->setObjectName(QString::fromUtf8("actZoomReset"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/414.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomReset->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(5, 5, 701, 551));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMaximumSize(QSize(400, 16777215));
        toolBox->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 351, 461));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        scrollArea_2 = new QScrollArea(page);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 326, 496));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        btnTitleSetText = new QPushButton(groupBox);
        btnTitleSetText->setObjectName(QString::fromUtf8("btnTitleSetText"));

        gridLayout_9->addWidget(btnTitleSetText, 0, 0, 1, 1);

        editTitle = new QLineEdit(groupBox);
        editTitle->setObjectName(QString::fromUtf8("editTitle"));

        gridLayout_9->addWidget(editTitle, 0, 1, 1, 1);

        btnTitleColor = new QPushButton(groupBox);
        btnTitleColor->setObjectName(QString::fromUtf8("btnTitleColor"));

        gridLayout_9->addWidget(btnTitleColor, 1, 0, 1, 1);

        btnTitleFont = new QPushButton(groupBox);
        btnTitleFont->setObjectName(QString::fromUtf8("btnTitleFont"));

        gridLayout_9->addWidget(btnTitleFont, 1, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_Legend = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_Legend->setObjectName(QString::fromUtf8("groupBox_Legend"));
        groupBox_Legend->setCheckable(true);
        groupBox_Legend->setChecked(true);
        gridLayout_7 = new QGridLayout(groupBox_Legend);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        radioButton = new QRadioButton(groupBox_Legend);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout_7->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_Legend);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_7->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_Legend);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_7->addWidget(radioButton_3, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_Legend);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_7->addWidget(radioButton_4, 1, 1, 1, 1);

        btnLegendlabelColor = new QPushButton(groupBox_Legend);
        btnLegendlabelColor->setObjectName(QString::fromUtf8("btnLegendlabelColor"));

        gridLayout_7->addWidget(btnLegendlabelColor, 2, 0, 1, 1);

        btnLegendFont = new QPushButton(groupBox_Legend);
        btnLegendFont->setObjectName(QString::fromUtf8("btnLegendFont"));

        gridLayout_7->addWidget(btnLegendFont, 2, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_Legend);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinMarginLeft = new QSpinBox(groupBox_2);
        spinMarginLeft->setObjectName(QString::fromUtf8("spinMarginLeft"));
        spinMarginLeft->setMinimum(10);
        spinMarginLeft->setMaximum(500);

        gridLayout->addWidget(spinMarginLeft, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinMarginRight = new QSpinBox(groupBox_2);
        spinMarginRight->setObjectName(QString::fromUtf8("spinMarginRight"));
        spinMarginRight->setMinimum(10);
        spinMarginRight->setMaximum(500);

        gridLayout->addWidget(spinMarginRight, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinMarginTop = new QSpinBox(groupBox_2);
        spinMarginTop->setObjectName(QString::fromUtf8("spinMarginTop"));
        spinMarginTop->setMinimum(10);
        spinMarginTop->setMaximum(500);

        gridLayout->addWidget(spinMarginTop, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinMarginBottom = new QSpinBox(groupBox_2);
        spinMarginBottom->setObjectName(QString::fromUtf8("spinMarginBottom"));
        spinMarginBottom->setMinimum(10);
        spinMarginBottom->setMaximum(500);

        gridLayout->addWidget(spinMarginBottom, 3, 1, 1, 1);

        btnSetMargin = new QPushButton(groupBox_2);
        btnSetMargin->setObjectName(QString::fromUtf8("btnSetMargin"));

        gridLayout->addWidget(btnSetMargin, 4, 0, 1, 2);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_15 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_10 = new QGridLayout(groupBox_15);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_6 = new QLabel(groupBox_15);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_6, 0, 0, 1, 1);

        comboAnimation = new QComboBox(groupBox_15);
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->addItem(QString());
        comboAnimation->setObjectName(QString::fromUtf8("comboAnimation"));

        gridLayout_10->addWidget(comboAnimation, 0, 1, 1, 1);

        comboTheme = new QComboBox(groupBox_15);
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->addItem(QString());
        comboTheme->setObjectName(QString::fromUtf8("comboTheme"));

        gridLayout_10->addWidget(comboTheme, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_15);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_8, 1, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_15);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_5->addWidget(scrollArea_2);

        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/images/3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page, icon5, QString::fromUtf8("\345\233\276\350\241\250\350\256\276\347\275\256"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 351, 461));
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(3, 3, 3, 3);
        scrollArea_3 = new QScrollArea(page_2);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 343, 453));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox_12 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(groupBox_12);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioSeries0 = new QRadioButton(groupBox_12);
        radioSeries0->setObjectName(QString::fromUtf8("radioSeries0"));
        radioSeries0->setChecked(true);

        horizontalLayout_3->addWidget(radioSeries0);

        radioSeries1 = new QRadioButton(groupBox_12);
        radioSeries1->setObjectName(QString::fromUtf8("radioSeries1"));

        horizontalLayout_3->addWidget(radioSeries1);


        verticalLayout_9->addWidget(groupBox_12);

        groupBox_Series = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_Series->setObjectName(QString::fromUtf8("groupBox_Series"));
        groupBox_Series->setCheckable(true);
        groupBox_Series->setChecked(true);
        gridLayout_3 = new QGridLayout(groupBox_Series);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnSeriesName = new QPushButton(groupBox_Series);
        btnSeriesName->setObjectName(QString::fromUtf8("btnSeriesName"));

        gridLayout_3->addWidget(btnSeriesName, 0, 0, 1, 1);

        editSeriesName = new QLineEdit(groupBox_Series);
        editSeriesName->setObjectName(QString::fromUtf8("editSeriesName"));

        gridLayout_3->addWidget(editSeriesName, 0, 1, 1, 1);

        btnSeriesColor = new QPushButton(groupBox_Series);
        btnSeriesColor->setObjectName(QString::fromUtf8("btnSeriesColor"));

        gridLayout_3->addWidget(btnSeriesColor, 1, 0, 1, 1);

        btnSeriesPen = new QPushButton(groupBox_Series);
        btnSeriesPen->setObjectName(QString::fromUtf8("btnSeriesPen"));

        gridLayout_3->addWidget(btnSeriesPen, 1, 1, 1, 1);

        chkkBoxUseOpenGL = new QCheckBox(groupBox_Series);
        chkkBoxUseOpenGL->setObjectName(QString::fromUtf8("chkkBoxUseOpenGL"));

        gridLayout_3->addWidget(chkkBoxUseOpenGL, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_Series);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        sliderOpacity = new QSlider(groupBox_Series);
        sliderOpacity->setObjectName(QString::fromUtf8("sliderOpacity"));
        sliderOpacity->setMaximum(10);
        sliderOpacity->setPageStep(2);
        sliderOpacity->setValue(10);
        sliderOpacity->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(sliderOpacity, 3, 1, 1, 1);


        verticalLayout_9->addWidget(groupBox_Series);

        groupBox_Points = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_Points->setObjectName(QString::fromUtf8("groupBox_Points"));
        groupBox_Points->setCheckable(true);
        groupBox_Points->setChecked(true);
        horizontalLayout = new QHBoxLayout(groupBox_Points);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_12 = new QLabel(groupBox_Points);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_12);

        doubleSpinBox = new QDoubleSpinBox(groupBox_Points);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setValue(5.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);

        btnPointColor = new QPushButton(groupBox_Points);
        btnPointColor->setObjectName(QString::fromUtf8("btnPointColor"));

        horizontalLayout->addWidget(btnPointColor);


        verticalLayout_9->addWidget(groupBox_Points);

        groupBox_PointLabel = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_PointLabel->setObjectName(QString::fromUtf8("groupBox_PointLabel"));
        groupBox_PointLabel->setCheckable(true);
        groupBox_PointLabel->setChecked(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_PointLabel);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnSeriesLabColor = new QPushButton(groupBox_PointLabel);
        btnSeriesLabColor->setObjectName(QString::fromUtf8("btnSeriesLabColor"));

        horizontalLayout_4->addWidget(btnSeriesLabColor);

        btnSeriesLabFont = new QPushButton(groupBox_PointLabel);
        btnSeriesLabFont->setObjectName(QString::fromUtf8("btnSeriesLabFont"));

        horizontalLayout_4->addWidget(btnSeriesLabFont);


        verticalLayout_7->addLayout(horizontalLayout_4);

        groupBox_14 = new QGroupBox(groupBox_PointLabel);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        verticalLayout_6 = new QVBoxLayout(groupBox_14);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        radioSeriesLabFormat0 = new QRadioButton(groupBox_14);
        radioSeriesLabFormat0->setObjectName(QString::fromUtf8("radioSeriesLabFormat0"));
        radioSeriesLabFormat0->setChecked(true);

        verticalLayout_6->addWidget(radioSeriesLabFormat0);

        radioSeriesLabFormat1 = new QRadioButton(groupBox_14);
        radioSeriesLabFormat1->setObjectName(QString::fromUtf8("radioSeriesLabFormat1"));

        verticalLayout_6->addWidget(radioSeriesLabFormat1);


        verticalLayout_7->addWidget(groupBox_14);


        verticalLayout_9->addWidget(groupBox_PointLabel);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_10->addWidget(scrollArea_3);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/images/dis3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon6, QString::fromUtf8("\346\233\262\347\272\277\350\256\276\347\275\256"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 351, 461));
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 326, 702));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_SelectAxis = new QGroupBox(scrollAreaWidgetContents);
        groupBox_SelectAxis->setObjectName(QString::fromUtf8("groupBox_SelectAxis"));
        groupBox_SelectAxis->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(groupBox_SelectAxis);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, 10);
        radioAxisX = new QRadioButton(groupBox_SelectAxis);
        radioAxisX->setObjectName(QString::fromUtf8("radioAxisX"));
        radioAxisX->setChecked(true);

        horizontalLayout_2->addWidget(radioAxisX);

        radioAxisY = new QRadioButton(groupBox_SelectAxis);
        radioAxisY->setObjectName(QString::fromUtf8("radioAxisY"));
        radioAxisY->setChecked(false);

        horizontalLayout_2->addWidget(radioAxisY);


        verticalLayout_8->addWidget(groupBox_SelectAxis);

        groupBox_Axis = new QGroupBox(scrollAreaWidgetContents);
        groupBox_Axis->setObjectName(QString::fromUtf8("groupBox_Axis"));
        groupBox_Axis->setFlat(true);
        groupBox_Axis->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_Axis);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        frame = new QFrame(groupBox_Axis);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        spinAxisMin = new QDoubleSpinBox(frame);
        spinAxisMin->setObjectName(QString::fromUtf8("spinAxisMin"));
        spinAxisMin->setMinimum(-1000.000000000000000);
        spinAxisMin->setMaximum(1000.000000000000000);

        gridLayout_4->addWidget(spinAxisMin, 0, 1, 1, 1);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        spinAxisMax = new QDoubleSpinBox(frame);
        spinAxisMax->setObjectName(QString::fromUtf8("spinAxisMax"));
        spinAxisMax->setMinimum(-1000.000000000000000);
        spinAxisMax->setMaximum(1000.000000000000000);
        spinAxisMax->setValue(10.000000000000000);

        gridLayout_4->addWidget(spinAxisMax, 1, 1, 1, 1);

        btnSetAxisRange = new QPushButton(frame);
        btnSetAxisRange->setObjectName(QString::fromUtf8("btnSetAxisRange"));

        gridLayout_4->addWidget(btnSetAxisRange, 1, 2, 1, 1);

        chkBoxAxisReverse = new QCheckBox(frame);
        chkBoxAxisReverse->setObjectName(QString::fromUtf8("chkBoxAxisReverse"));

        gridLayout_4->addWidget(chkBoxAxisReverse, 0, 2, 1, 1);


        verticalLayout_2->addWidget(frame);

        groupBox_AxisTitle = new QGroupBox(groupBox_Axis);
        groupBox_AxisTitle->setObjectName(QString::fromUtf8("groupBox_AxisTitle"));
        groupBox_AxisTitle->setCheckable(true);
        gridLayout_2 = new QGridLayout(groupBox_AxisTitle);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnAxisSetTitle = new QPushButton(groupBox_AxisTitle);
        btnAxisSetTitle->setObjectName(QString::fromUtf8("btnAxisSetTitle"));

        gridLayout_2->addWidget(btnAxisSetTitle, 0, 0, 1, 1);

        editAxisTitle = new QLineEdit(groupBox_AxisTitle);
        editAxisTitle->setObjectName(QString::fromUtf8("editAxisTitle"));

        gridLayout_2->addWidget(editAxisTitle, 0, 1, 1, 1);

        btnAxisTitleColor = new QPushButton(groupBox_AxisTitle);
        btnAxisTitleColor->setObjectName(QString::fromUtf8("btnAxisTitleColor"));

        gridLayout_2->addWidget(btnAxisTitleColor, 1, 0, 1, 1);

        btnAxisTitleFont = new QPushButton(groupBox_AxisTitle);
        btnAxisTitleFont->setObjectName(QString::fromUtf8("btnAxisTitleFont"));

        gridLayout_2->addWidget(btnAxisTitleFont, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_AxisTitle);

        groupBox_AxisLabel = new QGroupBox(groupBox_Axis);
        groupBox_AxisLabel->setObjectName(QString::fromUtf8("groupBox_AxisLabel"));
        groupBox_AxisLabel->setCheckable(true);
        gridLayout_6 = new QGridLayout(groupBox_AxisLabel);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        btnAxisLabelFormat = new QPushButton(groupBox_AxisLabel);
        btnAxisLabelFormat->setObjectName(QString::fromUtf8("btnAxisLabelFormat"));

        gridLayout_6->addWidget(btnAxisLabelFormat, 0, 0, 1, 1);

        editAxisLabelFormat = new QLineEdit(groupBox_AxisLabel);
        editAxisLabelFormat->setObjectName(QString::fromUtf8("editAxisLabelFormat"));

        gridLayout_6->addWidget(editAxisLabelFormat, 0, 1, 1, 1);

        btnAxisLabelColor = new QPushButton(groupBox_AxisLabel);
        btnAxisLabelColor->setObjectName(QString::fromUtf8("btnAxisLabelColor"));

        gridLayout_6->addWidget(btnAxisLabelColor, 1, 0, 1, 1);

        btnAxisLabelFont = new QPushButton(groupBox_AxisLabel);
        btnAxisLabelFont->setObjectName(QString::fromUtf8("btnAxisLabelFont"));
        btnAxisLabelFont->setMinimumSize(QSize(0, 24));

        gridLayout_6->addWidget(btnAxisLabelFont, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_AxisLabel);

        groupBox_Ticks = new QGroupBox(groupBox_Axis);
        groupBox_Ticks->setObjectName(QString::fromUtf8("groupBox_Ticks"));
        groupBox_Ticks->setCheckable(true);
        gridLayout_5 = new QGridLayout(groupBox_Ticks);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        spinTick_Count = new QSpinBox(groupBox_Ticks);
        spinTick_Count->setObjectName(QString::fromUtf8("spinTick_Count"));
        spinTick_Count->setMinimum(1);
        spinTick_Count->setMaximum(1000);
        spinTick_Count->setValue(10);

        gridLayout_5->addWidget(spinTick_Count, 1, 1, 1, 1);

        spinTick_Anchor = new QDoubleSpinBox(groupBox_Ticks);
        spinTick_Anchor->setObjectName(QString::fromUtf8("spinTick_Anchor"));
        spinTick_Anchor->setEnabled(false);
        spinTick_Anchor->setMinimum(-1000000.000000000000000);
        spinTick_Anchor->setMaximum(1000000.000000000000000);

        gridLayout_5->addWidget(spinTick_Anchor, 2, 1, 1, 1);

        btnAxisLinePen = new QPushButton(groupBox_Ticks);
        btnAxisLinePen->setObjectName(QString::fromUtf8("btnAxisLinePen"));

        gridLayout_5->addWidget(btnAxisLinePen, 4, 0, 1, 1);

        radioTick_Dynamic = new QRadioButton(groupBox_Ticks);
        radioTick_Dynamic->setObjectName(QString::fromUtf8("radioTick_Dynamic"));
        radioTick_Dynamic->setChecked(false);

        gridLayout_5->addWidget(radioTick_Dynamic, 0, 1, 1, 1);

        radioTick_Fixed = new QRadioButton(groupBox_Ticks);
        radioTick_Fixed->setObjectName(QString::fromUtf8("radioTick_Fixed"));
        radioTick_Fixed->setChecked(true);

        gridLayout_5->addWidget(radioTick_Fixed, 0, 0, 1, 1);

        btnAxisLinePenColor = new QPushButton(groupBox_Ticks);
        btnAxisLinePenColor->setObjectName(QString::fromUtf8("btnAxisLinePenColor"));

        gridLayout_5->addWidget(btnAxisLinePenColor, 4, 1, 1, 1);

        label_13 = new QLabel(groupBox_Ticks);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_13, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_Ticks);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        label_14 = new QLabel(groupBox_Ticks);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_14, 3, 0, 1, 1);

        spinTick_Intv = new QDoubleSpinBox(groupBox_Ticks);
        spinTick_Intv->setObjectName(QString::fromUtf8("spinTick_Intv"));
        spinTick_Intv->setEnabled(false);
        spinTick_Intv->setMaximum(1000000.000000000000000);
        spinTick_Intv->setValue(1.000000000000000);

        gridLayout_5->addWidget(spinTick_Intv, 3, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_Ticks);

        groupBox_GridLine = new QGroupBox(groupBox_Axis);
        groupBox_GridLine->setObjectName(QString::fromUtf8("groupBox_GridLine"));
        groupBox_GridLine->setCheckable(true);
        horizontalLayout_5 = new QHBoxLayout(groupBox_GridLine);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnGridLinePen = new QPushButton(groupBox_GridLine);
        btnGridLinePen->setObjectName(QString::fromUtf8("btnGridLinePen"));

        horizontalLayout_5->addWidget(btnGridLinePen);

        btnGridLineColor = new QPushButton(groupBox_GridLine);
        btnGridLineColor->setObjectName(QString::fromUtf8("btnGridLineColor"));

        horizontalLayout_5->addWidget(btnGridLineColor);


        verticalLayout_2->addWidget(groupBox_GridLine);

        groupBox_MinorGrid = new QGroupBox(groupBox_Axis);
        groupBox_MinorGrid->setObjectName(QString::fromUtf8("groupBox_MinorGrid"));
        groupBox_MinorGrid->setCheckable(true);
        gridLayout_8 = new QGridLayout(groupBox_MinorGrid);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_10 = new QLabel(groupBox_MinorGrid);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_10, 0, 0, 1, 1);

        spinMinorTickCount = new QSpinBox(groupBox_MinorGrid);
        spinMinorTickCount->setObjectName(QString::fromUtf8("spinMinorTickCount"));
        spinMinorTickCount->setValue(4);

        gridLayout_8->addWidget(spinMinorTickCount, 0, 1, 1, 1);

        btnMinorPen = new QPushButton(groupBox_MinorGrid);
        btnMinorPen->setObjectName(QString::fromUtf8("btnMinorPen"));

        gridLayout_8->addWidget(btnMinorPen, 1, 0, 1, 1);

        btnMinorColor = new QPushButton(groupBox_MinorGrid);
        btnMinorColor->setObjectName(QString::fromUtf8("btnMinorColor"));

        gridLayout_8->addWidget(btnMinorColor, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_MinorGrid);


        verticalLayout_8->addWidget(groupBox_Axis);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/images/39.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon7, QString::fromUtf8("\345\235\220\346\240\207\350\275\264\350\256\276\347\275\256"));
        splitter->addWidget(toolBox);
        frame_chart = new QFrame(splitter);
        frame_chart->setObjectName(QString::fromUtf8("frame_chart"));
        frame_chart->setFrameShape(QFrame::Panel);
        frame_chart->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_chart);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        chartView = new QChartView(frame_chart);
        chartView->setObjectName(QString::fromUtf8("chartView"));

        verticalLayout->addWidget(chartView);

        splitter->addWidget(frame_chart);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actDraw);
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QChart\347\273\230\345\233\276\350\257\246\347\273\206\345\212\237\350\203\275", nullptr));
        actDraw->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\347\273\230\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        actDraw->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\347\273\230\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomIn->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomReset->setText(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomReset->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\230\345\216\237\344\270\272\345\216\237\345\247\213\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(tooltip)
        btnTitleSetText->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\207\351\242\230\346\226\207\345\255\227", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTitleSetText->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\207\351\242\230", nullptr));
        editTitle->setText(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225\345\207\275\346\225\260\346\233\262\347\272\277", nullptr));
        btnTitleColor->setText(QCoreApplication::translate("MainWindow", "\346\240\207\351\242\230\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        btnTitleFont->setText(QCoreApplication::translate("MainWindow", "\346\240\207\351\242\230\345\255\227\344\275\223", nullptr));
        groupBox_Legend->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\344\276\213", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\346\226\271", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\344\270\213\346\226\271", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\345\267\246\344\276\247", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\345\217\263\344\276\247", nullptr));
        btnLegendlabelColor->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        btnLegendFont->setText(QCoreApplication::translate("MainWindow", "\345\233\276\344\276\213\345\255\227\344\275\223", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\276\271\350\267\235", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\267\246\350\276\271\350\267\235", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\217\263\350\276\271\350\267\235", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\270\212\350\276\271\350\267\235", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\276\271\350\267\235", nullptr));
        btnSetMargin->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\276\271\350\267\235", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "\345\212\250\347\224\273\346\225\210\346\236\234\345\222\214\344\270\273\351\242\230", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\212\250\347\224\273\346\225\210\346\236\234", nullptr));
        comboAnimation->setItemText(0, QCoreApplication::translate("MainWindow", "NoAnimation", nullptr));
        comboAnimation->setItemText(1, QCoreApplication::translate("MainWindow", "GridAxisAnimations", nullptr));
        comboAnimation->setItemText(2, QCoreApplication::translate("MainWindow", "SeriesAnimations", nullptr));
        comboAnimation->setItemText(3, QCoreApplication::translate("MainWindow", "AllAnimations", nullptr));

        comboTheme->setItemText(0, QCoreApplication::translate("MainWindow", "Light", nullptr));
        comboTheme->setItemText(1, QCoreApplication::translate("MainWindow", "BlueCerulean", nullptr));
        comboTheme->setItemText(2, QCoreApplication::translate("MainWindow", "Dark", nullptr));
        comboTheme->setItemText(3, QCoreApplication::translate("MainWindow", "BrownSand", nullptr));
        comboTheme->setItemText(4, QCoreApplication::translate("MainWindow", "BlueNcs", nullptr));
        comboTheme->setItemText(5, QCoreApplication::translate("MainWindow", "HighContrast", nullptr));
        comboTheme->setItemText(6, QCoreApplication::translate("MainWindow", "BlueIcy", nullptr));
        comboTheme->setItemText(7, QCoreApplication::translate("MainWindow", "Qt", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\273  \351\242\230", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\345\233\276\350\241\250\350\256\276\347\275\256", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\223\215\344\275\234\345\272\217\345\210\227", nullptr));
        radioSeries0->setText(QCoreApplication::translate("MainWindow", "Sin\346\233\262\347\272\277", nullptr));
        radioSeries1->setText(QCoreApplication::translate("MainWindow", "Cos\346\233\262\347\272\277", nullptr));
        groupBox_Series->setTitle(QCoreApplication::translate("MainWindow", "\345\272\217\345\210\227\346\233\262\347\272\277", nullptr));
        btnSeriesName->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\210\227\345\220\215\347\247\260", nullptr));
        editSeriesName->setText(QCoreApplication::translate("MainWindow", "Sin\346\233\262\347\272\277", nullptr));
        btnSeriesColor->setText(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\351\242\234\350\211\262", nullptr));
        btnSeriesPen->setText(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277Pen", nullptr));
#if QT_CONFIG(tooltip)
        chkkBoxUseOpenGL->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250openGL\345\220\216\344\270\215\350\203\275\350\256\276\347\275\256\347\272\277\345\236\213\357\274\214\344\270\215\350\203\275\346\230\276\347\244\272\346\225\260\346\215\256\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        chkkBoxUseOpenGL->setText(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250openGL", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\200\217\346\230\216\345\272\246", nullptr));
        groupBox_Points->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\202\271", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\202\271\345\244\247\345\260\217", nullptr));
        btnPointColor->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\202\271\351\242\234\350\211\262", nullptr));
        groupBox_PointLabel->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\202\271\346\240\207\347\255\276", nullptr));
        btnSeriesLabColor->setText(QCoreApplication::translate("MainWindow", "\346\240\207\347\255\276\351\242\234\350\211\262", nullptr));
        btnSeriesLabFont->setText(QCoreApplication::translate("MainWindow", "\346\240\207\347\255\276\345\255\227\344\275\223", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\346\240\207\347\255\276\346\240\274\345\274\217", nullptr));
        radioSeriesLabFormat0->setText(QCoreApplication::translate("MainWindow", "@yPoint", nullptr));
        radioSeriesLabFormat1->setText(QCoreApplication::translate("MainWindow", "(@xPoint, @yPoint)", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\350\256\276\347\275\256", nullptr));
        groupBox_SelectAxis->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\223\215\344\275\234\347\232\204\345\235\220\346\240\207\350\275\264\345\257\271\350\261\241", nullptr));
        radioAxisX->setText(QCoreApplication::translate("MainWindow", "X\350\275\264", nullptr));
        radioAxisY->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264", nullptr));
        groupBox_Axis->setTitle(QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207\350\275\264(setVisible())", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        btnSetAxisRange->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\235\220\346\240\207\350\214\203\345\233\264", nullptr));
        chkBoxAxisReverse->setText(QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207\345\217\215\345\220\221", nullptr));
        groupBox_AxisTitle->setTitle(QCoreApplication::translate("MainWindow", "\350\275\264\346\240\207\351\242\230(setTitleVisible())", nullptr));
        btnAxisSetTitle->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\275\264\346\240\207\351\242\230", nullptr));
        editAxisTitle->setText(QCoreApplication::translate("MainWindow", "time(secs)", nullptr));
        btnAxisTitleColor->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        btnAxisTitleFont->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        groupBox_AxisLabel->setTitle(QCoreApplication::translate("MainWindow", "\350\275\264\345\210\273\345\272\246\346\240\207\347\255\276(setLabelsVisible())", nullptr));
        btnAxisLabelFormat->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\207\347\255\276\346\240\274\345\274\217", nullptr));
        editAxisLabelFormat->setText(QCoreApplication::translate("MainWindow", "%.1f", nullptr));
        btnAxisLabelColor->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        btnAxisLabelFont->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        groupBox_Ticks->setTitle(QCoreApplication::translate("MainWindow", "\350\275\264\347\272\277\345\222\214\344\270\273\345\210\273\345\272\246(setLineVisible())", nullptr));
        btnAxisLinePen->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241Pen", nullptr));
        radioTick_Dynamic->setText(QCoreApplication::translate("MainWindow", "\345\212\250\346\200\201\345\210\273\345\272\246", nullptr));
        radioTick_Fixed->setText(QCoreApplication::translate("MainWindow", "\345\233\272\345\256\232\345\210\273\345\272\246", nullptr));
        btnAxisLinePenColor->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\210\273\345\272\246\350\265\267\347\202\271\345\200\274", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tick\344\270\252\346\225\260", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\345\210\273\345\272\246\351\227\264\351\232\224\345\200\274", nullptr));
        groupBox_GridLine->setTitle(QCoreApplication::translate("MainWindow", "\344\270\273\347\275\221\346\240\274\347\272\277(setGridLineVisible())", nullptr));
        btnGridLinePen->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241Pen", nullptr));
        btnGridLineColor->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", nullptr));
        groupBox_MinorGrid->setTitle(QCoreApplication::translate("MainWindow", "\346\254\241\347\275\221\346\240\274\347\272\277(setMinorGridLineVisible())", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "MinorTick\344\270\252\346\225\260", nullptr));
        btnMinorPen->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241Pen", nullptr));
        btnMinorColor->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207\350\275\264\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
