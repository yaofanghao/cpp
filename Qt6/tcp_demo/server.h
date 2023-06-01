#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>  // tcp通讯所需头文件
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

private:
    QTcpSocket *socket_;

private slots:
    // 如果外部有连接到此端口，会进入此函数
    void incomingConnection(qintptr handle);
    void receiveMessage();
};

#endif // SERVER_H
