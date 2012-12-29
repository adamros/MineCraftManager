#ifndef VERSION_H
#define VERSION_H

#include <QtCore>

class Version
{
public:
    Version();

    QString getVersion();

    bool isNewer(const QString &str);
private:
    int MAJOR;
    int MINOR;
    int RELEASE;
    int BUILD;
};

#endif // VERSION_H
