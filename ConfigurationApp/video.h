#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget> // for QString


class Video
{
private:
    QString path;
    int brightness;
    int contrast;

public:
    Video();
};

#endif // VIDEO_H
