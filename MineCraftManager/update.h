#ifndef UPDATE_H
#define UPDATE_H

#include <QtCore>
#include <QtNetwork>

#include "version.h"

class Update
{
public:
    Update();

    bool downloadLauncherUpdate();
    bool checkLauncherUpdate();

    enum UpState {
        IDLE,
        CONNECT,
        CHECK,
        DOWNLOAD,
        BACKUP,
        PREINSTALL,
        INSTALL
    };

    UpState *updateStatus;

    bool checkUpdate();
    bool updateClient();
    bool selfUpdate();

    bool downloadFile(QUrl *url, QString filename);

private:
    QUrl updateInfoUrl;

    int ver;

private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // UPDATE_H
