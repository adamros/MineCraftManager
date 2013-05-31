#include "query.h"

Query::Query(QString address, int port)
{
    this->addr = QHostAddress(address);
    this->port = port;
}

Query::~Query()
{
    delete this->socket;
}
