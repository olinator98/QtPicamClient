#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QBuffer>
#include <QImage>


class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = 0);
    QTcpSocket *socket;
    void getImage();
    QImage recvdImage;

public slots:
    void connectToHost(QString host, QByteArray password);
    bool writeData(QByteArray data);
    void takeImage(QByteArray para);

private:
    bool passwordSuccessfull;



};

#endif // CLIENT_H
