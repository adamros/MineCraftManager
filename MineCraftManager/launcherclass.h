#ifndef LAUNCHERCLASS_H
#define LAUNCHERCLASS_H

#include <QtCore>

class LauncherClass
{
public:
    LauncherClass();

    void addParam(QString param);
    void setJVMPath(QString path);
    void setWorkingDir(QString dir);
    void setUsername(QString nick);
    void setSessionID(QString sid);

    bool launchGame();
private:
    QStringList params;
    QProcess *jvmProcess;

    QString username;
    QString session;

    QString jvmPath;
    QDir workingDir;
};

#endif // LAUNCHERCLASS_H
