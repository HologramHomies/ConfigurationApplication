/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionExport;
    QAction *actionQuit;
    QAction *actionSave;
    QAction *actionOpen_Last_Project;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *b1_gbox;
    QGridLayout *gridLayout_2;
    QPushButton *b1OpenFile_button;
    QLabel *b1Path_label;
    QLabel *b1Constrast_label;
    QLineEdit *b1Path_lineEdit;
    QHBoxLayout *b1Footer_hbox;
    QSpacerItem *b1Footer_spacer;
    QPushButton *b1Reset_button;
    QPushButton *b1Apply_button;
    QLabel *b1Brightness_label;
    QLabel *b1Trim_label;
    QPushButton *b1Preview_button;
    QSlider *b1Trim_slider;
    QSlider *b1Contrast_slider;
    QSlider *b1Brightness_slider;
    QLabel *videoPlayerPlaceholder_label;
    QHBoxLayout *addButton_hbox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addButton_button;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *windowFooter_hbox;
    QSpacerItem *windowFooter_spacer;
    QPushButton *hologramPreview_button;
    QPushButton *export_button;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("b"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName("actionExport");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionOpen_Last_Project = new QAction(MainWindow);
        actionOpen_Last_Project->setObjectName("actionOpen_Last_Project");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 774, 481));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        b1_gbox = new QGroupBox(scrollAreaWidgetContents);
        b1_gbox->setObjectName("b1_gbox");
        QFont font;
        font.setPointSize(14);
        b1_gbox->setFont(font);
        b1_gbox->setAutoFillBackground(false);
        b1_gbox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        b1_gbox->setFlat(false);
        b1_gbox->setCheckable(true);
        gridLayout_2 = new QGridLayout(b1_gbox);
        gridLayout_2->setObjectName("gridLayout_2");
        b1OpenFile_button = new QPushButton(b1_gbox);
        b1OpenFile_button->setObjectName("b1OpenFile_button");

        gridLayout_2->addWidget(b1OpenFile_button, 3, 6, 1, 1);

        b1Path_label = new QLabel(b1_gbox);
        b1Path_label->setObjectName("b1Path_label");

        gridLayout_2->addWidget(b1Path_label, 3, 4, 1, 1);

        b1Constrast_label = new QLabel(b1_gbox);
        b1Constrast_label->setObjectName("b1Constrast_label");

        gridLayout_2->addWidget(b1Constrast_label, 1, 4, 1, 1);

        b1Path_lineEdit = new QLineEdit(b1_gbox);
        b1Path_lineEdit->setObjectName("b1Path_lineEdit");

        gridLayout_2->addWidget(b1Path_lineEdit, 3, 5, 1, 1);

        b1Footer_hbox = new QHBoxLayout();
        b1Footer_hbox->setObjectName("b1Footer_hbox");
        b1Footer_spacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        b1Footer_hbox->addItem(b1Footer_spacer);

        b1Reset_button = new QPushButton(b1_gbox);
        b1Reset_button->setObjectName("b1Reset_button");

        b1Footer_hbox->addWidget(b1Reset_button);

        b1Apply_button = new QPushButton(b1_gbox);
        b1Apply_button->setObjectName("b1Apply_button");

        b1Footer_hbox->addWidget(b1Apply_button);


        gridLayout_2->addLayout(b1Footer_hbox, 5, 5, 1, 2);

        b1Brightness_label = new QLabel(b1_gbox);
        b1Brightness_label->setObjectName("b1Brightness_label");

        gridLayout_2->addWidget(b1Brightness_label, 0, 4, 1, 1);

        b1Trim_label = new QLabel(b1_gbox);
        b1Trim_label->setObjectName("b1Trim_label");

        gridLayout_2->addWidget(b1Trim_label, 2, 4, 1, 1);

        b1Preview_button = new QPushButton(b1_gbox);
        b1Preview_button->setObjectName("b1Preview_button");

        gridLayout_2->addWidget(b1Preview_button, 5, 1, 1, 1);

        b1Trim_slider = new QSlider(b1_gbox);
        b1Trim_slider->setObjectName("b1Trim_slider");
        b1Trim_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b1Trim_slider, 2, 5, 1, 2);

        b1Contrast_slider = new QSlider(b1_gbox);
        b1Contrast_slider->setObjectName("b1Contrast_slider");
        b1Contrast_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b1Contrast_slider, 1, 5, 1, 2);

        b1Brightness_slider = new QSlider(b1_gbox);
        b1Brightness_slider->setObjectName("b1Brightness_slider");
        b1Brightness_slider->setValue(50);
        b1Brightness_slider->setSliderPosition(50);
        b1Brightness_slider->setTracking(true);
        b1Brightness_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b1Brightness_slider, 0, 5, 1, 2);

        videoPlayerPlaceholder_label = new QLabel(b1_gbox);
        videoPlayerPlaceholder_label->setObjectName("videoPlayerPlaceholder_label");
        videoPlayerPlaceholder_label->setMinimumSize(QSize(300, 200));
        videoPlayerPlaceholder_label->setAutoFillBackground(true);
        videoPlayerPlaceholder_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(videoPlayerPlaceholder_label, 0, 0, 5, 3);


        verticalLayout->addWidget(b1_gbox);

        addButton_hbox = new QHBoxLayout();
        addButton_hbox->setObjectName("addButton_hbox");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addButton_hbox->addItem(horizontalSpacer_3);

        addButton_button = new QPushButton(scrollAreaWidgetContents);
        addButton_button->setObjectName("addButton_button");

        addButton_hbox->addWidget(addButton_button);


        verticalLayout->addLayout(addButton_hbox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        windowFooter_hbox = new QHBoxLayout();
        windowFooter_hbox->setObjectName("windowFooter_hbox");
        windowFooter_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        windowFooter_hbox->addItem(windowFooter_spacer);

        hologramPreview_button = new QPushButton(centralwidget);
        hologramPreview_button->setObjectName("hologramPreview_button");

        windowFooter_hbox->addWidget(hologramPreview_button);

        export_button = new QPushButton(centralwidget);
        export_button->setObjectName("export_button");

        windowFooter_hbox->addWidget(export_button);


        verticalLayout_2->addLayout(windowFooter_hbox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Last_Project);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuFile->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hologram Configurator", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New...", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExport->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpen_Last_Project->setText(QCoreApplication::translate("MainWindow", "Open Previous Project", nullptr));
        b1_gbox->setTitle(QCoreApplication::translate("MainWindow", "Button #1", nullptr));
        b1OpenFile_button->setText(QCoreApplication::translate("MainWindow", "Open File...", nullptr));
        b1Path_label->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        b1Constrast_label->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        b1Reset_button->setText(QCoreApplication::translate("MainWindow", "Reset Settings", nullptr));
        b1Apply_button->setText(QCoreApplication::translate("MainWindow", "Apply Settings", nullptr));
        b1Brightness_label->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        b1Trim_label->setText(QCoreApplication::translate("MainWindow", "Trim", nullptr));
#if QT_CONFIG(tooltip)
        b1Preview_button->setToolTip(QCoreApplication::translate("MainWindow", "Open video in new window.", nullptr));
#endif // QT_CONFIG(tooltip)
        b1Preview_button->setText(QCoreApplication::translate("MainWindow", "Large Preview", nullptr));
        videoPlayerPlaceholder_label->setText(QCoreApplication::translate("MainWindow", "<VIDEO PLAYER>", nullptr));
        addButton_button->setText(QCoreApplication::translate("MainWindow", "Add Button", nullptr));
        hologramPreview_button->setText(QCoreApplication::translate("MainWindow", "Hologram Preview", nullptr));
        export_button->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
