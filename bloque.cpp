#include "bloque.h"
#include "math.h"
Bloque::Bloque(QVector2D _bl1,QVector2D _bl2):
    ObjRectagulo(_bl1,_bl2)
{
    //srand( (unsigned)time( NULL ) );
    bl1=_bl1;
    bl2=_bl2;
    vida= rand()%3+1;}

//DIBUJAR BLOQUE
void Bloque::dibujar(QPainter*p){
QColor ColorRgb;
if (vida==1){
    ColorRgb.setRgb(200,0,0);
    p->setBrush(ColorRgb);
    p->drawRect(bl1.x(),bl1.y(),bl2.x()-bl1.x(),bl2.y()-bl1.y());
    p->setBrush(Qt::NoBrush);
}else{if(vida==2){
        ColorRgb.setRgb(0,200,0);
        p->setBrush(ColorRgb);
        p->drawRect(bl1.x(),bl1.y(),bl2.x()-bl1.x(),bl2.y()-bl1.y());
        p->setBrush(Qt::NoBrush);
    }else{if(vida==3){
            ColorRgb.setRgb(0,0,200);
            p->setBrush(ColorRgb);
             p->drawRect(bl1.x(),bl1.y(),bl2.x()-bl1.x(),bl2.y()-bl1.y());
            p->setBrush(Qt::NoBrush);
        }}}}


void Bloque::VerificarColi(){
if(getColision()==true){
  vida=vida-1;
  setColision(false);}}


