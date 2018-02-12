#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked()
{
        client = new Client();

        client->connectToHost("10.1.1.10", "theNextLevel");
        ui->lbl_state->setText("connected");


}

void MainWindow::on_btn_picture_clicked()
{
    (ui->verticalRotation->isChecked())?(verticalRotation = "1"):(verticalRotation = "0");
    (ui->horizontalRotation->isChecked())?(horizontalRotation = "1"):(horizontalRotation = "0");
    (ui->exposure->isChecked())?(exposure = "1"):(exposure = "0");
    (ui->resolution->isChecked())?(resolution = "1"):(resolution = "0");
    (ui->infraredOn->isChecked())?(infraredOn = "1"):(infraredOn = "0");

    takePic = "1"; //Because user clicked take pic button

    (ui->closeConnection->isChecked())?(closeConnection = "1"):(closeConnection = "0");
    (ui->restartServer->isChecked())?(restartServer = "1"):(restartServer = "0");

    QString command =verticalRotation+horizontalRotation+exposure+resolution+infraredOn+takePic+closeConnection+restartServer;
    qDebug()<<command; //Executed reversed on the server
    QByteArray arr = command.toUtf8();
    client->takeImage(arr);
}

void MainWindow::on_btn_showImage_clicked()
{
    client->getImage();
}
