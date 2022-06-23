#ifndef WIDGETARKANOID_H
#define WIDGETARKANOID_H
#include <QWidget>
#include <QTimer>
#include "juegoarkanoid.h"
#include <QKeyEvent>
#include <QPainter>
class WidgetArkanoid : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetArkanoid(QWidget *parent=nullptr);
    void paintEvent(QPaintEvent*e) override;
public slots:
    void PressBoton(int k);
    void PressStart(int k);
    void PressResteo(bool k);
protected:
    JuegoArkanoid * arkanoid;
    float refresco_ms=10;
    bool key;
    QTimer timer;
};

#endif // WIDGETARKANOID_H
