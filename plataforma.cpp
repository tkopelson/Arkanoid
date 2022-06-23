#include "plataforma.h"

Plataforma::Plataforma(QVector2D _pl1,QVector2D _pl2)
    :ObjRectagulo(_pl1,_pl2)
{
    pl1=getP1();
    pl2=getP2();}


void Plataforma::dibujar(QPainter *p){
    QColor ColorRgb;

    ColorRgb.setRgb(255,255,0);
    p->setBrush(ColorRgb);
    p->drawRect(pl1.x(),pl1.y(),pl2.x()-pl1.x(),pl2.y()-pl1.y());
    p->setBrush(Qt::NoBrush);
    pl1=getP1();
    pl2=getP2();}
