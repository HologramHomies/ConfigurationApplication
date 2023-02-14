#include "mainwindow.h"

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui -> setupUi(this);

  QObject::connect(
    ui -> addBut_Button, & QPushButton::clicked,
    this, & MainWindow::onAddWidgets
  );
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::addProperties(QWidget * newWidget, QWidget * existingWidget) {
  newWidget -> setGeometry(existingWidget -> geometry());
  newWidget -> setMinimumSize(existingWidget -> minimumSize());
  newWidget -> setEnabled(existingWidget -> isEnabled());
  newWidget -> setFont(existingWidget -> font());
  newWidget -> setPalette(existingWidget -> palette());
  newWidget -> setStyleSheet(existingWidget -> styleSheet());
  newWidget -> setSizePolicy(existingWidget -> sizePolicy());
  newWidget -> setContentsMargins(existingWidget -> contentsMargins());

}

void MainWindow::onAddWidgets() {
  //Casting the Original vertical layout and the GroupBox within the layout
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
  newGroupBox -> setTitle(existingGroupBox -> title());
  newGroupBox -> setContentsMargins(existingGroupBox -> contentsMargins());
  newGroupBox -> setAlignment(existingGroupBox -> alignment());
  //    newGroupBox->setCheckable(existingGroupBox->isCheckable());
  //    newGroupBox->setChecked(existingGroupBox->isChecked());
  newGroupBox -> setFlat(existingGroupBox -> isFlat());
  //    newGroupBox->setEnabled(existingGroupBox->isEnabled());
  //newGroupBox->setLayout(existingGroupBox->layout());

  //Creating and replicating layout from the original
  QGridLayout * newLayout = new QGridLayout();
  newLayout -> setHorizontalSpacing(existingLayout -> horizontalSpacing());
  newLayout -> setVerticalSpacing(existingLayout -> verticalSpacing());

  //WARNING MUST MAKE SURE SECOND ITERATION WORKS
   qDebug() << "Check";
  QLayoutItem * videoLabel = existingLayout -> itemAtPosition(0, 0);
  QLayoutItem * largePrevButton = existingLayout -> itemAtPosition(1, 0);


  QWidget * existingLabelWidget = videoLabel -> widget();
  QWidget * existingPrevButton = largePrevButton -> widget();

  QLabel * label = qobject_cast < QLabel * > (existingLabelWidget);
  QPushButton * pushButton = dynamic_cast < QPushButton * > (existingPrevButton);
     qDebug() << "Check";

  QLabel * vidLabel = new QLabel();
  QPushButton * prevBut = new QPushButton();

  vidLabel -> setText(label -> text());
  prevBut -> setText(pushButton -> text());
  vidLabel -> setAlignment(label -> alignment());

  addProperties(vidLabel, existingLabelWidget);
  addProperties(prevBut, existingPrevButton);

  newLayout -> addWidget(vidLabel, 0, 1);
  newLayout -> addWidget(prevBut, 2, 1);

  QHBoxLayout * buttonSettings = dynamic_cast < QHBoxLayout * > (existingLayout -> itemAtPosition(1, 1));
  QHBoxLayout * buttonSettingsLayout = new QHBoxLayout();


  int count = buttonSettings -> count();

  for (int i = 0; i < count; i++) {
    QLayoutItem * existingItem = buttonSettings -> itemAt(i);

    if (!existingItem) {
      qDebug() << "Not an item";
      continue;
    }
    QWidget * existingWidget = existingItem -> widget();

    if (!existingWidget) {
      qDebug() << "Not a widget";
      QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
      buttonSettingsLayout -> addItem(horizontalSpacer);
      qDebug() << "Not a widget";
    } else {
      qDebug() << "Not a widget";
      QPushButton * pushButton = dynamic_cast < QPushButton * > (existingWidget);
      QPushButton * newWidget = new QPushButton();
      newWidget -> setText(pushButton -> text());
      addProperties(newWidget, existingWidget);

      buttonSettingsLayout -> addWidget(newWidget);
    }

  }
  newLayout -> addLayout(buttonSettingsLayout, 2, 2);

  //This item will contain the grid layout for the video options
  QGridLayout * videoOptions = dynamic_cast < QGridLayout * > (existingLayout -> itemAtPosition(0, 1));
  QGridLayout * videoOptionsGridLayout = new QGridLayout();

  //    qDebug()<<videoOptions->rowCount();
  //    qDebug()<<videoOptions->columnCount();

  for (int row = 0; row < videoOptions -> rowCount(); row++) {
    for (int column = 0; column < videoOptions -> columnCount(); column++) {
      if (videoOptionsGridLayout -> itemAtPosition(row, column)) {
        continue;
      }

      QLayoutItem * existingItem = videoOptions -> itemAtPosition(row, column);
      //            newLayout->setRowStretch(row, existingLayout->rowStretch(row));
      //            newLayout->setColumnStretch(column, existingLayout->columnStretch(column));
      //            newLayout->setColumnMinimumWidth(column, existingLayout->columnMinimumWidth(column));
      //            newLayout->setRowMinimumHeight(row, existingLayout->rowMinimumHeight(row));

      if (!existingItem) {
        //                qDebug()<<row;
        //                qDebug()<<column;
        //qDebug()<<"Not an item";
        //qDebug()<<existingLayout->itemAtPosition(row, column);
        continue;
      }

      QWidget * existingWidget = existingItem -> widget();
      //QSlider *slider = dynamic_cast<QSlider*>(existingWidget);
      //QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(existingWidget);

      if (!existingWidget) {
        //                qDebug()<<row;
        //                qDebug()<<column;
        // qDebug()<<"Not a widget";
        //qDebug()<<existingItem->widget();
        continue;
      }
      //Check if doing seperate q widgets help!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      else if (QLabel * label = qobject_cast < QLabel * > (existingWidget)) {
        QLabel * newWidget = new QLabel();
        newWidget -> setText(label -> text());
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 1, Qt::Alignment());

      } else if (QSlider * slider = qobject_cast < QSlider * > (existingWidget)) {
        qDebug() << existingItem -> widget();
        QSlider * newWidget = new QSlider(Qt::Horizontal, nullptr);
        addProperties(newWidget, existingWidget);

        videoOptionsGridLayout -> addWidget(newWidget, row, column, 1, 2, Qt::Alignment());
      } else if (QLineEdit * lineEdit = dynamic_cast < QLineEdit * > (existingWidget)) {
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
  //existingGroupBox->setLayout(newLayout);

  layout -> insertWidget(1, newGroupBox);

}
