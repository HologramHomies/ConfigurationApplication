#include "videoplayer.h"
#include "ui_videoplayer.h"

#include <QUrl>

VideoPlayer::VideoPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);
}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}

void loadVideo(QUrl video_path){
    //qInfo() << "testing";
    return;
}
