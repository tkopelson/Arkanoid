#ifndef JUEGOARKANOID_H
#define JUEGOARKANOID_H
#include "Dibujable.h"
#include "pelota.h"
#include "tablero.h"
#include "plataforma.h"
#include "bloque.h"
#include "bloqueindrestructible.h"
#include <QDebug>
class JuegoArkanoid : public Dibujable
{
public:
    JuegoArkanoid();
    ~JuegoArkanoid();

    void dibujar(QPainter*p) override;
    void ColisionesEstado(float tiempo);

    void setBoton(float key)
    {mover=key;}
    void setStart(int key)
    {StartPause=StartPause+key;}
    void MoverPlataforma();
    void GameOver();
protected:
    Pelota*pelota;
    Tablero*tablero;
   QList<Bloque*>bloque;
    Plataforma *plataforma;
    float mover;
    int StartPause;
    int vidaJugador;
};

#endif // JUEGOARKANOID_H
