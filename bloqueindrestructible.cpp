#include "bloqueindrestructible.h"

BloqueIndrestructible::BloqueIndrestructible(QVector2D _bl1,QVector2D _bl2):
    Bloque(_bl1,_bl2)
{
    bl1=_bl1;
    bl2=_bl2;
}

void BloqueIndrestructible::dibujar(QPainter *p){
    QColor ColorRgb;

    ColorRgb.setRgb(255,255,255);
    p->setBrush(ColorRgb);
    p->drawRect(bl1.x(),bl1.y(),bl2.x()-bl1.x(),bl2.y()-bl1.y());
    p->setBrush(Qt::NoBrush);}

//NO NECESARIA
void BloqueIndrestructible::VerificarColi(){
    if(getColision()==true){
      setColision(false);}}
