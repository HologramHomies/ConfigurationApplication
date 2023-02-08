#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addVideoButton_clicked()
{

}


void MainWindow::on_browseButton_1_clicked()
{
    QUrl homePath = QUrl("\Videos");
    QString videoPath = QFileDialog::getOpenFileName(
                this,
                tr("Select Video"),
                "./Videos",
                tr("Video Files (*.mp4 *.avi *.mov)")
                );
    ui->videoPathLine_1->setText(videoPath);
    //qDebug()<<videoPath;

}

