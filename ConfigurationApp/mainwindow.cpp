#include "mainwindow.h"


#include "ui_mainwindow.h"


#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsEffect>
#include <QMouseEvent>


int totalVideos =1;
QMediaPlayer *player = new QMediaPlayer;



MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui -> setupUi(this);


  QObject::connect(
    ui -> addButton_pushButton, & QPushButton::clicked,
    this, & MainWindow::onAddWidgets
  );

  QObject::connect(
    ui -> removeButton_pushButton, & QPushButton::clicked,
    this, & MainWindow::removeButton
  );

  QObject::connect(
    ui -> openVideo_pushButton, & QPushButton::clicked,
    this, & MainWindow::addVideo
  );
}

MainWindow::~MainWindow() {
  delete ui;
}





void MainWindow::addVideo(){
    /*TODO
     * VERY IMPORTANT
     * (FIXED)Properly remove any previously added video from the group box
     * Save the MediaPlayer (Object responsible for playing video files) to a data structure
     * Reset all controls and audio (create a function for this)
     * Make onClick for videoWidget(Video display) able to pause the video
     * Double clicking the videoWidget(Video Display) will make video fullscreen
     *
     *
     * NOT SO IMPORTANT
     * Add a volume slider(Not to be saved but for user convinience)
     *
     * NOTE: Large Preview button was removed and replaced with a seeker slider
     *
     *
     */

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QGridLayout * existingLayout = dynamic_cast < QGridLayout * > (button -> parentWidget() -> layout());

//    qDebug()<<existingLayout -> itemAtPosition(0, 0);
//    qDebug()<<existingLayout -> itemAtPosition(0, 0)->widget();

    QUrl videoPath = QFileDialog::getOpenFileUrl(
                this,
                tr("Select Video"),
                QString("C:/"),
                tr("Video Files (*.mp4 *.avi *.mov *.wmv)")
                );
    if(videoPath==QUrl("")){
        return;
    }
    QVideoWidget *vw = new QVideoWidget;
    //player = new QMediaPlayer;

    if(dynamic_cast < QLabel * > (existingLayout -> itemAtPosition(0, 1)->widget())){
            vw->setSizePolicy(existingLayout -> itemAtPosition(0, 1)->widget()->sizePolicy());
            vw->setMinimumSize(existingLayout -> itemAtPosition(0, 1)->widget()->minimumSize());
            delete dynamic_cast < QWidget * > (existingLayout -> itemAtPosition(0, 1)->widget());

        //existingLayout ->removeWidget(existingLayout -> itemAtPosition(0, 0)->widget());
    }else{
        vw = dynamic_cast < QVideoWidget * > (existingLayout -> itemAtPosition(0, 1)->widget());
        //player = vw->mediaObject->service();
    }

    vw->setMouseTracking(true);
    //connect(vw, &QVideoWidget::mouseDoubleClickEvent, this, &MainWindow::toggleFullScreen);
    //QObject::connect(vw, &QVideoWidget::mousePressEvent, player, &QMediaPlayer::pause);




    //QUrl homePath = QUrl("\Videos");

    ui->videoPath_lineEdit->setText(videoPath.toString());

//    QAudioOutput *audioOutput = new QAudioOutput;
//    audioOutput ->setVolume(.25);
    //player->set(audioOutput);
     //qDebug() << vw->children();
    //QMediaPlayer *player = new QMediaPlayer;
    player -> setVolume(10);
    player -> setMedia(videoPath);
    player ->setVideoOutput(vw);

    existingLayout -> addWidget(vw, 0, 1);

    vw -> show();
    qDebug() << player->mediaStatus();

    player ->play();
    connect(player,&QMediaPlayer::durationChanged,ui->seeker_Slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,ui->seeker_Slider,&QSlider::setValue);
    connect(ui->seeker_Slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);
    ui->brightness_Slider->setRange(-100,100);
    ui->contrast_Slider->setRange(-100,100);
    ui->contrast_Slider->setSliderPosition(0);
    ui->brightness_Slider->setSliderPosition(0);
    connect(ui->brightness_Slider,&QSlider::valueChanged,vw,&QVideoWidget::setBrightness);
    connect(ui->contrast_Slider,&QSlider::valueChanged,vw,&QVideoWidget::setContrast);



}

void MainWindow::removeButton(){
    totalVideos--;

    delete dynamic_cast < QGroupBox * > (sender()->parent());

}

void MainWindow::addProperties(QWidget * newWidget, QWidget * existingWidget) {
  newWidget -> setGeometry(existingWidget -> geometry());
  newWidget -> setMinimumSize(existingWidget -> minimumSize());
  newWidget -> setEnabled(true);
  newWidget -> setFont(existingWidget -> font());
  newWidget -> setPalette(existingWidget -> palette());
  newWidget -> setStyleSheet(existingWidget -> styleSheet());
  newWidget -> setSizePolicy(existingWidget -> sizePolicy());
  newWidget -> setContentsMargins(existingWidget -> contentsMargins());
  newWidget -> setStyleSheet(existingWidget -> styleSheet());
}

void MainWindow::onAddWidgets() {
    /*
     * TODO
     * VERY IMPORTANT
     * Add Functionality to new widgets being created
     * Create a data structure where these new buttons are added
     * Save any new video button data that will be inserted
     *
     * NOT SO IMPORTANT
     * Make new video button font size the same

*/
    totalVideos++;




  //Casting the Original vertical layout and the GroupBox within the Scroll Area layout
  QVBoxLayout * layout = qobject_cast < QVBoxLayout * > (ui -> scrollAreaWidgetContents ->layout());
  QGroupBox * existingGroupBox = ui -> originalGroupBox;

  //Exceptions
  if (!existingGroupBox) {
    qDebug() << "GroupBox is invalid or does not exist";
    return;
  }
  QGridLayout * existingLayout = dynamic_cast < QGridLayout * > (existingGroupBox -> layout());
  if (!existingLayout) {
    qDebug() << "Groupbox has an invalid layout";
    return;
  }
  //Creating a new GroupBox where we will duplicate widgets
  QGroupBox * newGroupBox = new QGroupBox();

  //Replicating properties to new GroupBox
  newGroupBox -> setTitle("Button #"+QString::number(totalVideos));
  newGroupBox -> setContentsMargins(existingGroupBox -> contentsMargins());
  newGroupBox -> setAlignment(existingGroupBox -> alignment());
  newGroupBox->setCheckable(existingGroupBox->isCheckable());
  newGroupBox->setChecked(existingGroupBox->isChecked());
  newGroupBox -> setFlat(existingGroupBox -> isFlat());
  //newGroupBox->setEnabled(existingGroupBox->isEnabled());
  //newGroupBox->setLayout(existingGroupBox->layout());

  //Creating and replicating layout from the original
  QGridLayout * newLayout = new QGridLayout();
  newLayout -> setHorizontalSpacing(existingLayout -> horizontalSpacing());
  newLayout -> setVerticalSpacing(existingLayout -> verticalSpacing());

  /*The following will grab the standalone widgets from the original
    group box and add them to the new groupbox*/
  QLayoutItem * videoDisplay = existingLayout -> itemAtPosition(0, 1);
  QLayoutItem * seeker = existingLayout -> itemAtPosition(2, 1);

  QWidget * existingLabelWidget = videoDisplay -> widget();
  QWidget * existingSlider = seeker -> widget();


//  QVideoWidget * videoWidget = qobject_cast < QVideoWidget * > (existingLabelWidget);
//  QSlider * seekSlider = dynamic_cast < QSlider * > (existingSlider);

  QLabel * vidLabel = new QLabel();
  QSlider * seek = new QSlider(Qt::Horizontal,this);

  //vidLabel -> setText(label -> text());
  //prevBut -> setText(pushButton -> text());
  //vidLabel -> setAlignment(label -> alignment());

  addProperties(vidLabel, existingLabelWidget);
  addProperties(seek, existingSlider);

  newLayout -> addWidget(vidLabel, 0, 1);
  newLayout -> addWidget(seek, 2, 1);

  QHBoxLayout * buttonSettings = dynamic_cast < QHBoxLayout * > (existingLayout -> itemAtPosition(2, 2));
  QHBoxLayout * buttonSettingsLayout = new QHBoxLayout();

  /*This for loop will iterate through all the widgets in the HLayout that is
   * in the groupbox. This will include the video button settings*/
  for (int i = 0; i < buttonSettings -> count(); i++) {
    QLayoutItem * existingItem = buttonSettings -> itemAt(i);

    if (!existingItem) {
      //qDebug() << "Not an item";
      continue;
    }
    QWidget * existingWidget = existingItem -> widget();

    if (!existingWidget) {
      //qDebug() << "Not a widget";
      QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
      buttonSettingsLayout -> addItem(horizontalSpacer);
    } else {
      QPushButton * pushButton = dynamic_cast < QPushButton * > (existingWidget);
      QPushButton * newWidget = new QPushButton();
      if(pushButton->text()=="Remove Button"){
          QObject::connect(
            newWidget, & QPushButton::clicked,
            this, & MainWindow::removeButton
          );
      }

      newWidget -> setText(pushButton -> text());
      addProperties(newWidget, existingWidget);

      buttonSettingsLayout -> addWidget(newWidget);
    }

  }
  newLayout -> addLayout(buttonSettingsLayout, 2, 2);

  //This item will contain the grid layout for the video options
  QGridLayout * videoOptions = dynamic_cast < QGridLayout * > (existingLayout -> itemAtPosition(0, 2));
  QGridLayout * videoOptionsGridLayout = new QGridLayout();

  //qDebug()<<videoOptions->rowCount();
  //qDebug()<<videoOptions->columnCount();

  for (int row = 0; row < videoOptions -> rowCount(); row++) {
    for (int column = 0; column < videoOptions -> columnCount(); column++) {
      if (videoOptionsGridLayout -> itemAtPosition(row, column)) {
        continue;
      }

      QLayoutItem * existingItem = videoOptions -> itemAtPosition(row, column);
      //newLayout->setRowStretch(row, existingLayout->rowStretch(row));
      //newLayout->setColumnStretch(column, existingLayout->columnStretch(column));
      //newLayout->setColumnMinimumWidth(column, existingLayout->columnMinimumWidth(column));
      //newLayout->setRowMinimumHeight(row, existingLayout->rowMinimumHeight(row));

      if (!existingItem) {
        //qDebug()<<"Not an item";
        //qDebug()<<existingLayout->itemAtPosition(row, column);
        continue;
      }

      QWidget * existingWidget = existingItem -> widget();

      if (!existingWidget) {
        //qDebug()<<"Not a widget";
        //qDebug()<<existingItem->widget();
        continue;
      }
      /*NOTE: Created a brand new instance of whatever type of widget was in layout
        to prevent removing widget from existing layout */
      else if (QLabel * label = qobject_cast < QLabel * > (existingWidget)) {
        QLabel * newWidget = new QLabel();
        newWidget -> setText(label -> text());
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 1, Qt::Alignment());

      } else if (qobject_cast < QSlider * > (existingWidget)) {
        QSlider * newWidget = new QSlider(Qt::Horizontal, nullptr);
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 2, Qt::Alignment());
      } else if (dynamic_cast < QLineEdit * > (existingWidget)) {
        QLineEdit * newWidget = new QLineEdit();
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 1, Qt::Alignment());
      } else if (QPushButton * pushButton = dynamic_cast < QPushButton * > (existingWidget)) {
        QPushButton * newWidget = new QPushButton();
        newWidget -> setText(pushButton -> text());
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 1, Qt::Alignment());
      }

    }
  }

  newLayout -> addLayout(videoOptionsGridLayout, 0, 2);

  newGroupBox -> setLayout(newLayout);

  layout -> insertWidget(totalVideos-1, newGroupBox);

}


