#ifndef OBJRECTAGULO_H
#define OBJRECTAGULO_H
#include <QVector2D>
#include "Dibujable.h"
#include "pelota.h"

class ObjRectagulo: public Dibujable
{
public:
    ObjRectagulo(QVector2D _rec1,QVector2D _rec2);
    virtual void dibujar(QPainter*p) override;

    QVector2D getP1(){return rec1;}
    QVector2D getP2(){return rec2;}
    bool getColision(){return colision;}

    void setColision(bool A);
    void setRec1(float A,float B);
    void setRec2(float A, float B);


    virtual void ColisionPel(Pelota*p);
protected:
    QVector2D rec1;
    QVector2D rec2;
    bool colision;
    int color;
};

#endif // OBJRECTAGULO_H
