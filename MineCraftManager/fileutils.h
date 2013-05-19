#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QObject>
#include <QtCore>

class FileUtils : public QObject
{
    Q_OBJECT
public:
    explicit FileUtils(QObject *parent = 0);

    void scanDir(const QString dirName);
    
signals:
    
public slots:
    
private:
    QMap<QString, QString> fileMap;
};

#endif // FILEUTILS_H
