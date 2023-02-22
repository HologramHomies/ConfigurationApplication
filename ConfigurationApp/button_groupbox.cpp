#include "button_groupbox.h"
#include "ui_button_groupbox.h"
#include "videoplayer.h"

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
                    QString("C:/"),
                    tr("Video Files (*.mp4 *.avi *.mov *.wmv)")
                    );
    if(video_path==QUrl("")){
        return;
    }
    ui->path_lineEdit->setText(video_path.toString());
    this->video_player->loadVideo(video_path);
}

