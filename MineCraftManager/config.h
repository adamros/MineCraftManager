#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

#include "enumstruct.h"

class Config : public QObject
{
    Q_OBJECT
public:
    Config();
    Config(ConfigType type);

    // Program config
    QMap< QString, QMap<QString, QString> > general;
    QMap< QString, QMap<QString, QString> > jvm;
    QMap< QString, QMap<QString, QString> > localFiles;

    // Update file
    QMap< QString, QMap<QString, QString> > main;
    QMap< QString, QMap<QString, QString> > files;

    void parseFile(QString filename);
    void writeFile(QString filename);

    QString readMapElement(XMLSection section, QString key, QString attribute);
    void writeMapElement(XMLSection section, QString key, QString attribute, QString value);

    static bool toBool(QString value);

signals:
    void sendMessage(QString type, QString message);

private:
    QString currentNode;
    ConfigType confType;

    QXmlStreamReader xmlReader;

    void parseElement(QXmlStreamReader &xml);
};

#endif // CONFIG_H
