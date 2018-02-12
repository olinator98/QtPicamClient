#include "client.h"
#include <QDataStream>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>

Client::Client(QObject *parent)
{

}

void Client::connectToHost(QString host, QByteArray password)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(host, 12345);

    socket->write(password);


}

bool Client::writeData(QByteArray data)
{
}

void Client::takeImage(QByteArray para)
{
    socket->write(para);
}

void Client::getImage()
{
    QBuffer *imageBuffer = new QBuffer();
    imageBuffer->open(QBuffer::ReadWrite);
    qint64 bytes = imageBuffer->write(socket->readAll());
    imageBuffer->seek(imageBuffer->pos() - bytes);
    recvdImage.loadFromData(imageBuffer->buffer());
    if(!recvdImage.isNull())
    {
        qDebug()<<"image received";
    }

    QPixmap item(QPixmap::fromImage(recvdImage));
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addPixmap(item);
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    view->show();
}


