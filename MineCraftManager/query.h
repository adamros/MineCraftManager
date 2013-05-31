#ifndef QUERY_H
#define QUERY_H

#include <QtCore>
#include <QtNetwork>
#include <exception>

class Query : public QUdpSocket
{
public:
    Query(QString address, int port);
    ~Query();

    void isOnline();
    void getPlayers();
    void getPlayersList();
    void getInfo();

private:
    QUdpSocket *socket;

    static const char HANDSHAKE;
    static const char STAT;

    QHostAddress addr;
    int port;
};

#endif // QUERY_H
