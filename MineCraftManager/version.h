#ifndef VERSION_H
#define VERSION_H

#include <QtCore>

#define MAJOR 1
#define MINOR 0
#define RELEASE 1
#define BUILD 1

class Version
{
public:
    Version();

    QString getVersion();

    bool isNewer(const QString &str);
};

#endif // VERSION_H
