#include "launcherclass.h"

LauncherClass::LauncherClass(QString workingDir, QString username, QString sessionId, QString javaPath)
{
    this->jvmPath = javaPath;
    this->jvmProcess = new QProcess();
    this->username = username;
    this->session = sessionId;
    this->workingDir = workingDir;
}

/* Detect 64-bit Windows system (Qt4 is 32-bit when compiled with MinGW) */
bool LauncherClass::is64Windows()
{
#if defined (Q_WS_WIN)
    QProcessEnvironment env(QProcessEnvironment::systemEnvironment());
    QString nativeDir = QDir::toNativeSeparators(env.value("windir") + "/sysnative");
    return QDir(nativeDir).exists();
#else
    return false;
#endif
}

bool LauncherClass::launchGame()
{
    QString javaConstruct = "";

    if (!jvmPath.trimmed().isEmpty() || jvmPath.trimmed() != "")
        javaConstruct += QDir::toNativeSeparators("\"" + this->jvmPath + "\"/" + "javaw");
#if defined (Q_WS_WIN)
    else if (is64Windows() && (jvmPath.trimmed().isEmpty() || jvmPath.trimmed() == ""))
    {
        QProcessEnvironment env(QProcessEnvironment::systemEnvironment());
        javaConstruct += QDir::toNativeSeparators(env.value("windir") + "/sysnative/javaw.exe");
    }
#endif
    else javaConstruct += "javaw";

    addClasspathLibrary("bin/minecraft.jar");
    addClasspathLibrary("bin/lwjgl.jar");
    addClasspathLibrary("bin/lwjgl_util.jar");
    addClasspathLibrary("bin/jinput.jar");

    addParam("-cp \"" + this->classpath.join(";") + "\"");
    addParam("-Dorg.lwjgl.librarypath=\"" + QDir::toNativeSeparators(this->workingDir.absoluteFilePath(".minecraft/bin/natives")) + "\"");
    addParam("-Dnet.java.games.input.librarypath=\"" + QDir::toNativeSeparators(this->workingDir.absoluteFilePath(".minecraft/bin/natives")) + "\"");
    addParam("-Duser.home=\"" + QDir::toNativeSeparators(this->workingDir.absolutePath()) + "\"");
    addParam("net.minecraft.client.Minecraft");

    if (this->username.trimmed().isEmpty() || this->username.trimmed() == "" || this->session.trimmed().isEmpty() || this->session.trimmed() == "")
        return false;

    addParam(this->username);
    addParam(this->session);

#if defined(Q_WS_WIN) || defined(Q_WS_WIN32)
    qputenv("APPDATA", QDir::toNativeSeparators(this->workingDir.absolutePath()).trimmed().toAscii());
#endif

    QString oldWDir = QDir::current().absolutePath();
    QDir::setCurrent(QDir::toNativeSeparators(this->workingDir.path()));

    qDebug() << javaConstruct;

    foreach(QString parameter, this->params)
        javaConstruct += " " + parameter;

    bool started = this->jvmProcess->startDetached(javaConstruct);

    QDir::setCurrent(QDir::toNativeSeparators(oldWDir));

    return started;
}

void LauncherClass::addParam(QString param)
{
    this->params.push_back(param);
}

void LauncherClass::addClasspathLibrary(QString library)
{
    QDir file(QDir::toNativeSeparators(this->workingDir.absolutePath()));
    this->classpath.push_back(QDir::toNativeSeparators(file.absoluteFilePath(".minecraft/" + library)));
}

LauncherClass::~LauncherClass()
{
    delete this->jvmProcess;
}
