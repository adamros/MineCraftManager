#include "hashcalc.h"

HashCalc::HashCalc()
{
    this->totalfiles = 0;
    this->completedFiles = 0;
    this->hashMap = new QMultiMap<QString, QMap<QString, QString> >;
}

void HashCalc::addFile(QFileInfo &file)
{
    fileQueue.enqueue(file);
    this->totalfiles++;
}

void HashCalc::run()
{
    while (!fileQueue.empty())
    {
        QFileInfo finfo = fileQueue.dequeue();
        QFile tmpFile(finfo.filePath());
        if (tmpFile.open(QIODevice::ReadOnly))
        {
            QString hash = QString(QCryptographicHash::hash(tmpFile.readAll(), QCryptographicHash::Md5).toHex());

            QMap<QString, QString> map;
            map.insert("text", finfo.filePath());
            map.insert("checksum", hash);

            hashMap->insert("file", map);

            map.clear();
            tmpFile.close();
            this->completedFiles++;
        }

        emit progressChanged(this->completedFiles, this->totalfiles);
    }
    emit mapCompleted();
}

HashCalc::~HashCalc()
{
    //hashMap.clear();
    delete hashMap;
    fileQueue.clear();
}
