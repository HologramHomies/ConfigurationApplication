#include "button_groupbox.h"
#include "ui_button_groupbox.h"

Button_GroupBox::Button_GroupBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Button_GroupBox)
{
    ui->setupUi(this);
}

Button_GroupBox::~Button_GroupBox()
{
    delete ui;
}
