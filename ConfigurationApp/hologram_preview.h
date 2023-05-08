#ifndef HOLOGRAM_PREVIEW_H
#define HOLOGRAM_PREVIEW_H

#include "qmediaplayer.h"
#include "qvideowidget.h"
#include <QMainWindow>

namespace Ui {
class hologram_preview;
}

class hologram_preview : public QMainWindow
{
    Q_OBJECT

public:
    explicit hologram_preview(QWidget *parent = nullptr);
    ~hologram_preview();
    void setting_buttons(int id, QString video_path, int brightness, int contrast, int start_pos, int end_pos);


private:
    Ui::hologram_preview *ui;
    QVideoWidget* video_widget = new QVideoWidget;
    QMediaPlayer* media_player = new QMediaPlayer();

private slots:
    void onWindowClosed();
};







#endif // HOLOGRAM_PREVIEW_H
