#ifndef SIMPLEENCRYPT_H
#define SIMPLEENCRYPT_H

#include <QObject>

class SimpleEncrypt : public QObject
{
    Q_OBJECT
public:
    explicit SimpleEncrypt(QObject *parent = 0);
    
    static QByteArray calculateXor(const QByteArray &data, const QByteArray &key);
    
};

#endif // SIMPLEENCRYPT_H
