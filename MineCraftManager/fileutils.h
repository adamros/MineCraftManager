#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QObject>
#include <QtCore>

#include "hashcalc.h"
#include "enumstruct.h"
#include "config.h"

class FileUtils : public QObject
{
    Q_OBJECT
public:
    explicit FileUtils(Config *config, QObject *parent = 0);

    void addFilesAndScan(QString dirName = "");
    static void initDirectories();
    QStringList scanFolder(QString dirName);
    
private slots:
    void mapAssign();
    
private:
    HashCalc *hashThread;
    QMultiMap<QString, QMap<QString, QString> > fileMap;
    Config *config;

    QStringList files;

    void scanAndCalcHash(QString dirName = "");
    void scanDirectory(QString dirName);
};

#endif // FILEUTILS_H
