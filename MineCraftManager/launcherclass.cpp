#include "launcherclass.h"

LauncherClass::LauncherClass(QString workingDir, QString username, QString sessionId, QString javaPath)
{
    this->jvmPath = javaPath;
    this->jvmProcess = new QProcess();
    this->username = username;
    this->session = sessionId;
    this->workingDir = workingDir;
    this->fileTools = new FileUtils(NULL);
}

/* Detect 64-bit Windows system (Qt4 is 32-bit if was compiled with MinGW) */
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
        javaConstruct += QDir::toNativeSeparators("\"" +this->jvmPath + "/java\"");
#if defined (Q_WS_WIN)
    else if (is64Windows() && (jvmPath.trimmed().isEmpty() || jvmPath.trimmed() == ""))
    {
        QProcessEnvironment env(QProcessEnvironment::systemEnvironment());
        javaConstruct += QDir::toNativeSeparators(env.value("windir") + "/sysnative/javaw.exe");
    }
#endif
    else javaConstruct += "java";

    QStringList classList = fileTools->scanFolder("C:\\Users\\Adam\\AppData\\Roaming\\.minecraft\\libraries");

    foreach (QString file, classList)
    {
        addAbsoluteClasspathLibrary(file);
    }

    addAbsoluteClasspathLibrary("C:\\Users\\Adam\\AppData\\Roaming\\.minecraft\\versions\\1.6.2\\1.6.2.jar");

    addParam("-Djava.library.path=\"" + QDir::toNativeSeparators(this->workingDir.absoluteFilePath(".minecraft/versions/1.6.2/natives")) + "\"");
    addParam("-Duser.home=\"" + QDir::toNativeSeparators(this->workingDir.absolutePath()) + "\"");
    addParam("-cp \"" + this->classpath.join(";") + "\"");
    addParam("net.minecraft.client.main.Main");

    if (this->username.trimmed().isEmpty() || this->username.trimmed() == "" || this->session.trimmed().isEmpty() || this->session.trimmed() == "")
        return false;

    addParam("--username " + this->username);
    addParam("--session " + this->session);
    addParam("--version 1.6.2");
    addParam("--gameDir " + QDir::toNativeSeparators(this->workingDir.absoluteFilePath(".minecraft/")));
    addParam("--assetsDir " + QDir::toNativeSeparators(this->workingDir.absoluteFilePath(".minecraft/assets")));

#if defined(Q_WS_WIN) || defined(Q_WS_WIN32)
    qputenv("APPDATA", QDir::toNativeSeparators(this->workingDir.absolutePath()).trimmed().toAscii());
#endif

    foreach(QString parameter, this->params)
        javaConstruct += " " + parameter;

    bool started = this->jvmProcess->startDetached(javaConstruct);

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

void LauncherClass::addAbsoluteClasspathLibrary(QString library)
{
    this->classpath.push_back(QDir::toNativeSeparators(library));
}

LauncherClass::~LauncherClass()
{
    //delete this->jvmProcess;
}
