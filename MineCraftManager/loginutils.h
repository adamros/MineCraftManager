#ifndef LOGINUTILS_H
#define LOGINUTILS_H

#include <QtCore>
#include <QtNetwork/QtNetwork>

class Loginutils : public QObject
{
public:
    Loginutils();

    void doLogin(QString username, QString password);
    void playCached(QString username, bool demo);

    short getErrorCode();
    QString getSID();

private:
    short errCode;

    bool demo;
    QString latestVer;
    QString downloadTicket;
    QString username;
    QString sessionId;

private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // LOGINUTILS_H
