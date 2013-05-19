#include "fileutils.h"

FileUtils::FileUtils(QObject *parent) :
    QObject(parent)
{
}

void FileUtils::scanDir(const QString dirName)
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
                this->scanDir(sFilePath);
            }
        }
        else
        {
            //qDebug() << "Path: " << info.filePath() << " Name: " << info.fileName() << endl;
        }
    }
}
