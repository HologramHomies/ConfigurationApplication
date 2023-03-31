#include "hologram_preview.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "ui_hologram_preview.h"
#include "QObject"

hologram_preview::hologram_preview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hologram_preview)

{
    ui->setupUi(this);
    connect(this, &QObject::destroyed, this, &hologram_preview::onWindowClosed);
    ui->verticalLayout_2->insertWidget(0,video_widget);
}

hologram_preview::~hologram_preview()
{
    delete media_player;
    delete ui;
}

void hologram_preview::setting_buttons(int id, QString video_path,int brightness, int contrast){

    qDebug() <<"clicked";
    qDebug() << id;


    QPushButton* preview_button = findChild<QPushButton*>("pushButton" + QString::number(id));
    qDebug() << preview_button;
    connect(preview_button, &QPushButton::clicked, this, [=]() {
        qDebug() << "Button" << id << "clicked";
        media_player->setVideoOutput(video_widget);
        media_player->setMedia(QUrl(video_path));
        video_widget->show();
        media_player->play();
    });

}

void hologram_preview::onWindowClosed() {
    qDebug() << "Window closed!";
    // Add your code here to handle the window closing event
}






