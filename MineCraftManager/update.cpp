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
    //this->updateLauncherUrl = "http://download.lixium.pl/launcher/lupdate.xml";
    this->updateLauncherUrl = "http://students.mimuw.edu.pl/~zbyszek/bezp/0102_acl_tcpd/cwiczenia-acl.txt";
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

void Update::doLauncherUpdate(QString file)
{
    Config *launcherUpdate = new Config(UPDATE);
    launcherUpdate->parseFile(file);
}

void Update::doClientUpdate()
{
}

void Update::addToQueue(const UpFile file)
{
    if (downloadQueue.isEmpty())
    {
        QTimer::singleShot(0, this, SLOT(downloadNext()));
        qDebug() << "Timer shot";
    }

    downloadQueue.enqueue(file);
    qDebug() << file.url << " enqueued";
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
    {
        emit sendMessage("information", "Zakończono pobieranie plików");
        return;
    }

    UpFile dequeue = downloadQueue.dequeue();
    qDebug() << "file " << dequeue.url << " dequeued";

    QString filename = getFileName(dequeue.url);
    qDebug() << "filename: " << filename;
    directory.mkpath(dequeue.dir);
    output.setFileName(dequeue.dir + filename);

    if (!output.open(QIODevice::WriteOnly))
    {
        emit sendMessage("error", "Nie można pisać w katalogu aplikacji!");
        downloadNext();
        qDebug() << "file opening failed";
        return;
    }

    QNetworkRequest req(dequeue.url);
    currentDownload = nam->get(req);

    qDebug() << "getting file";

    this->connect(currentDownload, SIGNAL(finished()), this, SLOT(replyFinished()));
    this->connect(currentDownload, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Update::replyFinished()
{
    output.close();

    if (!currentDownload->error())
    {
        ++downloaded;
        qDebug() << "downloaded file";
    }
    else
    {
        emit sendMessage("error", currentDownload->errorString());
        qDebug() << "download error";
    }

    currentDownload->deleteLater();
    downloadNext();
}

void Update::readyRead()
{
    output.write(currentDownload->readAll());
}

QMap<QString,QString> Update::prepareUpdateList(Config *updateConfig)
{
    QMap<QString,QString> updateMap;
    QList<QMap<QString,QString> > localFilesMap = this->configuration->localFiles.values("file");
    QList<QMap<QString,QString> > remoteFilesMap = updateConfig->files.values("file");
}

Update::~Update()
{
    delete this->version;
    delete this->nam;
    delete this;
}
