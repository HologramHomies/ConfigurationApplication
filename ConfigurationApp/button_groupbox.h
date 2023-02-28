#ifndef BUTTON_GROUPBOX_H
#define BUTTON_GROUPBOX_H

#include <QVBoxLayout>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGroupBox>
#include <QLabel>
#include <QPixmap>


namespace Ui {
class Button_GroupBox;
}

class Button_GroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit Button_GroupBox(QWidget *parent = nullptr);
    ~Button_GroupBox();
    int getID();
    void setID(int new_ID);
    void playClicked();

private slots:
    void on_openFile_pushButton_clicked();
    void on_remove_pushButton_clicked();
    void on_reset_pushButton_clicked();

private:
    Ui::Button_GroupBox *ui;
    QVBoxLayout* video_layout = new QVBoxLayout();
    QVideoWidget* video_widget = new QVideoWidget;
    QMediaPlayer* media_player = new QMediaPlayer();

    QLabel* icon_label = new QLabel;
    QPixmap play_icon;
    QPixmap pause_icon;
    QPixmap replay_icon;

    int button_ID;
};

#endif // BUTTON_GROUPBOX_H
