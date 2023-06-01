#include "login.h"
#include "./ui_login.h"
#include "home.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Login Window");
    ui->passwordText->setEchoMode(QLineEdit::Password);  // 隐藏显示密码
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginButton_clicked()
{
    qDebug()<<"this is on_loginButton_clicked()";
    QMessageBox *msgbox = new QMessageBox(this);

    if(ui->usernameText->text() == "rainy" && ui->passwordText->text()== "123")
    {
        qDebug()<<"Login success!";
        msgbox->information(this, "提示", "登陆成功");

//        Home home;
//        home.show();  // 一闪而过 为避免这样，要在login.h的pubilic中声明Home
        home.show();
        this->close(); // 关闭初始的那个界面
    }
    else
    {
        qDebug()<<"Login fail!";
        msgbox->information(this, "提示", "账号或密码错误");
        this->close();
    }

    delete msgbox;
}

void Widget::on_showimgButton_clicked()
{
    qDebug()<<"this is on_showimgButton_clicked()";
    showimg.show();
    this->close();
}

