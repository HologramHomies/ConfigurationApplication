#ifndef BUTTON_H
#define BUTTON_H

#include "QWidget"

class Button
{

private:
    int button_id;
    QString video_path;
    int brightness;
    int contrast;
public:
    Button(int button_id, QString video_path, int brightness, int contrast);
};

#endif // BUTTON_H
