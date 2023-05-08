#ifndef BUTTONLAYOUT_H
#define BUTTONLAYOUT_H

#include <QWidget>

namespace Ui {
class ButtonLayout;
}

class ButtonLayout : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonLayout(QWidget *parent = nullptr);
    ~ButtonLayout();

private:
    Ui::ButtonLayout *ui;
};

#endif // BUTTONLAYOUT_H
