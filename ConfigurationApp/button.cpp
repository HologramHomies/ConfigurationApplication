#include "button.h"


Button::Button(int button_id,QString video_path,int brightness, int contrast)
{
    this->button_id = button_id;
    this->video_path = video_path;
    this->brightness = brightness;
    this->contrast = contrast;
}
