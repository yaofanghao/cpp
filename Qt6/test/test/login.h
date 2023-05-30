#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include "home.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Home home;

private:
    Ui::Widget *ui;

private slots:
    // 点击登录按钮，进入home界面
    void on_loginButton_clicked();
};
#endif // WIDGET_H
