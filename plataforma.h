#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <QVector2D>
#include "objrectagulo.h"
class Plataforma: public ObjRectagulo
{
public:
    Plataforma(QVector2D pl1,QVector2D pl2);
    void dibujar(QPainter*p) override;
protected:
QVector2D pl1,pl2;
};

#endif // PLATAFORMA_H
