#include "juegoarkanoid.h"
#include "math.h"


JuegoArkanoid::JuegoArkanoid()
{ float velx=0.2/sqrt(0.2*0.2+0.3*0.3);
    float vely=-0.3/sqrt(0.2*0.2+0.3*0.3);
    pelota= new Pelota(QVector2D(300,585),QVector2D(velx/10,vely/10),10.0);

    tablero= new Tablero(QVector2D(0,0),QVector2D(600,800));
    plataforma= new Plataforma(QVector2D(237.5,600),QVector2D(362.5,630));

    vidaJugador=3;
    mover=0;
    StartPause=0;
   // srand( (unsigned)time( NULL ) );
    int conty=0;
    int bloqueind;
    for(int i=0;i<9;i++){
        int contx=0;
        for(int j=0;j<6;j++){
            bloqueind=rand()%101;
            if(i%2==0 and bloqueind<30){
                bloque.append(new BloqueIndrestructible(QVector2D(contx,conty),QVector2D(contx+100,conty+30)));
            }else{
                bloque.append(new Bloque(QVector2D(contx,conty),QVector2D(contx+100,conty+30)));}
            contx=contx+100;}
        conty=conty+30;}}

JuegoArkanoid::~JuegoArkanoid(){
    delete tablero;
    delete pelota;
    delete plataforma;
    for(int i=0;i<bloque.length();i++){
        delete bloque[i];
        bloque.remove(i);}}


//PIERDE UNA VIDA O PIERDE EL JUEGO EL JUGADOR.
void JuegoArkanoid::GameOver()
{
    if(tablero->getGameOver()==true and vidaJugador>0){
        vidaJugador=vidaJugador-1;
        plataforma->setRec1(237.5,600);
        plataforma->setRec2(362.5,630);

        float velx=0.2/sqrt(0.2*0.2+0.3*0.3);
        float vely=-0.3/sqrt(0.2*0.2+0.3*0.3);
        pelota->setPel(300,585);
        pelota->setVel(velx/10,vely/10);
        StartPause=0;
        tablero->setGameOver(false);
        qDebug()<<"VIDA DEL JUGADOR"<<vidaJugador;
    }}

void JuegoArkanoid::MoverPlataforma()
{
    if(StartPause%2==1 and vidaJugador>0){
        float PL1X=plataforma->getP1().x()+mover;
        float PL1Y=plataforma->getP1().y();
        float PL2X=plataforma->getP2().x()+mover;
        float PL2Y=plataforma->getP2().y();
        plataforma->setRec1(PL1X,PL1Y);
        plataforma->setRec2(PL2X,PL2Y);
        //MODIFICO LOS COMPONENTES DE LA VELOCIDAD PERO CON EL MISMO MODULO
        if(plataforma->getColision()==true){
            float VelX=pelota->getVel().x()+(mover*0.01);
            float VelY=pelota->getVel().y();
            float newVelX=VelX/sqrt(VelX*VelX+VelY*VelY);
            float newVelY=VelY/sqrt(VelX*VelX+VelY*VelY);
            pelota->setVel(newVelX/10,newVelY/10);
            plataforma->setColision(false);
        }}
    mover=0;}


void JuegoArkanoid::ColisionesEstado(float tiempo){
    if(StartPause%2==1 and vidaJugador>0){
        pelota->moverse(tiempo);
        plataforma->ColisionPel(pelota);
        tablero->ColisionPel(pelota);
        tablero->ColisionPlat(plataforma);
        for(int i=0;i<bloque.length();i++){
            if(bloque[i]->getVidaColi()>0){
                bloque[i]->ColisionPel(pelota);
                bloque[i]->VerificarColi();}
            else{
                delete bloque[i];
                bloque.remove(i);}}}}


void JuegoArkanoid::dibujar(QPainter *p){
    pelota->dibujar(p);
    plataforma->dibujar(p);
    tablero->dibujar(p);
    //qDebug()<<"PlATAFORMA X1="<<plataforma->getRec1().x()<<"   X2=="<<plataforma->getRec2().x();
    for(int i=0;i<bloque.length();i++){
        //if(bloque[i]->getVidaColi()>0){
        bloque[i]->dibujar(p);}


    p->setFont(QFont("Consolas", 15, QFont::Bold));
    p->drawText(440,650,"    "+ QString::number(vidaJugador));
    p->setBrush(Qt::red);
    p->setPen(QPen(Qt::red));
    p->drawEllipse(502,634,16,16);
    p->drawEllipse(516,634,16,16);
    p->drawEllipse(504,640,26,13);
    QPoint A1(504,649);
    QPoint B1(517,660);
    QPoint C1(529,649);
    QPolygon poly1;
    poly1 << A1 << B1<< C1;
    p->drawPolygon(poly1);
    p->setPen(QPen(Qt::black));
    p->setBrush(Qt::NoBrush);

    if(vidaJugador==0){
        p->setFont(QFont("Consolas",28,QFont::Bold));
        p->drawText(200,500,"GAME OVER");
    }}



