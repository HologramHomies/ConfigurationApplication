/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *videoPathLabel_1;
    QPushButton *browseButton_1;
    QCheckBox *checkBox_1;
    QComboBox *comboBox;
    QLabel *buttonIDLabel_1;
    QLineEdit *videoPathLine_1;
    QPushButton *addVideoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 110, 498, 147));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        videoPathLabel_1 = new QLabel(verticalLayoutWidget);
        videoPathLabel_1->setObjectName("videoPathLabel_1");

        gridLayout->addWidget(videoPathLabel_1, 2, 1, 1, 1);

        browseButton_1 = new QPushButton(verticalLayoutWidget);
        browseButton_1->setObjectName("browseButton_1");

        gridLayout->addWidget(browseButton_1, 2, 4, 1, 1);

        checkBox_1 = new QCheckBox(verticalLayoutWidget);
        checkBox_1->setObjectName("checkBox_1");

        gridLayout->addWidget(checkBox_1, 1, 0, 1, 1);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        buttonIDLabel_1 = new QLabel(verticalLayoutWidget);
        buttonIDLabel_1->setObjectName("buttonIDLabel_1");

        gridLayout->addWidget(buttonIDLabel_1, 1, 1, 1, 1);

        videoPathLine_1 = new QLineEdit(verticalLayoutWidget);
        videoPathLine_1->setObjectName("videoPathLine_1");
        videoPathLine_1->setMinimumSize(QSize(200, 0));
        videoPathLine_1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(videoPathLine_1, 2, 2, 1, 2);


        verticalLayout->addLayout(gridLayout);

        addVideoButton = new QPushButton(verticalLayoutWidget);
        addVideoButton->setObjectName("addVideoButton");

        verticalLayout->addWidget(addVideoButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        videoPathLabel_1->setText(QCoreApplication::translate("MainWindow", "Video Path", nullptr));
        browseButton_1->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        checkBox_1->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        buttonIDLabel_1->setText(QCoreApplication::translate("MainWindow", "Button ID: ", nullptr));
        addVideoButton->setText(QCoreApplication::translate("MainWindow", "Add Video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
