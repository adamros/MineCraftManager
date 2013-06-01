#ifndef SIMPLEENCRYPT_H
#define SIMPLEENCRYPT_H

#include <QObject>

class SimpleEncrypt : public QObject
{
    Q_OBJECT
public:
    explicit SimpleEncrypt(QObject *parent = 0);
    
    static QByteArray encrypt(QString data);
    static QString decrypt(QByteArray data);
    
};

#endif // SIMPLEENCRYPT_H
