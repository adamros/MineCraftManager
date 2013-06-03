#ifndef LAUNCHERCLASS_H
#define LAUNCHERCLASS_H

#include <QtCore>
#include <stdlib.h>

class LauncherClass : public QObject
{
    Q_OBJECT
public:
    LauncherClass(QString workingDir, QString username, QString sessionId, QString javaPath = "");
    ~LauncherClass();

    void addParam(QString param);
    void addClasspathLibrary(QString library);

    bool launchGame();
private:
    QStringList params;
    QStringList classpath;
    QProcess *jvmProcess;

    QString username;
    QString session;

    QString jvmPath;
    QDir workingDir;
};

#endif // LAUNCHERCLASS_H
