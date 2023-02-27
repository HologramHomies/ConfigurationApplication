#ifndef BUTTON_GROUPBOX_H
#define BUTTON_GROUPBOX_H

#include <QVBoxLayout>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGroupBox>


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

private slots:
    void on_openFile_pushButton_clicked();
    void on_remove_pushButton_clicked();


private:
    Ui::Button_GroupBox *ui;
    QVBoxLayout* video_layout = new QVBoxLayout;
    QVideoWidget* video_widget = new QVideoWidget();
    QMediaPlayer* media_player = new QMediaPlayer();
    int button_ID;
};

#endif // BUTTON_GROUPBOX_H
