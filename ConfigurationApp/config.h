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
    void addButton();
    void removeButton(int button_id);
};

#endif // CONFIG_H
