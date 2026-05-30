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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actSetRoot;
    QAction *actQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitterMain;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioShowAll;
    QRadioButton *radioShowOnlyDir;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBoxFilter;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkBoxEnableFilter;
    QComboBox *comboFilters;
    QToolButton *btnApplyFilters;
    QSpacerItem *horizontalSpacer;
    QTreeView *treeView;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labFileName;
    QLabel *labFileSize;
    QLabel *labType;
    QCheckBox *chkIsDir;
    QFrame *line;
    QLabel *labPath;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(783, 482);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actSetRoot = new QAction(MainWindow);
        actSetRoot->setObjectName(QString::fromUtf8("actSetRoot"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/fold.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSetRoot->setIcon(icon);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        splitterMain = new QSplitter(centralWidget);
        splitterMain->setObjectName(QString::fromUtf8("splitterMain"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitterMain->sizePolicy().hasHeightForWidth());
        splitterMain->setSizePolicy(sizePolicy);
        splitterMain->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(splitterMain);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        frame = new QFrame(groupBox_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioShowAll = new QRadioButton(frame);
        radioShowAll->setObjectName(QString::fromUtf8("radioShowAll"));
        radioShowAll->setChecked(true);

        horizontalLayout_3->addWidget(radioShowAll);

        radioShowOnlyDir = new QRadioButton(frame);
        radioShowOnlyDir->setObjectName(QString::fromUtf8("radioShowOnlyDir"));
        radioShowOnlyDir->setChecked(false);

        horizontalLayout_3->addWidget(radioShowOnlyDir);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBoxFilter = new QGroupBox(frame);
        groupBoxFilter->setObjectName(QString::fromUtf8("groupBoxFilter"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxFilter);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, 5);
        chkBoxEnableFilter = new QCheckBox(groupBoxFilter);
        chkBoxEnableFilter->setObjectName(QString::fromUtf8("chkBoxEnableFilter"));
        chkBoxEnableFilter->setChecked(false);

        horizontalLayout_2->addWidget(chkBoxEnableFilter);

        comboFilters = new QComboBox(groupBoxFilter);
        comboFilters->addItem(QString());
        comboFilters->addItem(QString());
        comboFilters->addItem(QString());
        comboFilters->addItem(QString());
        comboFilters->setObjectName(QString::fromUtf8("comboFilters"));
        comboFilters->setEnabled(false);
        comboFilters->setEditable(true);

        horizontalLayout_2->addWidget(comboFilters);

        btnApplyFilters = new QToolButton(groupBoxFilter);
        btnApplyFilters->setObjectName(QString::fromUtf8("btnApplyFilters"));
        btnApplyFilters->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/828.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnApplyFilters->setIcon(icon2);
        btnApplyFilters->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(btnApplyFilters);

        horizontalSpacer = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(groupBoxFilter);


        verticalLayout_6->addWidget(frame);

        treeView = new QTreeView(groupBox_3);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_6->addWidget(treeView);

        splitterMain->addWidget(groupBox_3);
        splitter = new QSplitter(splitterMain);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        listView = new QListView(groupBox);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setAlternatingRowColors(true);

        verticalLayout->addWidget(listView);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(tableView);

        splitter->addWidget(groupBox_2);
        splitterMain->addWidget(splitter);

        verticalLayout_5->addWidget(splitterMain);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 100));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labFileName = new QLabel(groupBox_4);
        labFileName->setObjectName(QString::fromUtf8("labFileName"));

        horizontalLayout->addWidget(labFileName);

        labFileSize = new QLabel(groupBox_4);
        labFileSize->setObjectName(QString::fromUtf8("labFileSize"));

        horizontalLayout->addWidget(labFileSize);

        labType = new QLabel(groupBox_4);
        labType->setObjectName(QString::fromUtf8("labType"));

        horizontalLayout->addWidget(labType);

        chkIsDir = new QCheckBox(groupBox_4);
        chkIsDir->setObjectName(QString::fromUtf8("chkIsDir"));

        horizontalLayout->addWidget(chkIsDir);


        verticalLayout_4->addLayout(horizontalLayout);

        line = new QFrame(groupBox_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        labPath = new QLabel(groupBox_4);
        labPath->setObjectName(QString::fromUtf8("labPath"));

        verticalLayout_4->addWidget(labPath);


        verticalLayout_5->addWidget(groupBox_4);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actSetRoot);
        toolBar->addSeparator();
        toolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\347\263\273\347\273\237Model/View", nullptr));
        actSetRoot->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\271\347\233\256\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actSetRoot->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\271\347\233\256\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "TreeView", nullptr));
        radioShowAll->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\233\256\345\275\225\345\222\214\346\226\207\344\273\266", nullptr));
        radioShowOnlyDir->setText(QCoreApplication::translate("MainWindow", "\345\217\252\346\230\276\347\244\272\347\233\256\345\275\225", nullptr));
        groupBoxFilter->setTitle(QString());
        chkBoxEnableFilter->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215\350\277\207\346\273\244", nullptr));
        comboFilters->setItemText(0, QCoreApplication::translate("MainWindow", "*.h;*.cpp;*.ui", nullptr));
        comboFilters->setItemText(1, QCoreApplication::translate("MainWindow", "*.h;*.cpp", nullptr));
        comboFilters->setItemText(2, QCoreApplication::translate("MainWindow", "*.jpg", nullptr));
        comboFilters->setItemText(3, QCoreApplication::translate("MainWindow", "*.txt", nullptr));

#if QT_CONFIG(statustip)
        btnApplyFilters->setStatusTip(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250\346\226\207\344\273\266\350\277\207\346\273\244\345\220\216\347\274\200", nullptr));
#endif // QT_CONFIG(statustip)
        btnApplyFilters->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "ListView", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "TableView", nullptr));
        groupBox_4->setTitle(QString());
        labFileName->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        labFileSize->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        labType->setText(QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\347\261\273\345\236\213\357\274\232", nullptr));
        chkIsDir->setText(QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\346\230\257\347\233\256\345\275\225", nullptr));
        labPath->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204\345\220\215\357\274\232", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
