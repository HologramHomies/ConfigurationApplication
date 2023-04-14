#include "configwindow.h"
#include "hologram_preview.h"
#include "qdialog.h"
#include "ui_button_groupbox.h"
#include "ui_configwindow.h"
#include "button_groupbox.h"
#include "config.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QXmlStreamWriter>

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
    this->number_of_buttons -=1;
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
    QString configName = ui->configName_lineEdit->text();
    QString cleanedConfigName;
    if(configName == ""){
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Please Enter Configuration Name!");
        msgBox->exec();
        return;
    } else {
        // config name set, remove illegal characters for saving
        QStringList invalidChars = { "\\", "/", ":", "*", "?", "\"", "<", ">", "|" };
        QStringList parts = configName.split(QRegExp("[" + invalidChars.join("") + "]"));
        cleanedConfigName = parts.join("_");
    }

    QUrl saved_path = QFileDialog::getExistingDirectoryUrl(
                        this,
                        tr("Select Directory"),
                        QUrl::fromLocalFile(QDir::homePath())
                        );

    // validate directory
    if (!saved_path.isEmpty()) {
        QFile file(saved_path.toLocalFile() + "/" + cleanedConfigName + ".xml");
        qDebug()<<saved_path.toLocalFile();
        qDebug()<<saved_path.path();

        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
            qDebug()<<"yo";
            QXmlStreamWriter xml(&file);
            xml.setAutoFormatting(true);

            xml.writeStartDocument();
            xml.writeStartElement("configuration");
            xml.writeAttribute("name", configName);
            for(int i = 0; i< number_of_buttons; i++){
                QString id         = QString::number(this->button_GroupBoxes[i]->getID());
                QString brightness = QString::number(this->button_GroupBoxes[i]->getBrightness());
                QString contrast   = QString::number(this->button_GroupBoxes[i]->getContrast());
                QString start_pos = QString::number(this->button_GroupBoxes[i]->getStartPos());
                QString end_pos = QString::number(this->button_GroupBoxes[i]->getEndPos());
                QString video_path = this->button_GroupBoxes[i]->getVideoPath();

                xml.writeStartElement("button");
                xml.writeAttribute("end_pos", end_pos);
                xml.writeAttribute("start_pos", start_pos);
                xml.writeAttribute("contrast", contrast);
                xml.writeAttribute("brightness", brightness);
                xml.writeAttribute("video_path", video_path);
                xml.writeAttribute("id", id);

                xml.writeEndElement();
            }
            xml.writeEndElement();
            xml.writeEndDocument();

            file.close();
        }
    }

    config->setNumberOfButtons(number_of_buttons);

    for(int i = 0; i< number_of_buttons; i++){
       int id = this->button_GroupBoxes[i]->getID();
       QString video_path = this->button_GroupBoxes[i]->getVideoPath();
       int brightness = this->button_GroupBoxes[i]->getBrightness();
       int contrast = this->button_GroupBoxes[i]->getContrast();
       Button *button = new Button(id, video_path, brightness, contrast);
       config->addButton(button);

       // Create a file object for the source video
       QFile source_file(video_path);
       QFileInfo fileInfo(source_file.fileName());
       QString extension = fileInfo.suffix();

       // Create a directory object for the target directory
       QDir target_dir(saved_path.toLocalFile());

       // Create a file object for the target video
       QString copy_video_name = QString::number(id) +"." + extension;
       QString target_file_path = target_dir.absoluteFilePath(copy_video_name);
       QFile target_file(target_file_path);
        //qDebug() << video_path;
       //qDebug() << target_file_path;
       // Copy the file to the target directory with the new file name
       if (source_file.copy(target_file_path)) {
           qDebug() << "File copied successfully";
       } else {
           qDebug() << "Failed to copy file";
       }
    }
}

void ConfigWindow::on_hologramPreview_pushButton_clicked()
{
    QList<Button*> prev_buttons;
    hologram_preview *h = new hologram_preview;
    for(int i = 0; i< number_of_buttons; i++){
       int id = this->button_GroupBoxes[i]->getID();
       QString video_path = this->button_GroupBoxes[i]->getVideoPath();
       int brightness = this->button_GroupBoxes[i]->getBrightness();
       int contrast = this->button_GroupBoxes[i]->getContrast();
//       Button *button = new Button(id, video_path, brightness, contrast);
//       prev_buttons.append(button);
       h->setting_buttons(id, video_path, brightness, contrast);
       qDebug() <<"no";
    }

    h->show();

}

void ConfigWindow::resizeWindow()
{
    // Set the new size of the window
    this->resize(this->width(), this->height()+1);
}

