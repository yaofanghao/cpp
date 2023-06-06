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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actListIni;
    QAction *actListClear;
    QAction *actListInsert;
    QAction *actListAppend;
    QAction *actListDelete;
    QAction *actSelALL;
    QAction *actSelNone;
    QAction *actSelInvs;
    QAction *actQuit;
    QAction *actSelPopMenu;
    QWidget *centralWidget;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QToolButton *tBtnListIni;
    QToolButton *tBtnListClear;
    QToolButton *tBtnListInsert;
    QToolButton *tBtnListAppend;
    QToolButton *tBtnListDelete;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QCheckBox *chkBoxSorting;
    QToolButton *tBtnSortAsc;
    QToolButton *tBtnSortDes;
    QSpacerItem *verticalSpacer;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *tBtnClearText;
    QToolButton *tBtnAddLine;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editCutItemText;
    QCheckBox *chkBoxListEditable;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tBtnSelectItem;
    QToolButton *tBtnSelALL;
    QToolButton *tBtnSelNone;
    QToolButton *tBtnSelInvs;
    QFrame *line;
    QListWidget *listWidget;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(577, 363);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actListIni = new QAction(MainWindow);
        actListIni->setObjectName(QString::fromUtf8("actListIni"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListIni->setIcon(icon);
        actListClear = new QAction(MainWindow);
        actListClear->setObjectName(QString::fromUtf8("actListClear"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListClear->setIcon(icon1);
        actListInsert = new QAction(MainWindow);
        actListInsert->setObjectName(QString::fromUtf8("actListInsert"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/424.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListInsert->setIcon(icon2);
        actListAppend = new QAction(MainWindow);
        actListAppend->setObjectName(QString::fromUtf8("actListAppend"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/316.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListAppend->setIcon(icon3);
        actListDelete = new QAction(MainWindow);
        actListDelete->setObjectName(QString::fromUtf8("actListDelete"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/324.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListDelete->setIcon(icon4);
        actSelALL = new QAction(MainWindow);
        actSelALL->setObjectName(QString::fromUtf8("actSelALL"));
        actSelNone = new QAction(MainWindow);
        actSelNone->setObjectName(QString::fromUtf8("actSelNone"));
        actSelNone->setMenuRole(QAction::AboutRole);
        actSelInvs = new QAction(MainWindow);
        actSelInvs->setObjectName(QString::fromUtf8("actSelInvs"));
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon5);
        actSelPopMenu = new QAction(MainWindow);
        actSelPopMenu->setObjectName(QString::fromUtf8("actSelPopMenu"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/124.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSelPopMenu->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 10, 536, 266));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(150, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 181, 176));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tBtnListIni = new QToolButton(page);
        tBtnListIni->setObjectName(QString::fromUtf8("tBtnListIni"));
        tBtnListIni->setMinimumSize(QSize(120, 25));
        tBtnListIni->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListIni->setAutoRaise(true);

        gridLayout->addWidget(tBtnListIni, 0, 0, 1, 1);

        tBtnListClear = new QToolButton(page);
        tBtnListClear->setObjectName(QString::fromUtf8("tBtnListClear"));
        tBtnListClear->setMinimumSize(QSize(120, 25));
        tBtnListClear->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListClear->setAutoRaise(true);

        gridLayout->addWidget(tBtnListClear, 1, 0, 1, 1);

        tBtnListInsert = new QToolButton(page);
        tBtnListInsert->setObjectName(QString::fromUtf8("tBtnListInsert"));
        tBtnListInsert->setMinimumSize(QSize(120, 25));
        tBtnListInsert->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListInsert->setAutoRaise(true);

        gridLayout->addWidget(tBtnListInsert, 2, 0, 1, 1);

        tBtnListAppend = new QToolButton(page);
        tBtnListAppend->setObjectName(QString::fromUtf8("tBtnListAppend"));
        tBtnListAppend->setMinimumSize(QSize(120, 25));
        tBtnListAppend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListAppend->setAutoRaise(true);

        gridLayout->addWidget(tBtnListAppend, 3, 0, 1, 1);

        tBtnListDelete = new QToolButton(page);
        tBtnListDelete->setObjectName(QString::fromUtf8("tBtnListDelete"));
        tBtnListDelete->setMinimumSize(QSize(120, 25));
        tBtnListDelete->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListDelete->setAutoRaise(true);

        gridLayout->addWidget(tBtnListDelete, 4, 0, 1, 1);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons/410.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page, icon7, QString::fromUtf8("\345\210\227\350\241\250\351\241\271\346\223\215\344\275\234"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 181, 176));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(12);
        chkBoxSorting = new QCheckBox(page_2);
        chkBoxSorting->setObjectName(QString::fromUtf8("chkBoxSorting"));

        gridLayout_2->addWidget(chkBoxSorting, 0, 0, 1, 1);

        tBtnSortAsc = new QToolButton(page_2);
        tBtnSortAsc->setObjectName(QString::fromUtf8("tBtnSortAsc"));
        tBtnSortAsc->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnSortAsc->setArrowType(Qt::UpArrow);

        gridLayout_2->addWidget(tBtnSortAsc, 1, 0, 1, 1);

        tBtnSortDes = new QToolButton(page_2);
        tBtnSortDes->setObjectName(QString::fromUtf8("tBtnSortDes"));
        tBtnSortDes->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnSortDes->setArrowType(Qt::DownArrow);

        gridLayout_2->addWidget(tBtnSortDes, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons/408.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon8, QString::fromUtf8("\345\210\227\350\241\250\346\216\222\345\272\217"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 181, 176));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 2, 5, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tBtnClearText = new QToolButton(page_3);
        tBtnClearText->setObjectName(QString::fromUtf8("tBtnClearText"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtnClearText->sizePolicy().hasHeightForWidth());
        tBtnClearText->setSizePolicy(sizePolicy);
        tBtnClearText->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(tBtnClearText);

        tBtnAddLine = new QToolButton(page_3);
        tBtnAddLine->setObjectName(QString::fromUtf8("tBtnAddLine"));
        sizePolicy.setHeightForWidth(tBtnAddLine->sizePolicy().hasHeightForWidth());
        tBtnAddLine->setSizePolicy(sizePolicy);
        tBtnAddLine->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(tBtnAddLine);


        verticalLayout_2->addLayout(horizontalLayout_3);

        plainTextEdit = new QPlainTextEdit(page_3);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/icons/412.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon9, QString::fromUtf8("\344\277\241\345\217\267\345\217\221\345\260\204\346\227\266\346\234\272"));
        splitter->addWidget(toolBox);
        groupBox_5 = new QGroupBox(splitter);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        editCutItemText = new QLineEdit(groupBox_5);
        editCutItemText->setObjectName(QString::fromUtf8("editCutItemText"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 255, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        editCutItemText->setPalette(palette);
        editCutItemText->setStyleSheet(QString::fromUtf8(""));
        editCutItemText->setClearButtonEnabled(false);

        horizontalLayout->addWidget(editCutItemText);

        chkBoxListEditable = new QCheckBox(groupBox_5);
        chkBoxListEditable->setObjectName(QString::fromUtf8("chkBoxListEditable"));
        chkBoxListEditable->setChecked(true);

        horizontalLayout->addWidget(chkBoxListEditable);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tBtnSelectItem = new QToolButton(groupBox_5);
        tBtnSelectItem->setObjectName(QString::fromUtf8("tBtnSelectItem"));
        tBtnSelectItem->setMinimumSize(QSize(100, 25));
        tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
        tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSelectItem);

        tBtnSelALL = new QToolButton(groupBox_5);
        tBtnSelALL->setObjectName(QString::fromUtf8("tBtnSelALL"));
        tBtnSelALL->setMinimumSize(QSize(70, 25));

        horizontalLayout_2->addWidget(tBtnSelALL);

        tBtnSelNone = new QToolButton(groupBox_5);
        tBtnSelNone->setObjectName(QString::fromUtf8("tBtnSelNone"));
        tBtnSelNone->setMinimumSize(QSize(70, 25));
        tBtnSelNone->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(tBtnSelNone);

        tBtnSelInvs = new QToolButton(groupBox_5);
        tBtnSelInvs->setObjectName(QString::fromUtf8("tBtnSelInvs"));
        tBtnSelInvs->setMinimumSize(QSize(70, 25));

        horizontalLayout_2->addWidget(tBtnSelInvs);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(groupBox_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        listWidget = new QListWidget(groupBox_5);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons/check2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        __qlistwidgetitem->setIcon(icon10);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        __qlistwidgetitem1->setIcon(icon10);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setSelectionRectVisible(false);

        verticalLayout->addWidget(listWidget);

        splitter->addWidget(groupBox_5);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actListIni);
        mainToolBar->addAction(actListClear);
        mainToolBar->addAction(actListInsert);
        mainToolBar->addAction(actListAppend);
        mainToolBar->addAction(actListDelete);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(actSelPopMenu, &QAction::triggered, actSelInvs, qOverload<>(&QAction::trigger));

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QListWidget\347\232\204\344\275\277\347\224\250", nullptr));
        actListIni->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
#if QT_CONFIG(tooltip)
        actListIni->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actListIni->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actListClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
#if QT_CONFIG(tooltip)
        actListClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        actListInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
#if QT_CONFIG(tooltip)
        actListInsert->setToolTip(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actListInsert->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actListAppend->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
#if QT_CONFIG(tooltip)
        actListAppend->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actListAppend->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actListDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
#if QT_CONFIG(tooltip)
        actListDelete->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actListDelete->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actSelALL->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(tooltip)
        actSelALL->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#endif // QT_CONFIG(tooltip)
        actSelNone->setText(QCoreApplication::translate("MainWindow", "\347\251\272\351\200\211", nullptr));
#if QT_CONFIG(tooltip)
        actSelNone->setToolTip(QCoreApplication::translate("MainWindow", "\347\251\272\351\200\211", nullptr));
#endif // QT_CONFIG(tooltip)
        actSelInvs->setText(QCoreApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));
#if QT_CONFIG(tooltip)
        actSelInvs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actSelPopMenu->setText(QCoreApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", nullptr));
#if QT_CONFIG(tooltip)
        actSelPopMenu->setToolTip(QCoreApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", nullptr));
#endif // QT_CONFIG(tooltip)
        tBtnListIni->setText(QCoreApplication::translate("MainWindow", "tBtnListIni", nullptr));
        tBtnListClear->setText(QCoreApplication::translate("MainWindow", "tBtnListClear", nullptr));
        tBtnListInsert->setText(QCoreApplication::translate("MainWindow", "tBtnListInsert", nullptr));
        tBtnListAppend->setText(QCoreApplication::translate("MainWindow", "tBtnListAppend", nullptr));
        tBtnListDelete->setText(QCoreApplication::translate("MainWindow", "tBtnListDelete", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\345\210\227\350\241\250\351\241\271\346\223\215\344\275\234", nullptr));
        chkBoxSorting->setText(QCoreApplication::translate("MainWindow", "\345\205\201\350\256\270\346\216\222\345\272\217", nullptr));
        tBtnSortAsc->setText(QCoreApplication::translate("MainWindow", "\345\215\207\345\272\217\346\216\222\345\272\217", nullptr));
        tBtnSortDes->setText(QCoreApplication::translate("MainWindow", "\351\231\215\345\272\217\346\216\222\345\272\217", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\345\210\227\350\241\250\346\216\222\345\272\217", nullptr));
        tBtnClearText->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        tBtnAddLine->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\251\272\350\241\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "\344\277\241\345\217\267\345\217\221\345\260\204\346\227\266\346\234\272", nullptr));
        groupBox_5->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\241\271\345\217\230\345\214\226", nullptr));
        editCutItemText->setText(QString());
        chkBoxListEditable->setText(QCoreApplication::translate("MainWindow", "\351\241\271\345\217\257\347\274\226\350\276\221", nullptr));
        tBtnSelectItem->setText(QCoreApplication::translate("MainWindow", "tBtnSelectItem", nullptr));
        tBtnSelALL->setText(QCoreApplication::translate("MainWindow", "tBtnSelALL", nullptr));
        tBtnSelNone->setText(QCoreApplication::translate("MainWindow", "tBtnSelNone", nullptr));
        tBtnSelInvs->setText(QCoreApplication::translate("MainWindow", "tBtnSelInvs", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "New Item2", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
