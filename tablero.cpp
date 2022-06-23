#include "tablero.h"

Tablero::Tablero(QVector2D _tl1,QVector2D _tl2):
    ObjRectagulo(_tl1,_tl2)
{
    tl1=_tl1;
    tl2=_tl2;
    gameOver=false;
}

//COLISION DEL TABLERO CON LA PELOTA
//ES DIFERENTE YA QUE LA COLISION ES POR ADENTRO DEL RECTANGULO
//POR LO QUE MODIFICA LA FUNCION HEREDADA
void Tablero::ColisionPel(Pelota *p){
    float PELX=p->getPel().x();
    float PELY=p->getPel().y();
    float VELX=p->getVel().x();
    float VELY=p->getVel().y();
    float rad=p->getRadio();


    //COLISION LADO DERECHO Y LADO IZQUIERDO
    if(PELX+rad>=tl2.x()){
        p->setVel(-VELX,VELY);
        p->setPel(tl2.x()-rad,PELY);
    }else{if(PELX-rad<=tl1.x()){
            p->setVel(-VELX,VELY);
            p->setPel(tl1.x()+rad,PELY);}}

    //COLISION LADO ARRIBA Y LADO ABAJO
    if(PELY-rad<=tl1.y()){
        p->setVel(VELX,-VELY);
        p->setPel(PELX,tl1.y()+rad);
    }else{if(PELY+rad>=tl2.y()){
            p->setVel(VELX,-VELY);
            p->setPel(PELX,tl2.y()-rad);
            gameOver=true;}}}



//COLISION DE LA PLATAFORMA CON EL TABLERO
void Tablero::ColisionPlat(Plataforma *p){
    float PL1X=p->getP1().x();
    float PL2X=p->getP2().x();
    float mover;

    //COLISION LADO DERECHO Y LADO IZQUIERDO
    if(PL2X>=tl2.x()){
        mover=PL2X-tl2.x();
        p->setRec1(PL1X-mover,p->getP1().y());
        p->setRec2(PL2X-mover,p->getP2().y());
    }else{if(PL1X<=tl1.y()){
            mover=PL1X-tl1.x();
            p->setRec1(PL1X-mover,p->getP1().y());
            p->setRec2(PL2X-mover,p->getP2().y());}}}



void Tablero::setGameOver(bool A)
{gameOver=A;}



