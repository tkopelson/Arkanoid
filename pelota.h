#ifndef PELOTA_H
#define PELOTA_H
#include <QVector2D>
#include "Dibujable.h"
#include <QDebug>

class Pelota: public Dibujable
{
public:
    Pelota(QVector2D _pel,QVector2D _vel,float _radio);

    void dibujar(QPainter*p) override;
    void moverse(float tiempo);

    QVector2D getPel(){return pel;}
    QVector2D getVel(){return vel;}
    float getRadio(){return radio;}

    void setPel(float A,float B);
    void setVel(float A,float B);
protected:
    QVector2D pel;
    QVector2D vel;
    float radio;
};

#endif // PELOTA_H
