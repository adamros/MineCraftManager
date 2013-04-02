#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtXml/QtXml>

class Config
{
public:
    Config();

    bool readConfig();
    bool updateConfig();
    bool createConfig();

private:
    QMap<QString, QVariant> settingsMap;
};

#endif // CONFIG_H
