#ifndef TABLERO_H
#define TABLERO_H
#include "objrectagulo.h"
#include "plataforma.h"
#include <QVector2D>
#include "plataforma.h"
class Tablero: public ObjRectagulo
{
public:
    Tablero(QVector2D tl1,QVector2D tl2);

    void ColisionPel(Pelota*p) override;
    void ColisionPlat(Plataforma*p);

    bool getGameOver()
    {return gameOver;}

    void setGameOver(bool A);
protected:
 QVector2D tl1,tl2;
 bool gameOver;
};

#endif // TABLERO_H
