#include "configwindow.h"
#include "ui_configwindow.h"
#include "button_groupbox.h"
#include "config.h"
#include <QDebug>

ConfigWindow::ConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(true);
    // QWidget *widget = new QWidget();
    // QVBoxLayout *scroll_layout = new QVBoxLayout(this->widget);
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}

void ConfigWindow::on_add_pushButton_clicked()
{
    Button_GroupBox *group_box = new Button_GroupBox(this);
    this->button_GroupBoxes.append(group_box);
    this->number_of_buttons =button_GroupBoxes.size();
    group_box->setID(number_of_buttons);
    group_box->setTitle("Button #"+QString::number(this->number_of_buttons));

    this->scroll_layout->addWidget(group_box);
    //this->widget->setLayout(this->scroll_layout);
    ui->scrollArea->setWidget(this->widget);
}

void ConfigWindow::removeButtonAt(int button_ID)
{
    this->button_GroupBoxes.removeAt(button_ID);
}

void ConfigWindow::updateButtonTitles()
{
    for(int i = 0;i<button_GroupBoxes.size();i++)
    {
        button_GroupBoxes.at(i)->setID(i+1);
        button_GroupBoxes.at(i)->setTitle("Button #"+QString::number(button_GroupBoxes.at(i)->getID()));
        this->scroll_layout->insertWidget(i,button_GroupBoxes.at(i));
    }

}

