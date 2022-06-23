#ifndef DIBUJABLE_H
#define DIBUJABLE_H
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include <QColor>
#include <QConicalGradient>
class Dibujable{
public:
   virtual void dibujar(QPainter *p)=0;
};
#endif // DIBUJABLE_H
