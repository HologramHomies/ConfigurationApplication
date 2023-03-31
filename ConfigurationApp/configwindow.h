#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
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
     void removeButtonAt(int button_ID);
     void updateButtonTitles();
     void resizeWindow();

private slots:
    void on_add_pushButton_clicked();
    void on_export_pushButton_clicked();
    void on_hologramPreview_pushButton_clicked();

private:
    Ui::ConfigWindow *ui;
    QList<Button_GroupBox*> button_GroupBoxes; // the GUI group box
    Config *config = new Config();
    int number_of_buttons = 0;
    int max_buttons = 8;
    QUrl saved_path;

    QWidget *widget = new QWidget();
    QVBoxLayout *scroll_layout = new QVBoxLayout(this->widget);

};

#endif // CONFIGWINDOW_H
