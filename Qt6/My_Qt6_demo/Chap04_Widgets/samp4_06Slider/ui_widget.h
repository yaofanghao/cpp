/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QDial *dial;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *slider;
    QLabel *label_2;
    QScrollBar *scrollBar;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QProgressBar *progressBar;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QRadioButton *radio_Value;
    QRadioButton *radio_Percent;
    QCheckBox *chkBox_Inverted;
    QCheckBox *chkBox_Visible;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(436, 299);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        dial = new QDial(groupBox);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(200);
        dial->setValue(20);
        dial->setOrientation(Qt::Horizontal);
        dial->setWrapping(false);
        dial->setNotchTarget(5.000000000000000);
        dial->setNotchesVisible(true);

        horizontalLayout_2->addWidget(dial);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        slider = new QSlider(groupBox);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMaximum(200);
        slider->setValue(23);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::TicksAbove);

        gridLayout_2->addWidget(slider, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        scrollBar = new QScrollBar(groupBox);
        scrollBar->setObjectName(QString::fromUtf8("scrollBar"));
        scrollBar->setMaximum(200);
        scrollBar->setValue(23);
        scrollBar->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(scrollBar, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 0);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(200);
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radio_Value = new QRadioButton(frame_2);
        radio_Value->setObjectName(QString::fromUtf8("radio_Value"));
        radio_Value->setChecked(false);

        gridLayout->addWidget(radio_Value, 1, 1, 1, 1);

        radio_Percent = new QRadioButton(frame_2);
        radio_Percent->setObjectName(QString::fromUtf8("radio_Percent"));
        radio_Percent->setChecked(true);

        gridLayout->addWidget(radio_Percent, 1, 0, 1, 1);

        chkBox_Inverted = new QCheckBox(frame_2);
        chkBox_Inverted->setObjectName(QString::fromUtf8("chkBox_Inverted"));

        gridLayout->addWidget(chkBox_Inverted, 0, 1, 1, 1);

        chkBox_Visible = new QCheckBox(frame_2);
        chkBox_Visible->setObjectName(QString::fromUtf8("chkBox_Visible"));
        chkBox_Visible->setChecked(true);

        gridLayout->addWidget(chkBox_Visible, 0, 0, 1, 1);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(groupBox_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Slider\345\222\214ProgreeeBar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\273\221\345\212\250\350\276\223\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\273\221\345\212\250\346\235\241", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\267\346\273\232\346\235\241", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "ProgressBar\346\230\276\347\244\272\345\222\214\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\277\233\345\272\246\346\235\241", nullptr));
        radio_Value->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\240\274\345\274\217--\345\275\223\345\211\215\345\200\274", nullptr));
        radio_Percent->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\240\274\345\274\217--\347\231\276\345\210\206\346\257\224", nullptr));
        chkBox_Inverted->setText(QCoreApplication::translate("Widget", "invertedAppearance", nullptr));
        chkBox_Visible->setText(QCoreApplication::translate("Widget", "textVisible", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
