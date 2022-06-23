#include "pelota.h"

Pelota::Pelota(QVector2D _pel,QVector2D _vel,float _radio)
{
    pel=_pel;
    vel=_vel;
    radio=_radio;
}

void Pelota::dibujar(QPainter *p){
    QColor color;
    color.setRgb(200,0,0);
    p->setBrush(color);
    p->drawEllipse(QPointF(pel.x(), pel.y()), radio, radio);
    p->setBrush(Qt::NoBrush);

}


//MOVIMIENTO DE LA PELOTA
void Pelota::moverse(float tiempo)
{
    pel.setX(pel.x()+vel.x()*tiempo);
    pel.setY(pel.y()+vel.y()*tiempo);}

//SET DE LA POSICION DE LA PELOTA
void Pelota::setPel(float A, float B)
{
    pel.setX(A);
    pel.setY(B);
}

//SET DE LA VELOCIDAD DE LA PELOTA
void Pelota::setVel(float A, float B)
{
    vel.setX(A);
    vel.setY(B);
}
