#include "button_groupbox.h"
#include "ui_button_groupbox.h"
#include "configwindow.h"
#include <unistd.h>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QUrl>
#include <QString>
#include "ctkrangeslider.h"


/* TODO
 *


*/

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

    trim_slider->setOrientation(Qt::Horizontal);
    ui->trim_layout->addWidget(trim_slider);
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

    this->video_path = video_path.toLocalFile();


    ui->path_lineEdit->setText(video_path.toString());
    // add video layout the the groupbox that already in the correct position on the UI
    ui->video_groupBox->setLayout(video_layout);
    // get the video by let the media grab its path
    media_player->setMedia(video_path);

    video_widget->show();
    media_player->play();
    //media_player->pause();

    //Pause/Play Button Functionality
    connect(ui->pause_pushButton,&QPushButton::clicked,this,&Button_GroupBox::playClicked);

    //Seeker Video Functions
    connect(media_player,&QMediaPlayer::durationChanged,ui->seeker_slider,&QSlider::setMaximum);
    connect(media_player,&QMediaPlayer::positionChanged,ui->seeker_slider,&QSlider::setValue);
    connect(ui->seeker_slider,&QSlider::sliderMoved,media_player,&QMediaPlayer::setPosition);
    connect(ui->seeker_slider,&QSlider::valueChanged,media_player,&QMediaPlayer::setPosition);


    //Brightness Video Functions
    ui->brightness_slider->setRange(-100, 100);
    ui->brightness_slider->setValue(video_widget->brightness());
    connect(ui->brightness_slider, &QSlider::sliderMoved, video_widget, &QVideoWidget::setBrightness);
    connect(video_widget, &QVideoWidget::brightnessChanged, ui->brightness_slider, &QSlider::setValue);

    //Contrast Video Functions
    ui->contrast_slider->setRange(-100, 100);
    ui->contrast_slider->setValue(video_widget->contrast());
    connect(ui->contrast_slider, &QSlider::sliderMoved, video_widget, &QVideoWidget::setContrast);
    connect(video_widget, &QVideoWidget::contrastChanged, ui->contrast_slider, &QSlider::setValue);

    //Trim Video Functions
    trim_slider->setMinimumValue(0);
    trim_slider->setMinimumPosition(0);
    trim_slider->setMaximumPosition(100);
    trim_slider->setMaximumValue(100);

    connect(trim_slider,&ctkRangeSlider::minimumPositionChanged, [=](int value) {
        qDebug() << "New minimum value:" << value;
        this->end_pos = value;
        int new_start = (value*media_player->duration())/100;
        ui->seeker_slider->setMinimum(new_start);
    });

    connect(trim_slider,&ctkRangeSlider::maximumPositionChanged, [=](int value) {
        qDebug() << "New Maximum value:" << value;
        int new_end = (value*media_player->duration())/100;
        ui->seeker_slider->setMaximum(new_end);
        this->start_pos = value;
        if(new_end<media_player->position()){
            media_player->stop();
        }
    });\


    connect(ui->seeker_slider,&QSlider::valueChanged, [=](int value) {
        qDebug() << "New Current value:" << value;
        qDebug() << "New Maximum seeker value:" << ui->seeker_slider->maximum();
        if(value >= ui->seeker_slider->maximum()){
            media_player->stop();
        }
    });


    icon_label->setPixmap(play_icon);
    // Set the alignment and size of the icon label
    icon_label->setAlignment(Qt::AlignCenter);
    icon_label->setFixedSize(video_widget->size());


    //FIX: Fixes whitespace bug when loading a video
    ConfigWindow *configWindow=dynamic_cast<ConfigWindow*>(sender()->parent()->parent()->parent()->parent()->parent()->parent());
    configWindow->resizeWindow();

}


void Button_GroupBox::on_remove_pushButton_clicked(){
    media_player->setMedia(QUrl(""));
    ConfigWindow *configWindow=dynamic_cast<ConfigWindow*>(sender()->parent()->parent()->parent()->parent()->parent()->parent());
    configWindow->removeButtonAt(button_ID-1);
    delete dynamic_cast < QGroupBox * > (sender()->parent());
    configWindow->updateButtonTitles();
}

void Button_GroupBox::on_reset_pushButton_clicked(){

    ui->path_lineEdit->setText("");
    ui->brightness_slider->setValue(0);
    ui->contrast_slider->setValue(0);
    media_player->setMedia(QUrl(""));
}


int Button_GroupBox::getID()
{
   return button_ID;
}

void Button_GroupBox::setID(int new_button_ID)
{
   button_ID = new_button_ID;
}

QString Button_GroupBox::getVideoPath(){
    return this->video_path;
}

void Button_GroupBox::playClicked()
{
    switch (media_player->state()) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        media_player->play();
        break;
    case QMediaPlayer::PlayingState:
        media_player->pause();
        break;
    }
}

void Button_GroupBox::on_contrast_slider_sliderMoved(int position)
{
    this->contrast = position;
}

int Button_GroupBox::getContrast(){
    return this->contrast;
}

void Button_GroupBox::on_brightness_slider_sliderMoved(int position)
{
    this->brightness = position;
}

int Button_GroupBox::getBrightness(){
    return this->brightness;
}


int Button_GroupBox::getStartPos(){
    return this->start_pos;
}


int Button_GroupBox::getEndPos(){
    return this->end_pos;
}



