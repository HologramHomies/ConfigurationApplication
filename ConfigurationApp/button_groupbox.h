#ifndef BUTTON_GROUPBOX_H
#define BUTTON_GROUPBOX_H

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

private:
    Ui::Button_GroupBox *ui;
};

#endif // BUTTON_GROUPBOX_H
