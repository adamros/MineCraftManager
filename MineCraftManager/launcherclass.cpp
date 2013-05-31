#include "launcherclass.h"

LauncherClass::LauncherClass()
{
    this->jvmPath = "";
    this->jvmProcess = new QProcess();
    this->username = "";
    this->session = "";
}

bool LauncherClass::launchGame()
{
    this->jvmProcess->setWorkingDirectory(this->workingDir.path());

    QString javaConstruct = "";

    if (!jvmPath.trimmed().isEmpty() || jvmPath.trimmed() != "")
        javaConstruct += this->jvmPath + " ";

    javaConstruct += "java";

    addParam("-cp \"bin/minecraft.jar:bin/jinput.jar:bin/lwjgl.jar:bin/lwjgl_util.jar\"");
    addParam("-Dorg.lwjgl.librarypath=\"bin/natives\"");
    addParam("-Dnet.java.games.input.librarypath=\"bin/natives\"");
    addParam("net.minecraft.client.Minecraft");

    if (this->username.trimmed().isEmpty() || this->username.trimmed() == "" || this->session.trimmed().isEmpty() || this->session.trimmed() == "")
        return false;

    addParam(this->username);
    addParam(this->session);

    return this->jvmProcess->startDetached(javaConstruct, this->params);
}

void LauncherClass::addParam(QString param)
{
    this->params.push_back(param);
}

void LauncherClass::setJVMPath(QString path)
{
    this->jvmPath = path;
}

void LauncherClass::setWorkingDir(QString dir)
{
    this->workingDir = QDir::toNativeSeparators(dir);
}

void LauncherClass::setUsername(QString nick)
{
    this->username = nick;
}

void LauncherClass::setSessionID(QString sid)
{
    this->session = sid;
}
