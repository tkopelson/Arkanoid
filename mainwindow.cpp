#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(50);
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this,SIGNAL(KeyBoton(int)),ui->widget,SLOT(PressBoton(int)));
    connect(this,SIGNAL(KeyStartPause(int)),ui->widget,SLOT(PressStart(int)));
    connect(this,SIGNAL(ResetKey(bool)),ui->widget,SLOT(PressResteo(bool)));
    this->setFixedHeight(800);
    this->setFixedWidth(600);
}

MainWindow::~MainWindow()
{delete ui;}

//DECTECCION DE BOTON DEL TECLADO.
//TRANSFORMA EL BOTON PRESIONADO A UN ENTERO
//LA SEÑAL MANDA UN ENTERO AL SLOT DEL WIDGET

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        emit KeyBoton(-15);}
    else{if(event->key()==Qt::Key_Right){
            emit KeyBoton(15);
        }else{if(event->key()==Qt::Key_Enter){
                emit KeyStartPause(1);
            }else{if(event->key()==Qt::Key_Escape){
                    emit ResetKey(true);}else{
                    emit KeyBoton(0);}}}}}
