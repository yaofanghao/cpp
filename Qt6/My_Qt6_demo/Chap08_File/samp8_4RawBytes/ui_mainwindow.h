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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actClearOutput;
    QAction *actClose;
    QAction *actSaveALL;
    QAction *actReadALL;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnFile;
    QLineEdit *editFilename;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_LittleEndian;
    QRadioButton *radio_BigEndian;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radio_Single;
    QRadioButton *radio_Double;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnInt32_Read;
    QLabel *label_5;
    QPushButton *btnUIn16_Read;
    QPushButton *btnUInt8_Read;
    QLabel *label_11;
    QPushButton *btnFloat_Read;
    QPushButton *btnUInt8_Write;
    QLineEdit *edit_Double;
    QLineEdit *edit_Int16;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *edit_Int64;
    QPushButton *btnInt64_Read;
    QSpinBox *spin_Int;
    QLineEdit *editStr_In;
    QLineEdit *editStr_Out;
    QSpinBox *spin_UInt8;
    QPushButton *btnInt_Write;
    QPushButton *btnInt32_Write;
    QPushButton *btnInt16_Read;
    QLineEdit *edit_Int;
    QLineEdit *edit_Float;
    QLabel *label_3;
    QSpinBox *spin_Int8;
    QPushButton *btnInt8_Write;
    QPushButton *btnDouble_Read;
    QPushButton *btnStr_Read2;
    QPushButton *btnInt64_Write;
    QPushButton *btnDouble_Write;
    QLineEdit *editStr_In2;
    QPushButton *btnInt16_Write;
    QPushButton *btnStr_Write;
    QLineEdit *editStr_Out2;
    QPushButton *btnBool_Read;
    QLabel *label_8;
    QDoubleSpinBox *spin_Double;
    QLabel *label_7;
    QDoubleSpinBox *spin_Float;
    QSpinBox *spin_Int64;
    QLineEdit *edit_Int8;
    QLineEdit *edit_UInt8;
    QSpinBox *spin_UInt16;
    QPushButton *btnBool_Write;
    QPushButton *btnStr_Read;
    QPushButton *btnStr_Write2;
    QLineEdit *edit_Int32;
    QLineEdit *edit_UInt16;
    QLabel *label_10;
    QLabel *label_4;
    QSpinBox *spin_Int32;
    QSpinBox *spin_Int16;
    QCheckBox *chkBox_Out;
    QLabel *label_13;
    QPushButton *btnInt8_Read;
    QPushButton *btnUInt16_Write;
    QLabel *label_12;
    QPushButton *btnInt_Read;
    QLabel *label_6;
    QCheckBox *chkBox_In;
    QPushButton *btnFloat_Write;
    QDoubleSpinBox *spin_Float16;
    QLabel *label_9;
    QPushButton *btnFloat16_Write;
    QPushButton *btnFloat16_Read;
    QLineEdit *edit_Float16;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(562, 528);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actClearOutput = new QAction(MainWindow);
        actClearOutput->setObjectName(QString::fromUtf8("actClearOutput"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/214.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClearOutput->setIcon(icon);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon1);
        actSaveALL = new QAction(MainWindow);
        actSaveALL->setObjectName(QString::fromUtf8("actSaveALL"));
        actSaveALL->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/saveall1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSaveALL->setIcon(icon2);
        actReadALL = new QAction(MainWindow);
        actReadALL->setObjectName(QString::fromUtf8("actReadALL"));
        actReadALL->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/upfold1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actReadALL->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 90));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnFile = new QToolButton(groupBox_2);
        btnFile->setObjectName(QString::fromUtf8("btnFile"));
        btnFile->setMinimumSize(QSize(0, 22));

        horizontalLayout_3->addWidget(btnFile);

        editFilename = new QLineEdit(groupBox_2);
        editFilename->setObjectName(QString::fromUtf8("editFilename"));

        horizontalLayout_3->addWidget(editFilename);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        radio_LittleEndian = new QRadioButton(groupBox_3);
        radio_LittleEndian->setObjectName(QString::fromUtf8("radio_LittleEndian"));
        radio_LittleEndian->setChecked(true);

        horizontalLayout->addWidget(radio_LittleEndian);

        radio_BigEndian = new QRadioButton(groupBox_3);
        radio_BigEndian->setObjectName(QString::fromUtf8("radio_BigEndian"));

        horizontalLayout->addWidget(radio_BigEndian);


        horizontalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, 5);
        radio_Single = new QRadioButton(groupBox_4);
        radio_Single->setObjectName(QString::fromUtf8("radio_Single"));
        radio_Single->setChecked(true);

        horizontalLayout_2->addWidget(radio_Single);

        radio_Double = new QRadioButton(groupBox_4);
        radio_Double->setObjectName(QString::fromUtf8("radio_Double"));

        horizontalLayout_2->addWidget(radio_Double);


        horizontalLayout_4->addWidget(groupBox_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(5);
        btnInt32_Read = new QPushButton(groupBox);
        btnInt32_Read->setObjectName(QString::fromUtf8("btnInt32_Read"));

        gridLayout->addWidget(btnInt32_Read, 4, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        btnUIn16_Read = new QPushButton(groupBox);
        btnUIn16_Read->setObjectName(QString::fromUtf8("btnUIn16_Read"));

        gridLayout->addWidget(btnUIn16_Read, 3, 3, 1, 1);

        btnUInt8_Read = new QPushButton(groupBox);
        btnUInt8_Read->setObjectName(QString::fromUtf8("btnUInt8_Read"));

        gridLayout->addWidget(btnUInt8_Read, 1, 3, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        btnFloat_Read = new QPushButton(groupBox);
        btnFloat_Read->setObjectName(QString::fromUtf8("btnFloat_Read"));

        gridLayout->addWidget(btnFloat_Read, 9, 3, 1, 1);

        btnUInt8_Write = new QPushButton(groupBox);
        btnUInt8_Write->setObjectName(QString::fromUtf8("btnUInt8_Write"));

        gridLayout->addWidget(btnUInt8_Write, 1, 2, 1, 1);

        edit_Double = new QLineEdit(groupBox);
        edit_Double->setObjectName(QString::fromUtf8("edit_Double"));
        edit_Double->setReadOnly(true);

        gridLayout->addWidget(edit_Double, 10, 4, 1, 1);

        edit_Int16 = new QLineEdit(groupBox);
        edit_Int16->setObjectName(QString::fromUtf8("edit_Int16"));
        edit_Int16->setReadOnly(true);

        gridLayout->addWidget(edit_Int16, 2, 4, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        edit_Int64 = new QLineEdit(groupBox);
        edit_Int64->setObjectName(QString::fromUtf8("edit_Int64"));
        edit_Int64->setReadOnly(true);

        gridLayout->addWidget(edit_Int64, 5, 4, 1, 1);

        btnInt64_Read = new QPushButton(groupBox);
        btnInt64_Read->setObjectName(QString::fromUtf8("btnInt64_Read"));

        gridLayout->addWidget(btnInt64_Read, 5, 3, 1, 1);

        spin_Int = new QSpinBox(groupBox);
        spin_Int->setObjectName(QString::fromUtf8("spin_Int"));
        spin_Int->setMinimum(-2147483647);
        spin_Int->setMaximum(2147483647);
        spin_Int->setValue(15648);

        gridLayout->addWidget(spin_Int, 6, 1, 1, 1);

        editStr_In = new QLineEdit(groupBox);
        editStr_In->setObjectName(QString::fromUtf8("editStr_In"));

        gridLayout->addWidget(editStr_In, 11, 1, 1, 1);

        editStr_Out = new QLineEdit(groupBox);
        editStr_Out->setObjectName(QString::fromUtf8("editStr_Out"));
        editStr_Out->setReadOnly(true);

        gridLayout->addWidget(editStr_Out, 11, 4, 1, 1);

        spin_UInt8 = new QSpinBox(groupBox);
        spin_UInt8->setObjectName(QString::fromUtf8("spin_UInt8"));
        spin_UInt8->setMinimum(0);
        spin_UInt8->setMaximum(255);
        spin_UInt8->setValue(216);

        gridLayout->addWidget(spin_UInt8, 1, 1, 1, 1);

        btnInt_Write = new QPushButton(groupBox);
        btnInt_Write->setObjectName(QString::fromUtf8("btnInt_Write"));

        gridLayout->addWidget(btnInt_Write, 6, 2, 1, 1);

        btnInt32_Write = new QPushButton(groupBox);
        btnInt32_Write->setObjectName(QString::fromUtf8("btnInt32_Write"));

        gridLayout->addWidget(btnInt32_Write, 4, 2, 1, 1);

        btnInt16_Read = new QPushButton(groupBox);
        btnInt16_Read->setObjectName(QString::fromUtf8("btnInt16_Read"));

        gridLayout->addWidget(btnInt16_Read, 2, 3, 1, 1);

        edit_Int = new QLineEdit(groupBox);
        edit_Int->setObjectName(QString::fromUtf8("edit_Int"));
        edit_Int->setReadOnly(true);

        gridLayout->addWidget(edit_Int, 6, 4, 1, 1);

        edit_Float = new QLineEdit(groupBox);
        edit_Float->setObjectName(QString::fromUtf8("edit_Float"));
        edit_Float->setReadOnly(true);

        gridLayout->addWidget(edit_Float, 9, 4, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 12, 0, 1, 1);

        spin_Int8 = new QSpinBox(groupBox);
        spin_Int8->setObjectName(QString::fromUtf8("spin_Int8"));
        spin_Int8->setMinimum(-128);
        spin_Int8->setMaximum(127);
        spin_Int8->setValue(123);

        gridLayout->addWidget(spin_Int8, 0, 1, 1, 1);

        btnInt8_Write = new QPushButton(groupBox);
        btnInt8_Write->setObjectName(QString::fromUtf8("btnInt8_Write"));

        gridLayout->addWidget(btnInt8_Write, 0, 2, 1, 1);

        btnDouble_Read = new QPushButton(groupBox);
        btnDouble_Read->setObjectName(QString::fromUtf8("btnDouble_Read"));

        gridLayout->addWidget(btnDouble_Read, 10, 3, 1, 1);

        btnStr_Read2 = new QPushButton(groupBox);
        btnStr_Read2->setObjectName(QString::fromUtf8("btnStr_Read2"));

        gridLayout->addWidget(btnStr_Read2, 12, 3, 1, 1);

        btnInt64_Write = new QPushButton(groupBox);
        btnInt64_Write->setObjectName(QString::fromUtf8("btnInt64_Write"));

        gridLayout->addWidget(btnInt64_Write, 5, 2, 1, 1);

        btnDouble_Write = new QPushButton(groupBox);
        btnDouble_Write->setObjectName(QString::fromUtf8("btnDouble_Write"));

        gridLayout->addWidget(btnDouble_Write, 10, 2, 1, 1);

        editStr_In2 = new QLineEdit(groupBox);
        editStr_In2->setObjectName(QString::fromUtf8("editStr_In2"));

        gridLayout->addWidget(editStr_In2, 12, 1, 1, 1);

        btnInt16_Write = new QPushButton(groupBox);
        btnInt16_Write->setObjectName(QString::fromUtf8("btnInt16_Write"));

        gridLayout->addWidget(btnInt16_Write, 2, 2, 1, 1);

        btnStr_Write = new QPushButton(groupBox);
        btnStr_Write->setObjectName(QString::fromUtf8("btnStr_Write"));

        gridLayout->addWidget(btnStr_Write, 11, 2, 1, 1);

        editStr_Out2 = new QLineEdit(groupBox);
        editStr_Out2->setObjectName(QString::fromUtf8("editStr_Out2"));

        gridLayout->addWidget(editStr_Out2, 12, 4, 1, 1);

        btnBool_Read = new QPushButton(groupBox);
        btnBool_Read->setObjectName(QString::fromUtf8("btnBool_Read"));

        gridLayout->addWidget(btnBool_Read, 7, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        spin_Double = new QDoubleSpinBox(groupBox);
        spin_Double->setObjectName(QString::fromUtf8("spin_Double"));
        spin_Double->setDecimals(4);
        spin_Double->setMinimum(-600000000.000000000000000);
        spin_Double->setMaximum(600000000.000000000000000);
        spin_Double->setValue(-458.239500000000021);

        gridLayout->addWidget(spin_Double, 10, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        spin_Float = new QDoubleSpinBox(groupBox);
        spin_Float->setObjectName(QString::fromUtf8("spin_Float"));
        spin_Float->setDecimals(4);
        spin_Float->setMinimum(-60000000.000000000000000);
        spin_Float->setMaximum(600000000.000000000000000);
        spin_Float->setValue(4531.265800000000127);

        gridLayout->addWidget(spin_Float, 9, 1, 1, 1);

        spin_Int64 = new QSpinBox(groupBox);
        spin_Int64->setObjectName(QString::fromUtf8("spin_Int64"));
        spin_Int64->setMinimum(-2147483647);
        spin_Int64->setMaximum(2147483647);
        spin_Int64->setValue(65984325);

        gridLayout->addWidget(spin_Int64, 5, 1, 1, 1);

        edit_Int8 = new QLineEdit(groupBox);
        edit_Int8->setObjectName(QString::fromUtf8("edit_Int8"));
        edit_Int8->setReadOnly(true);

        gridLayout->addWidget(edit_Int8, 0, 4, 1, 1);

        edit_UInt8 = new QLineEdit(groupBox);
        edit_UInt8->setObjectName(QString::fromUtf8("edit_UInt8"));
        edit_UInt8->setReadOnly(true);

        gridLayout->addWidget(edit_UInt8, 1, 4, 1, 1);

        spin_UInt16 = new QSpinBox(groupBox);
        spin_UInt16->setObjectName(QString::fromUtf8("spin_UInt16"));
        spin_UInt16->setMinimum(0);
        spin_UInt16->setMaximum(65535);
        spin_UInt16->setValue(56412);

        gridLayout->addWidget(spin_UInt16, 3, 1, 1, 1);

        btnBool_Write = new QPushButton(groupBox);
        btnBool_Write->setObjectName(QString::fromUtf8("btnBool_Write"));

        gridLayout->addWidget(btnBool_Write, 7, 2, 1, 1);

        btnStr_Read = new QPushButton(groupBox);
        btnStr_Read->setObjectName(QString::fromUtf8("btnStr_Read"));

        gridLayout->addWidget(btnStr_Read, 11, 3, 1, 1);

        btnStr_Write2 = new QPushButton(groupBox);
        btnStr_Write2->setObjectName(QString::fromUtf8("btnStr_Write2"));

        gridLayout->addWidget(btnStr_Write2, 12, 2, 1, 1);

        edit_Int32 = new QLineEdit(groupBox);
        edit_Int32->setObjectName(QString::fromUtf8("edit_Int32"));
        edit_Int32->setReadOnly(true);

        gridLayout->addWidget(edit_Int32, 4, 4, 1, 1);

        edit_UInt16 = new QLineEdit(groupBox);
        edit_UInt16->setObjectName(QString::fromUtf8("edit_UInt16"));
        edit_UInt16->setReadOnly(true);

        gridLayout->addWidget(edit_UInt16, 3, 4, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        spin_Int32 = new QSpinBox(groupBox);
        spin_Int32->setObjectName(QString::fromUtf8("spin_Int32"));
        spin_Int32->setMinimum(-2147483647);
        spin_Int32->setMaximum(2147483647);
        spin_Int32->setValue(-89562);

        gridLayout->addWidget(spin_Int32, 4, 1, 1, 1);

        spin_Int16 = new QSpinBox(groupBox);
        spin_Int16->setObjectName(QString::fromUtf8("spin_Int16"));
        spin_Int16->setMinimum(-32768);
        spin_Int16->setMaximum(32767);
        spin_Int16->setValue(-8412);

        gridLayout->addWidget(spin_Int16, 2, 1, 1, 1);

        chkBox_Out = new QCheckBox(groupBox);
        chkBox_Out->setObjectName(QString::fromUtf8("chkBox_Out"));

        gridLayout->addWidget(chkBox_Out, 7, 4, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 11, 0, 1, 1);

        btnInt8_Read = new QPushButton(groupBox);
        btnInt8_Read->setObjectName(QString::fromUtf8("btnInt8_Read"));

        gridLayout->addWidget(btnInt8_Read, 0, 3, 1, 1);

        btnUInt16_Write = new QPushButton(groupBox);
        btnUInt16_Write->setObjectName(QString::fromUtf8("btnUInt16_Write"));

        gridLayout->addWidget(btnUInt16_Write, 3, 2, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 10, 0, 1, 1);

        btnInt_Read = new QPushButton(groupBox);
        btnInt_Read->setObjectName(QString::fromUtf8("btnInt_Read"));

        gridLayout->addWidget(btnInt_Read, 6, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        chkBox_In = new QCheckBox(groupBox);
        chkBox_In->setObjectName(QString::fromUtf8("chkBox_In"));

        gridLayout->addWidget(chkBox_In, 7, 1, 1, 1);

        btnFloat_Write = new QPushButton(groupBox);
        btnFloat_Write->setObjectName(QString::fromUtf8("btnFloat_Write"));

        gridLayout->addWidget(btnFloat_Write, 9, 2, 1, 1);

        spin_Float16 = new QDoubleSpinBox(groupBox);
        spin_Float16->setObjectName(QString::fromUtf8("spin_Float16"));
        spin_Float16->setMinimum(-5000.000000000000000);
        spin_Float16->setMaximum(5000.000000000000000);
        spin_Float16->setValue(365.449999999999989);

        gridLayout->addWidget(spin_Float16, 8, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        btnFloat16_Write = new QPushButton(groupBox);
        btnFloat16_Write->setObjectName(QString::fromUtf8("btnFloat16_Write"));

        gridLayout->addWidget(btnFloat16_Write, 8, 2, 1, 1);

        btnFloat16_Read = new QPushButton(groupBox);
        btnFloat16_Read->setObjectName(QString::fromUtf8("btnFloat16_Read"));

        gridLayout->addWidget(btnFloat16_Read, 8, 3, 1, 1);

        edit_Float16 = new QLineEdit(groupBox);
        edit_Float16->setObjectName(QString::fromUtf8("edit_Float16"));

        gridLayout->addWidget(edit_Float16, 8, 4, 1, 1);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actClearOutput);
        toolBar->addAction(actSaveALL);
        toolBar->addAction(actReadALL);
        toolBar->addSeparator();
        toolBar->addAction(actClose);

        retranslateUi(MainWindow);
        QObject::connect(actClose, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\346\225\260\346\215\256\350\257\273\345\206\231", nullptr));
        actClearOutput->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\346\241\206\345\205\250\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        actClearOutput->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272\346\225\260\346\215\256\347\232\204\347\274\226\350\276\221\346\241\206\345\205\250\346\270\205\347\251\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actClose->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actSaveALL->setText(QCoreApplication::translate("MainWindow", "\350\277\236\347\273\255\345\206\231\345\205\245\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actSaveALL->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\236\347\273\255\345\206\231\345\205\245\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actReadALL->setText(QCoreApplication::translate("MainWindow", "\350\277\236\347\273\255\344\273\216\346\226\207\344\273\266\350\257\273\345\217\226", nullptr));
#if QT_CONFIG(tooltip)
        actReadALL->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\236\347\273\255\344\273\216\346\226\207\344\273\266\350\257\273\345\217\226", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QString());
        btnFile->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\224\250\346\226\207\344\273\266", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\350\212\202\345\272\217\357\274\210\344\270\215\345\275\261\345\223\215RawData\347\232\204\350\257\273\345\206\231\357\274\211", nullptr));
        radio_LittleEndian->setText(QCoreApplication::translate("MainWindow", "LittleEndian", nullptr));
        radio_BigEndian->setText(QCoreApplication::translate("MainWindow", "BigEndian", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\265\256\347\202\271\346\225\260\347\262\276\345\272\246\357\274\210\344\270\215\345\275\261\345\223\215RawData\347\232\204\350\257\273\345\206\231\357\274\211", nullptr));
        radio_Single->setText(QCoreApplication::translate("MainWindow", "SinglePrecision", nullptr));
        radio_Double->setText(QCoreApplication::translate("MainWindow", "DoublePrecision", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\344\272\214\350\277\233\345\210\266\346\225\260\346\215\256\350\257\273\345\206\231\346\265\213\350\257\225", nullptr));
        btnInt32_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "quint16(0~65535)", nullptr));
        btnUIn16_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnUInt8_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "float\357\274\2104\345\255\227\350\212\202\357\274\211", nullptr));
        btnFloat_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnUInt8_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "qint8(-128~127)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "quint8(0~255)", nullptr));
        btnInt64_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        editStr_In->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\257\344\273\245\350\276\223\345\205\245\346\261\211\345\255\227", nullptr));
#endif // QT_CONFIG(tooltip)
        editStr_In->setText(QCoreApplication::translate("MainWindow", "Hello\344\275\240\345\245\275", nullptr));
        btnInt_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnInt32_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnInt16_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "String(Latin1\347\274\226\347\240\201)", nullptr));
        btnInt8_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnDouble_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnStr_Read2->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnInt64_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnDouble_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        editStr_In2->setToolTip(QCoreApplication::translate("MainWindow", "\346\261\211\345\255\227\350\257\273\345\207\272\344\274\232\344\271\261\347\240\201", nullptr));
#endif // QT_CONFIG(tooltip)
        editStr_In2->setText(QCoreApplication::translate("MainWindow", "Hello", nullptr));
        btnInt16_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        btnStr_Write->setToolTip(QCoreApplication::translate("MainWindow", "writeBytes()\345\207\275\346\225\260\345\206\231\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStr_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnBool_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "int(=qint32)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "qint64", nullptr));
        btnBool_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        btnStr_Read->setToolTip(QCoreApplication::translate("MainWindow", "readBytes()\345\207\275\346\225\260\350\257\273\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStr_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        btnStr_Write2->setToolTip(QCoreApplication::translate("MainWindow", "writeRawData()\345\207\275\346\225\260\345\206\231\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStr_Write2->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Bool", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "qint16(-32768~32767)", nullptr));
        chkBox_Out->setText(QCoreApplication::translate("MainWindow", "\345\270\203\345\260\224\345\200\274", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "String(UTF8\347\274\226\347\240\201)", nullptr));
        btnInt8_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnUInt16_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "double\357\274\2108\345\255\227\350\212\202\357\274\211", nullptr));
        btnInt_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "qint32", nullptr));
        chkBox_In->setText(QCoreApplication::translate("MainWindow", "\345\270\203\345\260\224\345\200\274", nullptr));
        btnFloat_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "qfloat16", nullptr));
        btnFloat16_Write->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        btnFloat16_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
