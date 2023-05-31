#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QString> // toString() 所需头文件
#include <QMessageBox>
#include <QRandomGenerator> // 随机数QRandomGenerator::global()->bounded 所需头文件

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    QTimer *timer1;

private slots:
    // 获取当前时间并显示在home.ui上
    void showCurTime();

    // 点击生成随机数按钮，生成随机数
    void genRandomNum();

    // 退出
    void exitHome();

};

#endif // HOME_H
