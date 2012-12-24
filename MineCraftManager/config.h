#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

class Config
{
public:
    Config();

    QMap<QString,QVariant> configMap;

    void parseConfigFile();
    void updateConfigFile();
    void createConfigFile();
};

#endif // CONFIG_H
