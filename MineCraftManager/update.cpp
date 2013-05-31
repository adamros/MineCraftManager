#include "update.h"

Update::Update(UpdateType type, Config *configuration) : downloaded(0), total(0)
{
    this->updateStatus = IDLE;
    this->upType = type;
    this->configuration = configuration;
    this->version = new Version();
    this->nam = new QNetworkAccessManager(this);
    this->parser = new Config(UPDATE);
    this->updateClientUrl = "http://download.lixium.pl/launcher/client/cupdate.xml";
    this->updateLauncherUrl = "http://download.lixium.pl/launcher/lupdate.xml";
}

void Update::checkLauncherUpdate()
{
    UpFile *xml = new UpFile();
    xml->url = this->updateLauncherUrl;
    xml->type = 0;
    xml->dir = "tmp/";
    xml->hash = NULL;

    this->addToQueue(*xml);
    delete xml;
}

void Update::checkClientUpdate()
{
    UpFile *xml = new UpFile();
    xml->url = this->updateClientUrl;
    xml->type = 0;
    xml->dir = "tmp/";
    xml->hash = NULL;

    this->addToQueue(*xml);
    delete xml;
}

void Update::doLauncherUpdate()
{
}

void Update::doClientUpdate()
{

}

void Update::addToQueue(const UpFile file)
{
    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SLOT(downloadNext()));

    downloadQueue.enqueue(file);
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

    UpFile dequeue = downloadQueue.dequeue();

    QString filename = getFileName(dequeue.url);
    directory.mkpath(dequeue.dir);
    output.setFileName(dequeue.dir + filename);

    if (!output.open(QIODevice::WriteOnly))
    {
        emit sendMessage("error", "Nie można pisać w katalogu aplikacji!");
        downloadNext();
        return;
    }

    QNetworkRequest req(dequeue.url);
    currentDownload = nam->get(req);

    this->connect(currentDownload, SIGNAL(finished()), this, SLOT(replyFinished()));
    this->connect(currentDownload, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Update::replyFinished()
{
    output.close();

    if (!currentDownload->error())
    {
        ++downloaded;
    }
    else
        emit sendMessage("error", currentDownload->errorString());

    currentDownload->deleteLater();
    downloadNext();
}

void Update::readyRead()
{
    output.write(currentDownload->readAll());
}

Update::~Update()
{
    delete this->version;
    delete this->nam;
    delete this;
}
