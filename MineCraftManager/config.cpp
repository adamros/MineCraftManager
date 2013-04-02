#include "config.h"

Config::Config()
{
}

bool Config::createConfig()
{

}

bool Config::updateConfig()
{
    QDomDocument doc("configuration");
    QFile file("config.xml");

    if (!file.open(QIODevice::WriteOnly))
        return;

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }

    file.close();
}

bool Config::readConfig()
{
    QDomDocument doc("configuration");
    QFile file("config.xml");

    if (!file.open(QIODevice::ReadOnly))
        return;

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }

    file.close();

    QDomElement root = doc.documentElement();

    if (root.tagName() != "mcm")
        qDebug() << "XML configuration file not valid!";

    QDomElement general = root.firstChildElement("general");
    QDomElement generalChild = general.firstChildElement();

    while (!generalChild.isNull())
    {
        if (generalChild.tagName() == "")
    }
}
