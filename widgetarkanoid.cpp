#include "widgetarkanoid.h"
#include <QPainter>
WidgetArkanoid::WidgetArkanoid(QWidget*parent)
    :QWidget{parent}
{
   arkanoid= new JuegoArkanoid();
   timer.setInterval(refresco_ms);
   connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
   timer.start();
   key=false;
}


void WidgetArkanoid::paintEvent(QPaintEvent *e){

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing,true);
    p.setWindow(0,0,600,800);
    p.setViewport(0,0,width(),height());
    arkanoid->GameOver();
    arkanoid->ColisionesEstado(30);
    arkanoid->MoverPlataforma();
    arkanoid->dibujar(&p);}

//SLOT QUE CAMBIA LA POSICION DE LA PLATAFORMA
//EN EL JUEGO
void WidgetArkanoid::PressBoton(int k){
   arkanoid->setBoton(k);}

//PAUSA DEL JUEGO
void WidgetArkanoid::PressStart(int k){
    arkanoid->setStart(k);
}

//RESETEO DEL JUEGO
void WidgetArkanoid::PressResteo(bool k){
    key=k;
    if(key==true){
        arkanoid->~JuegoArkanoid();
        arkanoid= new JuegoArkanoid();
        key=false;}}
