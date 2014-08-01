#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define NUMBER_PLANETS 8
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <memory>
#include <list>
#include "mainworker.h"

using namespace std;

class MainWindow : public QGLWidget
{
    Q_OBJECT
protected:
    int WidthX, HeightY;
    void initializeGL(); // Метод для инициализирования opengl
    void resizeGL(int nWidth, int nHeight); // Метод вызываемый после каждого изменения размера окна
    void paintGL(); // Метод для вывода изображения на экран
    void paintPlanet(); // Рисуем объекты
    void paintSun();
    void mousePressEvent(QMouseEvent *mouse);
    void keyPressEvent(QKeyEvent *ke);
    void loadTextures();
private:
    std::shared_ptr<MainWorker> m_MainWorker;
public:
    MainWindow(int x, int y,QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
