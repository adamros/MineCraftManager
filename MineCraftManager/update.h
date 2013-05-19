#ifndef UPDATE_H
#define UPDATE_H

#include <QtCore>
#include <QtNetwork>

#include "version.h"
#include "config.h"

class Update : public QObject
{
public:
    Update(Type type);
    ~Update();

    enum UpState {
        IDLE,
        CONNECT,
        CHECK,
        DOWNLOAD,
        BACKUP,
        PREINSTALL,
        INSTALL
    };

    enum Type {
        LAUNCHER_CHECK,
        LAUNCHER,
        CLIENT_CHECK,
        CLIENT,
        NONE
    };

    UpState updateStatus;
    Type upType;

    Version *version;

    QString getFileName(const QUrl &url);
    void addToQueue(const UpFile *file);

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

    struct UpFile {
        QUrl &url;
        short type; // 0 - xml data, 1 - files to update
        QString dir;
        QVariant hash;
    };

private slots:
    void replyFinished();
    void readyRead();
    void downloadNext();
};

#endif // UPDATE_H
