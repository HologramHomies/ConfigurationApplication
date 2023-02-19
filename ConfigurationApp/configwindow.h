#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QMainWindow>
#include "button_groupbox.h"
#include "config.h"

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = nullptr);
    ~ConfigWindow();

private slots:
    void on_add_pushButton_clicked();

private:
    Ui::ConfigWindow *ui;
    QList<Button_GroupBox*> button_GroupBoxes; // the GUI group box
    Config config;
    int number_of_buttons = 0;
};

#endif // CONFIGWINDOW_H
