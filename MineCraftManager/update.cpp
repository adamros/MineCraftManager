#include "update.h"

Update::Update()
{
    updateStatus = IDLE;
    ver = 0;
}

bool Update::isCached()
{

}

QString Update::checkUpdates()
{

}

bool Update::checkLauncherUpdate(QString version)
{
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    QNetworkRequest req(QUrl("http://download.lixium.pl/check.php"));

    QString data = QString("version=%1").arg(Version::getVersion());
    QUrl encData = QUrl(data).toEncoded();

    QByteArray postData;
    postData.append(encData);

    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    nam->post(req, postData);

    delete nam;
}

bool Update::downloadFile(QUrl *url, QString filename)
{
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    QNetworkRequest req(&url);

    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*));

    QNetworkReply *reply = nam->get(req);
    QByteArray *data = reply->readAll();

    QFile *fdest = new QFile(filename);

    if (!fdest->open(QFile::WriteOnly))
    {
        qDebug() << "Creating file FAILED!";
    }

    fdest->write(data);

    fdest->close();

    delete nam;
}

void Update::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Download successful!";

        int response = reply->readAll();

        if (response == 0)
        {
            ver = response;
            qDebug() << "No new updates available";
        }
        else ver = response;
    }
    else
        qDebug() << reply->error();
}
