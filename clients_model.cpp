#include "clients_model.h"
#include <QDebug>

ClientData::ClientData(QObject *parent, TypeClient _TypeClient) : QObject(parent)
{
    my_type = _TypeClient;

}

float ClientData::get_speed()
{
    return my_speed;
}

QPointF ClientData::get_position()
{
    return my_position;
}

float ClientData::get_performance()
{
    return my_performance;
}

QString ClientData::get_my_type()
{
    QString type_return;
    if(my_type==TypeClient::Robot)
    {
        return "Robot";
    }

    else if(my_type==TypeClient::Human)
    {
        return "Human";
    }
    else return "Technics";
}

void ClientData::set_position_x(float x_pos)
{
    my_position.setX(x_pos);
}

void ClientData::set_position_y(float y_pos)
{
    my_position.setY(y_pos);
}

void ClientData::set_max_speed(float newSpeed)
{
    qDebug() << newSpeed;
    my_speed = newSpeed;
}

void ClientData::set_performance(float newPerformance)
{
    my_performance = newPerformance;
}


