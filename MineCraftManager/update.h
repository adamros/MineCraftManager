#ifndef UPDATE_H
#define UPDATE_H

#include <QtCore>
#include <QtNetwork>

#include "version.h"
#include "config.h"

class Update : public QObject
{
    Q_OBJECT
public:
    Update(UpdateType type, Config *configuration);
    ~Update();

    UpdateState updateStatus;
    UpdateType upType;

    Version *version;

    QString getFileName(const QUrl &url);
    void addToQueue(const UpFile file);

    void checkLauncherUpdate();
    void doLauncherUpdate();
    void checkClientUpdate();
    void doClientUpdate();

signals:
    void sendMessage(QString type, QString message);
    void notifyUpdate(QString type);

private:
    QUrl updateClientUrl;
    QUrl updateLauncherUrl;

    QNetworkAccessManager *nam;
    QQueue<UpFile> downloadQueue;
    QNetworkReply *currentDownload;
    QFile output;
    int downloaded, total;
    Config *parser;
    Config *configuration;

    QDir directory;

private slots:
    void replyFinished();
    void readyRead();
    void downloadNext();
};

#endif // UPDATE_H
