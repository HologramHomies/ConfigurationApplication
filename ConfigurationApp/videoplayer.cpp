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

void VideoPlayer::setupVideo(QGroupBox* video_box, QUrl video_path){
    video_layout->addWidget(video_widget);
    video_box->setLayout(video_layout);
    media_player->setVideoOutput(video_widget);
    media_player->setMedia(video_path);
    video_widget->show();

    //media_player->play();
}
