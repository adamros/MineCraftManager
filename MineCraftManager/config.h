#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

class Config
{
public:
    Config();

    QMap configMap;

    void parseConfigFile(const QString &file);
};

#endif // CONFIG_H
