#include "query.h"

Query::Query(QHostAddress ip, int port, int timeout)
{
    if (port == 0 || timeout <= 0)
        return;

    socket = new QUdpSocket();

    try {
        socket->bind(ip, port);
    }
    catch (SocketError)
    {
        socket->close();
    }

    if (!socket || socket->error())
        return;

    socket->close();
}
