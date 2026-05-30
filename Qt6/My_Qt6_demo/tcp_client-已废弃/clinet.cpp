#include "clinet.h"
#include "ui_clinet.h"

Clinet::Clinet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clinet)
{
    ui->setupUi(this);
}

Clinet::~Clinet()
{
    delete ui;
}

void Clinet::on_button_connect_clicked()
{
    qDebug()<<"this is on_button_connect_clicked()";

    socket_ = new QTcpSocket(this);
    socket_->connectToHost(ui->lineEdit_ip->text(),
                           ui->lineEdit_port->text().toInt()); // 连接端口

    // 信号关联，只有准备读取时，才进行消息接收和处理
    connect(socket_, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void Clinet::on_button_send_clicked()
{
    QString send_data_str = ui->textEdit_send->toPlainText();
    socket_->write(send_data_str);
}


//void Server::incomingConnection(qintptr handle)
//{
//    qDebug()<<"this is incomingConnection()";
//    socket_ = new QTcpSocket(this);
//    socket_->setSocketDescriptor(handle);

//    // 信号关联，只有准备读取时，才进行消息接收和处理
//    connect(socket_, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
//}

void Clinet::receiveMessage()
{
    //    qDebug()<<"this is receiveMessage()";

    QByteArray receive_data = socket_->readAll(); // 读取接收数据
    QString receive_data_str = receive_data.data();
    qDebug()<<receive_data_str;
    ui->textEdit_receive->setText(receive_data_str);

    if(receive_data_str=="quit")
    {
        this->hide();
    }


}
