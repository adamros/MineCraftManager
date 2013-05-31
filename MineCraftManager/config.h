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

    ConfigType confType;

    // Program config
    QMap< QString, QMap<QString, QString> > general;
    QMap< QString, QMap<QString, QString> > jvm;
    QMultiMap< QString, QMap<QString, QString> > localFiles;

    // Update file
    QMap< QString, QMap<QString, QString> > main;
    QMultiMap< QString, QMap<QString, QString> > files;

    void parseFile(QString filename);

    void writeFile(QString filename);

signals:
    void sendMessage(QString type, QString message);

private:
    QString currentNode;

    void parseElement(QXmlStreamReader *xml);
};

#endif // CONFIG_H
