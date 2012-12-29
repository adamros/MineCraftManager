#include "config.h"

Config::Config()
{
}

void Config::createConfig()
{

}

void Config::updateConfig()
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

void Config::readConfig()
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

    QDomElement docElement = doc.documentElement();
    QDomNodeList docNodeList = docElement.elementsByTagName("general").firstChild();

    while( !docNodeList.isNull() )
    {
        if( docNodeList.isElement() )
        {
          QDomElement element = docNodeList.toElement();
          qDebug() << "ELEMENT" << element.tagName();
          qDebug() << "ELEMENT ATTRIBUTE NAME" << element.attribute( "name", "not set" );
        }

        if( docNodeList.isText() )
        {
          QDomText text = docNodeList.toText();
          qDebug() << text.data();
        }

        docNodeList = docNodeList.nextSibling();
    }
}
