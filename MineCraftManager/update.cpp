#include "update.h"

Update::Update(Type type) : QObject(parent), downloaded(0), total(0)
{
    updateStatus = IDLE;
    upType = type;
    version = new Version();
    nam = new QNetworkAccessManager(this);
    parser = new Config(Config::UPDATE);
    updateLauncherUrl = "http://download.lixium.pl/launcher/client/cupdate.xml";
    updateClientUrl = "http://download.lixium.pl/launcher/lupdate.xml";
}

void Update::checkLauncherUpdate()
{

}

void Update::chechClientUpdate()
{

}

void Update::doLauncherUpdate()
{

}

void Update::doClientUpdate()
{

}

void Update::addToQueue(const QUrl &url)
{
    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SLOT(downloadNext()));

    //downloadQueue.enqueue(url);
    ++total;
}

QString Update::getFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    return basename;
}

void Update::downloadNext()
{
    if (downloadQueue.isEmpty())
        emit sendMessage("information", "Zakończono pobieranie plików");

    UpFile *dequeue = downloadQueue.dequeue();

    QString filename = getFileName(dequeue->url);
}

void Update::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        ++downloaded;
    }
    else
        emit sendMessage("error", reply->errorString());

    currentDownload->deleteLater();
}

Update::~Update()
{
    delete this->version;
    delete this->nam;
    delete this;
}
