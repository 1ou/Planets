#include "mainwindow.h"

MainWindow::MainWindow(int x, int y, QWidget* parent) : QGLWidget(parent)
{
    m_MainWorker = std::make_shared<MainWorker> ();
    m_MainWorker->mathPositionPlanet();

    setFormat(QGLFormat(QGL::DoubleBuffer));
    glDepthFunc(GL_LEQUAL);
    WidthX = x;
    HeightY = y;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();
}

void MainWindow::initializeGL()
{
    qglClearColor(Qt::black);
    glLoadIdentity();
}

void MainWindow::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    WidthX = nWidth;
    HeightY = nHeight;
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WidthX,HeightY,0,1,0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    paintSun();
    paintPlanet();

    swapBuffers();
}

void MainWindow::paintSun()
{
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1,1,0);
    glVertex2d(WidthX / 2, HeightY / 2);
    glEnd();
}

void MainWindow::paintPlanet()
{
    list<coordinate> listOfPlanets = m_MainWorker->getPlanetList();
    list<coordinate>::iterator i;
    for(i = listOfPlanets.begin(); i != listOfPlanets.end(); ++i)
    {
        glPointSize(i->getSize());
        glBegin(GL_POINTS);
        glColor3f(0,1,1);

        glVertex2d(i->getX() * m_MainWorker->getViewDistance() + WidthX / 2,
                   i->getY() * m_MainWorker->getViewDistance() + HeightY / 2);
        glEnd();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    if(mouse->button() == Qt::RightButton)
    {
    }
    if(mouse->button() == Qt::LeftButton)
    {
    }
    updateGL();
}

void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key())
    {
    case Qt::Key_Z:
        m_MainWorker->setViewDistance(m_MainWorker->getViewDistance() + 1);
        break;
    case Qt::Key_X:
        m_MainWorker->setViewDistance(m_MainWorker->getViewDistance() - 1);
        break;
    case Qt::Key_C:
        m_MainWorker->mathOrbitPlanet();
    case Qt::Key_V:
        m_MainWorker->mathPositionPlanet();
        break;
    }
    updateGL();
}

MainWindow::~MainWindow()
{
}

