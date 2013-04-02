#ifndef ZIPUTILS_H
#define ZIPUTILS_H

#include <QtCore>

class ziputils
{
public:
    ziputils();

    void unpack(QFile *file, QIODevice *dev);
    void pack(QIODevice *dev);
};

#endif // ZIPUTILS_H
