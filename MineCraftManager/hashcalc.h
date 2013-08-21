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

    QMultiMap<QString, QMap<QString, QString> > *hashMap;
    
protected:
    void run();

signals:
    void progressChanged(int completed, int total);
    void mapCompleted();

private:
    QQueue<QFileInfo> fileQueue;

    int totalfiles;
    int completedFiles;
    
};

#endif // HASHCALC_H
