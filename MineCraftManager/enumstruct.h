#ifndef ENUMSTRUCT_H
#define ENUMSTRUCT_H

#include <QtCore>

enum ConfigType {
    CONFIG,
    UPDATE
};

enum UpdateType {
    LAUNCHER_CHECK,
    LAUNCHER,
    CLIENT_CHECK,
    CLIENT,
    NONE
};

enum UpdateState {
    IDLE,
    CONNECT,
    CHECK,
    DOWNLOAD,
    BACKUP,
    PREINSTALL,
    INSTALL
};

enum UpdateFlag {
    FORCEUPDATE,
    DELETE,
    REINSTALL,
    KEEP
};

enum XMLSection {
    GENERAL,
    JVM,
    LOCALFILES,
    MAIN,
    FILES
};

struct UpFile {
    QUrl url;
    short type; // 0 - xml data, 1 - files to update
    QString dir;
    QVariant hash;
};

#endif // ENUMSTRUCT_H
