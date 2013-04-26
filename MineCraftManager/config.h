#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

class Config : public QObject
{
public:
    Config();
    Config(Type type);

    enum Type {
        CONFIG,
        UPDATE
    };

    Type confType;

    void parseFile(QString filename);

    void writeFile(QString filename);

signals:
    void sendMessage(QString type, QString message);

private:
    // Program config
    QMap< QString, QMap<QString, QString> > general;
    QMap< QString, QMap<QString, QString> > jvm;
    QMultiMap< QString, QMap<QString, QString> > localFiles;

    // Update file
    QMap< QString, QMap<QString, QString> > main;
    QMultiMap< QString, QMap<QString, QString> > files;

    QString currentNode;

    void parseElement(QXmlStreamReader &xml);
};

#endif // CONFIG_H
