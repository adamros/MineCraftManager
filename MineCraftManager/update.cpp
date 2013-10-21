#include "update.h"

Update::Update(UpdateType type, Config *configuration) : downloaded(0), total(0)
{
    this->updateStatus = IDLE;
    this->upType = type;
    this->configuration = configuration;
    this->version = new Version();
    this->nam = new QNetworkAccessManager(this);
    this->parser = new Config(UPDATE);
    this->updateClientUrl = "http://lixium.pl/download/launcher/client/cupdate.xml";
    //this->updateLauncherUrl = "http://download.lixium.pl/launcher/lupdate.xml";
    this->updateLauncherUrl = "http://students.mimuw.edu.pl/~zbyszek/bezp/0102_acl_tcpd/cwiczenia-acl.txt";
}

void Update::checkLauncherUpdate()
{
    UpFile *xml = new UpFile();
    xml->url = this->updateLauncherUrl;
    xml->type = 0;
    xml->dir = "tmp/";
    xml->hash = 0;

    this->addToQueue(*xml);
    delete xml;
}

void Update::checkClientUpdate()
{
    UpFile *xml = new UpFile();
    xml->url = this->updateClientUrl;
    xml->type = 0;
    xml->dir = "tmp/";
    xml->hash = 0;

    this->addToQueue(*xml);
    delete xml;
}

void Update::doLauncherUpdate(QString file)
{
    Config *launcherUpdate = new Config(UPDATE);
    launcherUpdate->parseFile(file);

    filesToDownload = prepareUpdateList(launcherUpdate);

    QList<QMap<QString, QString> > fileList = filesToDownload.values();

    for (int i = 0; i < fileList.count(); i++)
    {
        foreach (QString key, fileList.at(i).keys())
        {
            UpFile *fDownload = new UpFile();
            fDownload->type = 1;
            fDownload->dir = "tmp/launcher/";

            if (key == "url")
                fDownload->url = fileList.at(i).value(key);
            else if (key == "checksum")
                fDownload->hash = fileList.at(i).value(key);
            else {
                delete fDownload;
                break;
            }

            this->addToQueue(*fDownload);
            delete fDownload;
        }
    }
}

void Update::doClientUpdate(QString file)
{
    Config *clientUpdate = new Config(UPDATE);
    clientUpdate->parseFile(file);
    filesToDownload = prepareUpdateList(clientUpdate);

    for (int i = 0; filesToDownload.count(); i++)
        qDebug() << filesToDownload.value("file") << endl;
/*
    QList<QMap<QString, QString> > fileList = filesToDownload.values();

    for (int i = 0; i < fileList.count(); i++)
    {
        foreach (QString key, fileList.at(i).keys())
        {
            UpFile *fDownload = new UpFile();
            fDownload->type = 1;
            fDownload->dir = "tmp/client/";

            if (key == "url")
                fDownload->url = fileList.at(i).value(key);
            else if (key == "checksum")
                fDownload->hash = fileList.at(i).value(key);
            else {
                delete fDownload;
                break;
            }

            this->addToQueue(*fDownload);
            delete fDownload;
        }
    } */
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
        processFlags();
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

QMultiMap<QString, QMap<QString, QString> > Update::prepareUpdateList(Config *updateConfig)
{
    QMapIterator<QString, QMap<QString, QString> > localIterator(this->configuration->localFiles);
    QMapIterator<QString, QMap<QString, QString> > remoteIterator(updateConfig->files);

    QMap<QString, UpdateFlag> tmpMap;
    QMapIterator<QString, UpdateFlag> tmpIterator(tmpMap);

    QMultiMap<QString, QMap<QString, QString> > finalMap;

    while (remoteIterator.hasNext())
    {
        remoteIterator.next();

        QMap<QString, QString> loopMap = remoteIterator.value();

        tmpMap.insert(loopMap.value("text"), FORCEUPDATE);
    }

    while (localIterator.hasNext())
    {
        localIterator.next();

        QMap<QString, QString> loopMap = localIterator.value();

        if (tmpMap.contains(loopMap.value("text")))
        {
            while (remoteIterator.hasNext() && (remoteIterator.value().value("text") != loopMap.value("text")))
            {
                remoteIterator.next();

                QMap<QString, QString> loopMapInt = remoteIterator.value();

                if (loopMap.value("checksum") == loopMapInt.value("checksum"))
                    tmpMap.insert(loopMap.value("text"), KEEP);
            }
        }
        else {
            tmpMap.insert(loopMap.value("text"), DELETE);
        }
    }

    while (tmpIterator.hasNext())
    {
        tmpIterator.next();

        QMap<QString, QString> loopMap;

        remoteIterator.toFront();

        while (remoteIterator.hasNext())
        {
            remoteIterator.next();

            QMap<QString, QString> tmpLoop = remoteIterator.value();

            if (tmpLoop.value("text") == tmpIterator.key())
                loopMap = tmpLoop;
        }

        finalMap.insertMulti("file", loopMap);
    }

    fileFlags = tmpMap;

    return finalMap;
}

void Update::processFlags()
{
    QMapIterator<QString, UpdateFlag> iter(fileFlags);

    while (iter.hasNext())
    {
        iter.next();

        if (iter.value() == DELETE)
        {
            qDebug() << QFile(iter.key()).remove();
        }
    }
}

Update::~Update()
{
    delete this->version;
    delete this->nam;
    delete this;
}
