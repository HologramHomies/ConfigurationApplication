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
    this->video_player->setupVideo(ui->video_groupBox, video_path);
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

