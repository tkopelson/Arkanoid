#ifndef BLOQUE_H
#define BLOQUE_H
#include "objrectagulo.h"
#include <QVector2D>
#include "time.h"

class Bloque: public ObjRectagulo
{
public:
    Bloque(QVector2D _bl1,QVector2D _bl2);

    virtual void dibujar(QPainter *p) override;

    virtual int getVidaColi(){return vida;}
    virtual void VerificarColi();
protected:
  QVector2D bl1,bl2;
  int vida;
};

#endif // BLOQUE_H
