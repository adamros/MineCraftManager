#ifndef LAUNCHERCLASS_H
#define LAUNCHERCLASS_H

#include <QtCore>
#include "fileutils.h"
#include <stdlib.h>

class LauncherClass : public QObject
{
    Q_OBJECT
public:
    LauncherClass(QString workingDir, QString username, QString sessionId, QString javaPath = "");
    ~LauncherClass();

    void addParam(QString param);
    void addClasspathLibrary(QString library);
    void addAbsoluteClasspathLibrary(QString library);

    bool launchGame();
private:
    QStringList params;
    QStringList classpath;
    QProcess *jvmProcess;

    QString username;
    QString session;

    QString jvmPath;
    QDir workingDir;

    FileUtils *fileTools;

    bool is64Windows();
};

#endif // LAUNCHERCLASS_H
