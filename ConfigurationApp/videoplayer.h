#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QGraphicsView>

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();
    void loadVideo(QUrl);

private:
    Ui::VideoPlayer *ui;
    QVideoWidget* video_item = new QVideoWidget();
    QMediaPlayer* media_player = new QMediaPlayer();
};

#endif // VIDEOPLAYER_H

