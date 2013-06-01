#include "config.h"

Config::Config()
{
    confType = UPDATE;
}

Config::Config(ConfigType type)
{
    confType = type;
}

void Config::parseFile(QString filename)
{
    QFile *file = new QFile(filename);

    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit sendMessage("error", file->errorString());
        qDebug() << "Cant load xml file";
        return;
    }

    QXmlStreamReader *xmlReader = new QXmlStreamReader(file->readAll());
    file->close();

    while (!xmlReader->atEnd() && !xmlReader->hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();

        if (token == QXmlStreamReader::StartDocument)
            continue;

        if (token == QXmlStreamReader::StartElement)
        {
            if (xmlReader->name() == "general" || xmlReader->name() == "jvm" || xmlReader->name() == "main" || xmlReader->name() == "files")
            {
                this->currentNode = xmlReader->name().toString();
                this->parseElement(xmlReader);
            }
        }
    }

    xmlReader->clear();
    delete xmlReader;
    delete file;
}

void Config::parseElement(QXmlStreamReader *xml)
{
    xml->readNext();
    while (!(xml->isEndElement() && xml->name() == currentNode))
    {
        if (xml->isStartElement())
        {
            QMap<QString, QString> tempAttr;
            QXmlStreamAttributes attributes = xml->attributes();

            foreach (QXmlStreamAttribute attribute, attributes) {
                tempAttr.insert(attribute.name().toString(), attribute.value().toString());
            }

            QString txtElement = xml->readElementText();
            tempAttr.insert("text", txtElement);

            if (this->currentNode == "general")
            {
                this->general.insert(xml->name().toString(), tempAttr);
            }
            else if (this->currentNode == "jvm")
            {
                this->jvm.insert(xml->name().toString(), tempAttr);
            }
            else if (this->currentNode == "main")
            {
                this->main.insert(xml->name().toString(), tempAttr);
            }
            else if (this->currentNode == "files")
            {
                this->files.insert(xml->name().toString(), tempAttr);
            }
            else {
                continue;
            }
        }
        else xml->readNext();
    }
}

void Config::writeFile(QString filename)
{
    QFile *file = new QFile(filename);

    if (!file->open(QIODevice::WriteOnly))
    {
        emit sendMessage("error", file->errorString());
        return;
    }

    QXmlStreamWriter *xmlWriter = new QXmlStreamWriter();
    xmlWriter->setDevice(file);
    xmlWriter->setAutoFormatting(true);
    xmlWriter->writeStartDocument();

    if (this->confType == CONFIG)
    {
        // General section
        xmlWriter->writeStartElement("general");

        foreach (QString key, general.keys())
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, general.value(key).keys())
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(general.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, general.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();

        // JVM section
        xmlWriter->writeStartElement("jvm");

        foreach (QString key, jvm.keys())
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, jvm.value(key).keys())
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(jvm.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, jvm.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();

        // Localfiles section
        xmlWriter->writeStartElement("localfiles");

        foreach (QString key, files.keys())
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, files.value(key).keys())
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(files.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, files.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();
    }
    else if (this->confType == UPDATE)
    {
        // Main section
        xmlWriter->writeStartElement("main");

        foreach (QString key, main.keys())
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, main.value(key).keys())
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(main.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, main.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();

        // Files section
        xmlWriter->writeStartElement("files");

        foreach (QString key, files.keys())
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, files.value(key).keys())
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(files.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, files.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();
    }

    xmlWriter->writeEndDocument();
    file->close();

    delete xmlWriter;
    delete file;
}

QString Config::readMapElement(XMLSection section, QString key, QString attribute)
{
    if (section == GENERAL)
    {
        if (!general.contains(key))
        {
            emit sendMessage("error", "Element " + key + " nie istnieje!");
        }
        else if (!general.value(key).contains(attribute))
        {
            emit sendMessage("error", "Atrybut " + attribute + " elementu " + key + " nie istnieje!");
        }
        else return general.value(key).value(attribute);
    }
    else if (section == JVM)
    {
        if (!jvm.contains(key))
        {
            emit sendMessage("error", "Element " + key + " nie istnieje!");
        }
        else if (!jvm.value(key).contains(attribute))
        {
            emit sendMessage("error", "Atrybut " + attribute + " elementu " + key + " nie istnieje!");
        }
        else return jvm.value(key).value(attribute);
    }
    else if (section == LOCALFILES)
    {
        if (!localFiles.contains(key))
        {
            emit sendMessage("error", "Element " + key + " nie istnieje!");
        }
        else if (!localFiles.value(key).contains(attribute))
        {
            emit sendMessage("error", "Atrybut " + attribute + " elementu " + key + " nie istnieje!");
        }
        else return localFiles.value(key).value(attribute);
    }
    else if (section == MAIN)
    {
        if (!main.contains(key))
        {
            emit sendMessage("error", "Element " + key + " nie istnieje!");
        }
        else if (!main.value(key).contains(attribute))
        {
            emit sendMessage("error", "Atrybut " + attribute + " elementu " + key + " nie istnieje!");
        }
        else return main.value(key).value(attribute);
    }
    else if (section == FILES)
    {
        if (!files.contains(key))
        {
            emit sendMessage("error", "Element " + key + " nie istnieje!");
        }
        else if (!files.value(key).contains(attribute))
        {
            emit sendMessage("error", "Atrybut " + attribute + " elementu " + key + " nie istnieje!");
        }
        else return files.value(key).value(attribute);
    }
    else {
        emit sendMessage("error", "Próba odczytu nieistniejącej sekcji!");
    }

    return "";
}

void Config::writeMapElement(XMLSection section, QString key, QString attribute, QString value)
{
    if (section == GENERAL)
    {
        if (general.contains(key))
        {
            QMap<QString,QString> tmpMap = general.value(key);
            tmpMap.insert(attribute, value);

            general.insert(key, tmpMap);
        }
        else
            emit sendMessage("error", "Nie można zapisać elementu:" + key + " Element nie istnieje!");
    }
    else if (section == JVM)
    {
        if (jvm.contains(key))
        {
            QMap<QString,QString> tmpMap = jvm.value(key);
            tmpMap.insert(attribute, value);

            jvm.insert(key, tmpMap);
        }
        else
            emit sendMessage("error", "Nie można zapisać elementu:" + key + " Element nie istnieje!");
    }
    else if (section == LOCALFILES)
    {
        if (localFiles.contains(key))
        {
            QMap<QString,QString> tmpMap = localFiles.value(key);
            tmpMap.insert(attribute, value);

            localFiles.insert(key, tmpMap);
        }
        else
            emit sendMessage("error", "Nie można zapisać elementu:" + key + " Element nie istnieje!");
    }
    else if (section == MAIN)
    {
        if (main.contains(key))
        {
            QMap<QString,QString> tmpMap = main.value(key);
            tmpMap.insert(attribute, value);

            main.insert(key, tmpMap);
        }
        else
            emit sendMessage("error", "Nie można zapisać elementu:" + key + " Element nie istnieje!");
    }
    else if (section == FILES)
    {
        if (files.contains(key))
        {
            QMap<QString,QString> tmpMap = files.value(key);
            tmpMap.insert(attribute, value);

            files.insert(key, tmpMap);
        }
        else
            emit sendMessage("error", "Nie można zapisać elementu:" + key + " Element nie istnieje!");
    }
    else
        emit sendMessage("error", "Próba odczytu nieistniejącej sekcji!");
}
