#include "fileutils.h"

FileUtils::FileUtils(Config *config, QObject *parent) :
    QObject(parent)
{
    hashThread = new HashCalc();
    this->config = config;
}

void FileUtils::scanAndCalcHash(QString dirName)
{
    QDir dir(dirName);
    QFileInfoList list = dir.entryInfoList();

    for (int iList = 0; iList < list.count(); iList++)
    {
        QFileInfo info = list[iList];

        QString sFilePath = info.filePath();
        if (info.isDir())
        {
            if (info.fileName()!=".." && info.fileName()!=".")
            {
                this->scanAndCalcHash(sFilePath);
            }
        }
        else
        {
            hashThread->addFile(info);
        }
    }
}

void FileUtils::scanDirectory(QString dirName)
{
    QDir dir(dirName);
    QFileInfoList list = dir.entryInfoList();

    for (int iList = 0; iList < list.count(); iList++)
    {
        QFileInfo info = list[iList];

        QString sFilePath = info.filePath();

        if (info.isFile())
        {
            if (info.fileName()!=".." && info.fileName()!=".")
            {
                files.append(sFilePath);
            }
        }
        else
        {
            if (info.fileName()!=".." && info.fileName()!=".")
                this->scanDirectory(sFilePath);
        }
    }
}

QStringList FileUtils::scanFolder(QString dirName)
{
    this->scanDirectory(dirName);

    return this->files;
}

void FileUtils::addFilesAndScan(QString dirName)
{
    this->scanAndCalcHash(dirName);

    connect(hashThread, SIGNAL(mapCompleted()), this, SLOT(mapAssign()));

    hashThread->start();
}

void FileUtils::mapAssign()
{
    if (this->config->confType == CONFIG)
    {
        this->config->localFiles.clear();
        QList<QMap <QString, QString> > list = this->hashThread->hashMap->values();

        for(int i = 0; i < list.length(); i++)
        {
            this->config->localFiles.insert("file", list.at(i));
        }
    }
}

void FileUtils::initDirectories()
{
    QDir dir;
    dir.mkpath("config/");
    dir.mkpath("client/");
    dir.mkpath("tmp/client/");
    dir.mkpath("tmp/launcher");
}
