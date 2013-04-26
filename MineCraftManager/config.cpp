#include "config.h"

Config::Config()
{
    confType = UPDATE;
}

Config::Config(Type type)
{
    confType = type;
}

void Config::parseFile(QString filename)
{
    QFile *file = new QFile(QCoreApplication::applicationDirPath() + "/" + filename);

    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit sendMessage("error", file->errorString());
        return;
    }

    QXmlStreamReader *xmlReader = new QXmlStreamReader(file->readAll());
    file->close();

    while (!xmlReader->atEnd() && !xmlReader->hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();

        if (token = QXmlStreamReader::StartDocument)
            continue;

        if (token = QXmlStreamReader::StartElement)
        {
            if (xmlReader->name() == "general" || xmlReader->name() == "jvm" || xmlReader->name() == "main" || xmlReader->name() == "files")
            {
                this->currentNode = xmlReader->name();
                this->parseElement(xmlReader);
            }
        }
    }

    xmlReader->clear();
    delete this->currentNode;
    delete xmlReader;
    delete file;
}

void Config::parseElement(QXmlStreamReader &xml)
{
    while (!(xml.isEndElement() && xml.name() == currentNode))
    {
        xml.readNext();

        if (xml.isStartElement())
        {
            QMap<QString, QString> tempAttr;
            tempAttr.insert("text", xml.readElementText());

            foreach (const QXmlStreamAttribute &attributes, xml.attributes()) {
                tempAttr.insert(attributes.name(), attributes.value());
            }

            if (this->currentNode == "general")
            {
                this->general.insert(xml.name(), tempAttr);
            }
            else if (this->currentNode == "jvm")
            {
                this->jvm.insert(xml.name(), tempAttr);
            }
            else if (this->currentNode == "main")
            {
                this->main.insert(xml.name(), tempAttr);
            }
            else if (this->currentNode == "files")
            {
                this->files.insert(xml.name(), tempAttr);
            }
            else {
                continue;
            }

            delete tempAttr;
        }
    }
}

void Config::writeFile(QString filename)
{
    QFile *file = new QFile(QCoreApplication::applicationDirPath() + "/" + filename);

    if (!file->open(QIODevice::WriteOnly))
    {
        emit sendMessage("error", file->errorString());
        return;
    }

    QXmlStreamWriter *xmlWriter = new QXmlStreamWriter();
    xmlWriter->setDevice(file);
    xmlWriter->writeStartDocument();

    if (this->confType == CONFIG)
    {
        // General section
        xmlWriter->writeStartElement("general");

        foreach (QString key, general)
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, general.value(key))
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

        foreach (QString key, jvm)
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, jvm.value(key))
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

        foreach (QString key, files)
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, localFiles.value(key))
            {
                if (argkey == "text")
                    xmlWriter->writeCharacters(localFiles.value(key).value("text"));
                else
                    xmlWriter->writeAttribute(argkey, localFiles.value(key).value(argkey));
            }

            xmlWriter->writeEndElement();
        }

        xmlWriter->writeEndElement();
    }
    else if (this->confType == UPDATE)
    {
        // Main section
        xmlWriter->writeStartElement("main");

        foreach (QString key, main)
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, main.value(key))
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

        foreach (QString key, files)
        {
            xmlWriter->writeStartElement(key);

            foreach (QString argkey, files.value(key))
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
