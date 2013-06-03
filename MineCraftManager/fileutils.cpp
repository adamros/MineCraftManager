#include "fileutils.h"

FileUtils::FileUtils(QObject *parent) :
    QObject(parent)
{
    hashThread = new HashCalc();
}

HashCalc* FileUtils::scanAndCalcHash(QString dirName)
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

    hashThread->start();

    return this->hashThread;
}

void FileUtils::initDirectories()
{
    QDir dir;
    dir.mkpath("config/");
    dir.mkpath("client/");
    dir.mkpath("tmp/client/");
    dir.mkpath("tmp/launcher");
}
