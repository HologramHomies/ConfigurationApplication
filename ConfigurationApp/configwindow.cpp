#include "configwindow.h"
#include "ui_configwindow.h"
#include "button_groupbox.h"
#include "config.h"

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
    this->number_of_buttons +=1;
    group_box->setTitle("Button #"+QString::number(this->number_of_buttons));

    this->scroll_layout->addWidget(group_box);
    //this->widget->setLayout(this->scroll_layout);
    ui->scrollArea->setWidget(this->widget);
}

