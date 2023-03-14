#include "configwindow.h"
#include "qdialog.h"
#include "ui_button_groupbox.h"
#include "ui_configwindow.h"
#include "button_groupbox.h"
#include "config.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

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
   if(number_of_buttons==max_buttons){
       QMessageBox *msgBox = new QMessageBox();
       msgBox->setText("Max Number of Buttons Reached!");
       msgBox->exec();
       return;
   }
    Button_GroupBox *group_box = new Button_GroupBox(this);

    this->button_GroupBoxes.append(group_box);
    this->number_of_buttons =button_GroupBoxes.size();

    group_box->setID(number_of_buttons);
    group_box->setTitle("Button #"+QString::number(this->number_of_buttons));

    this->scroll_layout->addWidget(group_box);
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

void ConfigWindow::on_export_pushButton_clicked(){
    if(ui->configName_lineEdit->text() == ""){
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Please Enter COnfiguration Name!");
        msgBox->exec();
        return;

    }

    saved_path = QFileDialog::getOpenFileUrl(
                    this,
                    tr("Select Directory"),
                    QString(""),
                    tr("Directory. (*.dir)")
                    );
    config->setNumberOfButtons(number_of_buttons);

    for(int i = 0; i< number_of_buttons; i++){
       int id = i;
       QString video_path = this->button_GroupBoxes[i]->getVideoPath();
       int brightness = this->button_GroupBoxes[i]->getBrightness();
       int contrast = this->button_GroupBoxes[i]->getContrast();
       Button *button = new Button(id, video_path, brightness, contrast);
       config->addButton(button);
    }
}

void ConfigWindow::resizeWindow()
{
    // Set the new size of the window
    this->resize(this->width(), this->height()+1);
}

