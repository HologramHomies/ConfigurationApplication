#include "config.h"


Config::Config()
{

}


void Config::setNumberOfButtons(int number_of_buttons){
    this->number_of_buttons = number_of_buttons;
}


int Config::getNumberOfButtons(){
    return number_of_buttons;
}

void Config::setConfigName(QString name){
    this->config_name = name;
}

void Config::addButton(Button* button){
    this->Buttons.append(button);
}
