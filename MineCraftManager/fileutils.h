#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QObject>
#include <QtCore>

#include "hashcalc.h"

class FileUtils : public QObject
{
    Q_OBJECT
public:
    explicit FileUtils(QObject *parent = 0);

    void scanDir(QString dirName = "");
    
signals:
    
public slots:
    
private:
    HashCalc *hashThread;
    QMap<QString, QString> fileMap;
};

#endif // FILEUTILS_H
