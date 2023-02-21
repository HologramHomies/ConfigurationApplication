#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmediaplayer.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //Felipe Functions
    void onAddWidgets();
    //void showFullScreen(QVideoWidget *videoWidget);
    void addProperties(QWidget * newWidget, QWidget * existingWidget);
    void removeButton();
    void addVideo();


private slots:

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player = nullptr;
};
#endif // MAINWINDOW_H
