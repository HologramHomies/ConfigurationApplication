#include "configwindow.h"
#include "ui_configwindow.h"
#include "button_groupbox.h"
#include "config.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}


void ConfigWindow::on_add_pushButton_clicked()
{
    Button_GroupBox *group_box = new Button_GroupBox(this);
    this->button_GroupBoxes.append(group_box);
    this->number_of_buttons +=1;
    group_box->setTitle("Button #"+QString::number(this->number_of_buttons));
    if(this->number_of_buttons == 1){
        //add new groupbox to scroll area

    }
}

