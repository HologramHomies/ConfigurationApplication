#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget> // for QList
#include "button.h"


class Config
{
private:
    QString config_name;
    int number_of_buttons;
    QList<Button> Buttons;
public:
    Config();
    void setConfigName(QString name);
    void addButton(Button button);
    void removeButton(int button_id);
    int getNumberOfButtons();
    void setNumberOfButtons(int number_of_buttons);

};

#endif // CONFIG_H
