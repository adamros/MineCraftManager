#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

class Config
{
public:
    Config();

    QMap<QString,QVariant> configMap;

    void readConfig();
    void updateConfig();
    void createConfig();
};

#endif // CONFIG_H
