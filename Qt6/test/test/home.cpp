#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(showCurTime()));
    timer1->start(10);
    connect(ui->button_getRandNum, SIGNAL(clicked()),
            this, SLOT(genRandomNum()));
    connect(ui->button_exit, SIGNAL(clicked()),
            this, SLOT(exitHome()));
}

Home::~Home()
{
    delete ui;
}

void Home::showCurTime()
{
//    qDebug()<<"this is func1()";
    QString curTime = QTime::currentTime().toString("hh:mm:ss");
    ui->label_curTime->setText(curTime);
}

void Home::genRandomNum()
{
    qDebug()<<"this is genRandomNum()";
    int randNum = QRandomGenerator::global()->bounded(10);
    QString randNumStr = QString::number(randNum);  // int转为string
    ui->label_randNum->setText(randNumStr);
}

void Home::exitHome()
{
    qDebug()<<"this is exitHome()";
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setText("警告！");
    msgbox->setInformativeText("是否退出");
    msgbox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgbox->setDefaultButton(QMessageBox::Ok);
    int ret = msgbox->exec();
//    qDebug()<<ret;
    if(ret == QMessageBox::Ok)
    {
        this->close();
    }
    else
    {
        ;
    }
}


