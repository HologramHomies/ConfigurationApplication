#include "button_groupbox.h"
#include "ui_button_groupbox.h"
#include "configwindow.h"

#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QUrl>
#include <QString>

Button_GroupBox::Button_GroupBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Button_GroupBox)
{
    ui->setupUi(this);
    video_layout->addWidget(video_widget);
    media_player->setVideoOutput(video_widget);

    play_icon.load(":/icons/icons/play.png");
    pause_icon.load(":/icons/icons/pause.png");
    replay_icon.load(":/icons/icons/replay.png");
}

Button_GroupBox::~Button_GroupBox()
{
    delete ui;
}

void Button_GroupBox::on_openFile_pushButton_clicked()
{
    QUrl video_path = QFileDialog::getOpenFileUrl(
                    this,
                    tr("Select Video"),
                    QString(""),
                    tr("Video Files (*.mp4 *.avi *.mov *.wmv)")
                    );
    if(video_path==QUrl("")){
        return;
    }
    ui->path_lineEdit->setText(video_path.toString());
    // add video layout the the groupbox that already in the correct position on the UI
    ui->video_groupBox->setLayout(video_layout);
    // get the video by let the media grab its path
    media_player->setMedia(video_path);

    video_widget->show();
    media_player->play();
    media_player->pause();

    icon_label->setPixmap(play_icon);
    // Set the alignment and size of the icon label
    icon_label->setAlignment(Qt::AlignCenter);
    icon_label->setFixedSize(video_widget->size());

}


void Button_GroupBox::on_remove_pushButton_clicked(){
    ConfigWindow *configWindow=dynamic_cast<ConfigWindow*>(sender()->parent()->parent()->parent()->parent()->parent()->parent());
    configWindow->removeButtonAt(button_ID-1);
    delete dynamic_cast < QGroupBox * > (sender()->parent());
    configWindow->updateButtonTitles();
}

int Button_GroupBox::getID()
{
   return button_ID;
}

void Button_GroupBox::setID(int new_button_ID)
{
   button_ID = new_button_ID;
}

