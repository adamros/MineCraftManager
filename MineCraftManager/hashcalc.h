#ifndef HASHCALC_H
#define HASHCALC_H

#include <QThread>
#include <QtCore>

class HashCalc : public QThread
{
    Q_OBJECT
public:
    HashCalc();
    ~HashCalc();

    void addFile(QFileInfo &file);
    
protected:
    void run();

signals:
    void progressChanged(int completed, int total);
    void mapCompleted(QMap<QString, QString> &map);

private:
    QQueue<QFileInfo> fileQueue;

    QMap<QString, QString> hashMap;

    int totalfiles;
    int completedFiles;
    
};

#endif // HASHCALC_H
