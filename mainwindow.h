#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_connect_clicked();

    void on_btn_picture_clicked();

    void on_btn_showImage_clicked();

private:
    Ui::MainWindow *ui;
    Client *client;
    QString verticalRotation;
    QString horizontalRotation;
    QString exposure;
    QString resolution;

    QString infraredOn;
    QString takePic;
    QString closeConnection;
    QString restartServer;
};

#endif // MAINWINDOW_H
