#include "button_groupbox.h"
#include "ui_button_groupbox.h"
#include "videoplayer.h"
#include "configwindow.h"

#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QUrl>

Button_GroupBox::Button_GroupBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Button_GroupBox)
{
    ui->setupUi(this);
    video_layout->addWidget(video_widget);
    media_player->setVideoOutput(video_widget);
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
    ui->video_groupBox->setLayout(video_layout);
    media_player->setMedia(video_path);
    video_widget->show();
    media_player->play();
}

void Button_GroupBox::on_remove_pushButton_clicked(){
    ConfigWindow *configWindow=dynamic_cast<ConfigWindow*>(sender()->parent()->parent()->parent()->parent()->parent()->parent());
    configWindow->removeButtonAt(getID()-1);
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

