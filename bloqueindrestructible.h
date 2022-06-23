#ifndef BLOQUEINDRESTRUCTIBLE_H
#define BLOQUEINDRESTRUCTIBLE_H
#include "bloque.h"

class BloqueIndrestructible: public Bloque
{
public:
    BloqueIndrestructible(QVector2D _bl1,QVector2D _bl2);

    virtual void dibujar(QPainter*p)override;

    int getVidaColi() override {return vida;}
    void VerificarColi() override;
protected:
    QVector2D bl1,bl2;
};

#endif // BLOQUEINDRESTRUCTIBLE_H
