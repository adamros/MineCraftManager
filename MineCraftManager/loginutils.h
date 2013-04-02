#ifndef LOGINUTILS_H
#define LOGINUTILS_H

#include <QtCore>
#include <QtNetwork/QtNetwork>

class Loginutils
{
public:
    Loginutils();

    void doLogin(QString username, QString password);
    void playCached(QString username, bool demo);

protected:
    short errCode;

    bool demo;
    QVariant latestVer;
    QString downloadTicket;
    QString username;
    QVariant sessionId;

private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // LOGINUTILS_H
