#include "hashcalc.h"

HashCalc::HashCalc()
{
    this->totalfiles = 0;
    this->completedFiles = 0;
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

        QString hash = QString(QCryptographicHash::hash(tmpFile.readAll(), QCryptographicHash::Md5).toHex());

        hashMap.insert(finfo.path(), hash);
        this->completedFiles++;

        emit progressChanged(this->completedFiles, this->totalfiles);
    }

    emit mapCompleted(this->hashMap);
}

HashCalc::~HashCalc()
{
    hashMap.clear();

    fileQueue.clear();
}