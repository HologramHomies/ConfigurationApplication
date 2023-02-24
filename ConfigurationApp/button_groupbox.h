#ifndef BUTTON_GROUPBOX_H
#define BUTTON_GROUPBOX_H

#include <QGroupBox>
#include "videoplayer.h"

namespace Ui {
class Button_GroupBox;
}

class Button_GroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit Button_GroupBox(QWidget *parent = nullptr);
    ~Button_GroupBox();

private slots:
    void on_openFile_pushButton_clicked();
    void on_remove_pushButton_clicked();


private:
    Ui::Button_GroupBox *ui;
    VideoPlayer *video_player = new VideoPlayer();
};

#endif // BUTTON_GROUPBOX_H
