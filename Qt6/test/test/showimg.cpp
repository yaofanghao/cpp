#include "showimg.h"
#include "ui_showimg.h"

ShowImg::ShowImg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowImg)
{
    ui->setupUi(this);

    num = 1;

    // 显示图片的相关代码
    pm = new QPixmap();
    pm->load(":/img/" + QString::number(num) + ".png");
    pm->scaled(200,200);
    lblimg.setPixmap(*pm);
    lblimg.setScaledContents(true);  // 设置尺寸为自适应
    lblimg.setParent(this);

    // 每隔一段时间，切换显示图片
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(displayImg()));
    timer1->start(1000);

    connect(ui->button_exit, SIGNAL(clicked()),
            this, SLOT(exitShowImg()));
}

ShowImg::~ShowImg()
{
    delete ui;
}

void ShowImg::displayImg()
{
    qDebug()<<"this is displayImg()";
    num++;
    if(num>3) num=1;
    pm->load(":/img/" + QString::number(num) + ".png");
    pm->scaled(200,200);
    lblimg.setPixmap(*pm);
    lblimg.setScaledContents(true);
}

void ShowImg::exitShowImg()
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
