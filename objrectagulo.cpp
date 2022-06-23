#include "objrectagulo.h"
#include <QDebug>

ObjRectagulo::ObjRectagulo(QVector2D _rec1,QVector2D _rec2):
    rec1(_rec1),
    rec2(_rec2)
{colision=false;
    color=0;}

//DIBUJA TODO LOS ELEMENTOS QUE TENGAN UNA FORMA RECTANGULAR
//DEL JUEGO... LOS HIJOS SON EL BLOQUE,TABLERO,PLATAFORMA
void ObjRectagulo::dibujar(QPainter *p)
{p->drawRect(rec1.x(),rec1.y(),rec2.x()-rec1.x(),rec2.y()-rec1.y());}


//LOS SET LOS HEREDAN TODOS LOS HIJOS PERO ALGUNOS NOMAS LOS USAN.
//SIRVE POR SI SE QUIERE AGREGAR BLOQUES QUE SE MUEVAN
void ObjRectagulo::setRec1(float A, float B)
{
    rec1.setX(A);
    rec1.setY(B);
}

void ObjRectagulo::setColision(bool A)
{colision=A;}

void ObjRectagulo::setRec2(float A, float B)
{
    rec2.setX(A);
    rec2.setY(B);
}

//COLISIONES DE LOS OBJETOS RECTANGULOS CON LA PELOTA
// ES VIRTUAL PORQUE ESTA HECHA PARA LAS COLISIONES CON LA
// PELOTA FUERA DEL RECTANGULO
void ObjRectagulo::ColisionPel(Pelota *p)
{
    //VALORES DE LA PELOTA
    float PELX=p->getPel().x();
    float PELY=p->getPel().y();
    float VELX=p->getVel().x();
    float VELY=p->getVel().y();
    float rad=p->getRadio();

    //MITAD DEL RECTANGULO
    float MITADX=(rec2.x()-rec1.x())/2;
    float MITADY=(rec2.y()-rec1.y())/2;


    if(VELX>0 )
    {
        if((PELX+rad)>=rec1.x() and PELX+rad<(MITADX+rec1.x()) and rec1.y()<PELY and PELY<rec2.y()){
            p->setVel(-VELX,VELY);
            p->setPel(rec1.x()-rad,PELY);
            colision=true;
        }}else{if((rec1.x()+MITADX)<PELX+rad and PELX-rad<=rec2.x() and rec1.y()<PELY and PELY<rec2.y()){
            colision=true;
            p->setVel(-VELX,VELY);
            p->setPel(rec2.x()+rad,PELY);}}

    if(VELY>0)
    {
        if((PELY+rad)>=rec1.y() and PELY+rad<(MITADY+rec1.y()) and rec1.x()<PELX and PELX<rec2.x()){
            colision=true;
            p->setVel(VELX,-VELY);
            p->setPel(PELX,rec1.y()-rad);
        }}else{if((rec1.y()+MITADY)<PELY+rad and (PELY-rad)<=rec2.y() and rec1.x()<PELX and PELX<rec2.x()){
            colision=true;
            p->setVel(VELX,-VELY);
            p->setPel(PELX,rec2.y()+rad);}}}
























