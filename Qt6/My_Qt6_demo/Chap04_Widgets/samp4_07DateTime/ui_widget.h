/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *btnGetTime;
    QLabel *LabDateTime;
    QLabel *label;
    QTimeEdit *timeEdit;
    QLineEdit *editTime;
    QPushButton *btnDebugTime;
    QPushButton *btnSetTime;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLineEdit *editDate;
    QPushButton *btnSetDate;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *editDateTime;
    QPushButton *btnSetDateTime;
    QPushButton *btnDebugDate;
    QPushButton *btnDebugDateTime;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *editCalendar;
    QCalendarWidget *calendarWidget;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(708, 319);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnGetTime = new QPushButton(groupBox_2);
        btnGetTime->setObjectName(QString::fromUtf8("btnGetTime"));

        gridLayout->addWidget(btnGetTime, 0, 1, 1, 1);

        LabDateTime = new QLabel(groupBox_2);
        LabDateTime->setObjectName(QString::fromUtf8("LabDateTime"));
        LabDateTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LabDateTime, 0, 2, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        timeEdit = new QTimeEdit(groupBox_2);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setCalendarPopup(true);
        timeEdit->setTime(QTime(15, 30, 55));

        gridLayout->addWidget(timeEdit, 1, 1, 1, 1);

        editTime = new QLineEdit(groupBox_2);
        editTime->setObjectName(QString::fromUtf8("editTime"));

        gridLayout->addWidget(editTime, 1, 2, 1, 1);

        btnDebugTime = new QPushButton(groupBox_2);
        btnDebugTime->setObjectName(QString::fromUtf8("btnDebugTime"));

        gridLayout->addWidget(btnDebugTime, 2, 1, 1, 1);

        btnSetTime = new QPushButton(groupBox_2);
        btnSetTime->setObjectName(QString::fromUtf8("btnSetTime"));

        gridLayout->addWidget(btnSetTime, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2021, 9, 21), QTime(0, 0, 0)));
        dateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        dateEdit->setCalendarPopup(true);
        dateEdit->setCurrentSectionIndex(0);
        dateEdit->setDate(QDate(2021, 9, 21));

        gridLayout->addWidget(dateEdit, 3, 1, 1, 1);

        editDate = new QLineEdit(groupBox_2);
        editDate->setObjectName(QString::fromUtf8("editDate"));

        gridLayout->addWidget(editDate, 3, 2, 1, 1);

        btnSetDate = new QPushButton(groupBox_2);
        btnSetDate->setObjectName(QString::fromUtf8("btnSetDate"));

        gridLayout->addWidget(btnSetDate, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBox_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2021, 9, 19), QTime(8, 21, 28)));
        dateTimeEdit->setDate(QDate(2021, 9, 19));
        dateTimeEdit->setTime(QTime(8, 21, 28));
        dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);

        gridLayout->addWidget(dateTimeEdit, 5, 1, 1, 1);

        editDateTime = new QLineEdit(groupBox_2);
        editDateTime->setObjectName(QString::fromUtf8("editDateTime"));
        editDateTime->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(editDateTime, 5, 2, 1, 1);

        btnSetDateTime = new QPushButton(groupBox_2);
        btnSetDateTime->setObjectName(QString::fromUtf8("btnSetDateTime"));

        gridLayout->addWidget(btnSetDateTime, 6, 2, 1, 1);

        btnDebugDate = new QPushButton(groupBox_2);
        btnDebugDate->setObjectName(QString::fromUtf8("btnDebugDate"));

        gridLayout->addWidget(btnDebugDate, 4, 1, 1, 1);

        btnDebugDateTime = new QPushButton(groupBox_2);
        btnDebugDateTime->setObjectName(QString::fromUtf8("btnDebugDateTime"));

        gridLayout->addWidget(btnDebugDateTime, 6, 1, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        editCalendar = new QLineEdit(groupBox_3);
        editCalendar->setObjectName(QString::fromUtf8("editCalendar"));

        gridLayout_3->addWidget(editCalendar, 0, 1, 1, 1);

        calendarWidget = new QCalendarWidget(groupBox_3);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setSelectedDate(QDate(2021, 9, 15));
        calendarWidget->setGridVisible(true);

        gridLayout_3->addWidget(calendarWidget, 1, 0, 1, 2);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", " \346\227\245\346\234\237\346\227\266\351\227\264\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        btnGetTime->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        LabDateTime->setText(QCoreApplication::translate("Widget", "\345\255\227\347\254\246\344\270\262\346\230\276\347\244\272", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\227\266  \351\227\264", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("Widget", "HH:mm:ss", nullptr));
        editTime->setInputMask(QCoreApplication::translate("Widget", "99:99:99;_", nullptr));
        btnDebugTime->setText(QCoreApplication::translate("Widget", "qDebug--Time", nullptr));
        btnSetTime->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\227\266\351\227\264fromString", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\227\245  \346\234\237", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Widget", "yyyy\345\271\264M\346\234\210d\346\227\245", nullptr));
        editDate->setInputMask(QCoreApplication::translate("Widget", "9999-99-99", nullptr));
        btnSetDate->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\227\245\346\234\237fromString", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("Widget", "yyyy-MM-dd HH:mm:ss", nullptr));
        editDateTime->setInputMask(QCoreApplication::translate("Widget", "9999-99-99 99:99:99", nullptr));
        btnSetDateTime->setText(QCoreApplication::translate("Widget", "\346\227\245\346\234\237\346\227\266\351\227\264fromString", nullptr));
        btnDebugDate->setText(QCoreApplication::translate("Widget", "qDebug--Date", nullptr));
        btnDebugDateTime->setText(QCoreApplication::translate("Widget", "qDebug--DateTime", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\346\227\245\345\216\206\351\200\211\346\213\251", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\347\232\204\346\227\245\346\234\237\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
