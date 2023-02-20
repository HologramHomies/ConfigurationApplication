#include "mainwindow.h"

#include <QApplication>

#include <QMediaPlayer>

#include <QVideoWidget>

//NOTE: This will always be updated when the apply settings button is pressed
class videoSettings{
public:
    int brightnessValue;
    int constrastValue;
    double fromTrim;
    double toTrim;
    QString path;
    QMediaPlayer *player;
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
