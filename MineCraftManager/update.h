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
    void addToQueue(const QUrl &url);

    void checkLauncherUpdate();
    void doLauncherUpdate();
    void chechClientUpdate();
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

    struct UpFile {
        QUrl &url;
        QString dir;
        QString hash;
    };

private slots:
    void replyFinished(QNetworkReply *reply);
    void downloadNext();
};

#endif // UPDATE_H
