#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //Felipe Functions
    void onAddWidgets();
    void addProperties(QWidget * newWidget, QWidget * existingWidget);


private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
