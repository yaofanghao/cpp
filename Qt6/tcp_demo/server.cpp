#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    qDebug()<<"this is listen()";
    listen(QHostAddress::Any, 8888); // 开启端口
    // 8888端口是否开启可以在cmd中用 netstat -ano 查看
}

// 如果外部有连接到此端口，会进入此函数
// 可以在cmd中用 telnet 127.0。0.1 8888 测试
// 如果此处打印this is incomingConnection() 则成功连接
void Server::incomingConnection(qintptr handle)
{
    qDebug()<<"this is incomingConnection()";
    socket_ = new QTcpSocket(this);
    socket_->setSocketDescriptor(handle);

    // 信号关联，只有准备读取时，才进行消息接收和处理
    connect(socket_, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void Server::receiveMessage()
{
//    qDebug()<<"this is receiveMessage()";

    if(socket_->bytesAvailable())
    {
        char buffer[1024];
        socket_->read(buffer, socket_->bytesAvailable()); // 读取接收数据
        qDebug()<<buffer;
    }
}
