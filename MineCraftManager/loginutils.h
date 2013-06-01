#ifndef LOGINUTILS_H
#define LOGINUTILS_H

#include <QtCore>
#include <QtNetwork/QtNetwork>

class Loginutils : public QObject
{
    Q_OBJECT
public:
    Loginutils();
    ~Loginutils();

    void doLogin(QString username, QString password);
    void playCached(QString username);

    QString getSID();
    QString getUsername();

signals:
    void sendResult(int i);
    void sendMessage(QString type, QString message);

private:
    QNetworkAccessManager *nam;

    short errCode;

    QString latestVer;
    QString downloadTicket;
    QString username;
    QString sessionId;

private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // LOGINUTILS_H
