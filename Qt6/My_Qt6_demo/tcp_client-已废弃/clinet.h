#ifndef CLINET_H
#define CLINET_H

#include <QWidget>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class Clinet; }
QT_END_NAMESPACE

class Clinet : public QWidget
{
    Q_OBJECT

public:
    Clinet(QWidget *parent = nullptr);
    ~Clinet();

private:
    Ui::Clinet *ui;
    QTcpSocket *socket_;

private slots:
    // 连接端口监听
    void on_button_connect_clicked();

    // 发送消息
    void on_button_send_clicked();

    // 如果外部有连接到此端口，会进入此函数
//    void incomingConnection(qintptr handle);
    void receiveMessage();
};
#endif // CLINET_H
