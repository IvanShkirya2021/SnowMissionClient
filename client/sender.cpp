#include "sender.h"

sendPack::sendPack(ClientData* client)
{
    {
        client_data = client;

        socket = new QTcpSocket();
        timer_connect = new QTimer();
        timer_send = new QTimer();
        timer_send->setInterval(1000);
        timer_connect->setInterval(100);

        timer_connect->start();
        connect(timer_send, SIGNAL(timeout()), this, SLOT(send_package()));
        connect(timer_connect, SIGNAL(timeout()), this, SLOT(connecting()));
    }
}

void sendPack::connecting()
{
    if (socket->state() != QAbstractSocket::ConnectingState){
        if(timer_send->isActive()) timer_send->stop();
        if(!(timer_connect->isActive())) timer_connect->start();
        qDebug() << "Попытка подключения";
        socket->connectToHost(QHostAddress::LocalHost, 5000, QIODevice::ReadWrite);
    }
    else if ( socket->state() != QAbstractSocket::ConnectingState)
    {
        if(!(timer_send->isActive())) timer_send->start();
        if(timer_connect->isActive()) timer_connect->stop();
    }
}

void sendPack::send_package()
{
    if(socket->state() == QAbstractSocket::ClosingState){
        timer_send->stop();
        timer_connect->start();
    }
    else
    {
        if(client_data->get_work_id() == 0)
        {
            client_data->set_my_status(0);
        }
        qDebug() << "sendPack::send_package";
        QByteArray data;
        data.append(Start_SIGNATURE);

        data.append(client_data->get_my_type());
        data.append(client_data->get_status());
        data.append(client_data->get_speed());
        data.append(client_data->get_position().x());
        data.append(client_data->get_position().y());
        data.append(client_data->get_power());
        data.append(client_data->get_performance());

        qDebug() << data;
        socket->write(data);
    }
}
