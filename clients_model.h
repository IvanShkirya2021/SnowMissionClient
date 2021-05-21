#ifndef CLIENTS_MODEL_H
#define CLIENTS_MODEL_H

#include <QObject>

#include <QPointF>

enum class TypeClient {
    Robot,
    Human,
    Technics
};

class ClientData : public QObject
{
    Q_OBJECT
public:
    explicit ClientData(QObject *parent = nullptr, TypeClient _TypeClient = TypeClient::Human);
    float get_speed();
    QPointF get_position();
    float get_performance();
    QString get_my_type();
    void set_max_speed(float newSpeed);
    void set_performance(float newPerformance);
    void set_position_x(float x_pos);
    void set_position_y(float y_pos);
private:
    QPointF my_position= QPointF(0,0);
    TypeClient my_type;
    float my_speed = 30.0;
    float my_performance = 1.0;


public slots:

signals:

};

#endif // CLIENTS_MODEL_H
