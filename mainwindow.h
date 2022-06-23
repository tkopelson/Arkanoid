#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>
#include "widgetarkanoid.h"
#include <QTimer>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent*event)override;
signals:
   void KeyBoton(int);
   void KeyStartPause(int);
   void ResetKey(bool);
private:
    Ui::MainWindow *ui;
    QTimer timer;
};
#endif // MAINWINDOW_H
