#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    int x = 1000, y = 600;
    QApplication app(argc, argv);
    MainWindow window(x,y);
    window.setWindowTitle("Planets");
    window.setGeometry(100,100,x,y);
    //window.setCursor(QCursor(Qt::BlankCursor));
    window.show();
    return app.exec();
}
