#include "loginutils.h"

Loginutils::Loginutils()
{
}

void Loginutils::doLogin(QString username, QString password)
{
    nam = new QNetworkAccessManager(this);
    QNetworkRequest req(QUrl("http://login.minecraft.net/"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString data = QString("user=%1&password=%2&version=13").arg(username).arg(password);
    QByteArray postData;
    postData.append(data);

    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    nam->post(req, postData);
}

void Loginutils::playCached(QString username)
{
    if (username.isEmpty() || username.isNull() || username.length() <= 0)
        username = "Player";

    this->username = username;
    this->sessionId = "1";
}

void Loginutils::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QString response = reply->readAll();

        if (!response.contains(":"))
        {
            if (response.contains("Bad login"))
                errCode = 1;
            else if (response.contains("Old version"))
                errCode = 2;
            else if (response.contains("User not premium"))
                errCode = 3;
            else
                errCode = 4;
        }
        else
        {
            errCode = 0;

            QStringList list = response.split(":");
            latestVer = list[0];
            downloadTicket = list[1];
            username = list[2];
            sessionId = list[3];
        }

        emit sendResult(errCode);
    }
    else
        emit sendMessage("error", "Błąd logowania: " + reply->errorString());
}

QString Loginutils::getSID()
{
    return this->sessionId;
}

QString Loginutils::getUsername()
{
    return this->username;
}

Loginutils::~Loginutils()
{
    delete this->nam;
}
