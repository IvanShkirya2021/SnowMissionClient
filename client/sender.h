#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <qexception.h>
#include <QHostAddress>
#include "clients_model.h"

class sendPack : public QObject
{
    Q_OBJECT
public:
    explicit sendPack(ClientData* client);

    QTcpSocket* socket = nullptr;
    QString Start_SIGNATURE = "[START]";

    ClientData* client_data = nullptr;

    QTimer* timer_send;
    QTimer* timer_connect;


public slots:
    void send_package();
    void connecting();
};

#endif // SENDER_H
