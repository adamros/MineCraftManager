#ifndef QUERY_H
#define QUERY_H

#include <QtCore>
#include <QtNetwork>
#include <exception>

class Query : public QUdpSocket
{
public:
    Query(QHostAddress ip, int port, int timeout = 3);

    void isOnline();
    void getPlayers();
    void getPlayersList();
    void getInfo();

private:
    int STATISTIC = 0x00;
    int HANDSHAKE = 0x09;

    QUdpSocket *socket;
};

#endif // QUERY_H
