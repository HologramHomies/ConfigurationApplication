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
    delete video_widget;
    delete media_player;
    delete ui;

}

void hologram_preview::setting_buttons(int id, QString video_path,int brightness,
                                       int contrast, int start_pos, int end_pos ){

    QPushButton* preview_button = findChild<QPushButton*>("pushButton" + QString::number(id));
    connect(preview_button, &QPushButton::clicked, this, [=]() {

        media_player->setVideoOutput(video_widget);
        media_player->setMedia(QUrl(video_path));
        video_widget->setBrightness(brightness);

        video_widget->setContrast(contrast);


        media_player->setPosition(start_pos);

        video_widget->show();
        media_player->play();

    });

}

void hologram_preview::onWindowClosed() {
}






