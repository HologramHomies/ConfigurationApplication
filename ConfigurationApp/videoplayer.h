#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGroupBox>
#include <QVBoxLayout>

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();
    void setupVideo(QGroupBox*, QUrl);

private:
    Ui::VideoPlayer *ui;
    QVBoxLayout* video_layout = new QVBoxLayout;
    QVideoWidget* video_widget = new QVideoWidget();
    QMediaPlayer* media_player = new QMediaPlayer();
};

#endif // VIDEOPLAYER_H

