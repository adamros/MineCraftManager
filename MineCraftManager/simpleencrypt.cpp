#include "simpleencrypt.h"

SimpleEncrypt::SimpleEncrypt(QObject *parent) :
    QObject(parent)
{
}

QByteArray SimpleEncrypt::calculateXor(const QByteArray &data, const QByteArray &key)
{
    if(key.isEmpty())
        return data;

    QByteArray result;
    for(int i = 0; i < data.length(); ++i)
    {
        result.append(data.at(i) ^ key.at(0));
    }
    return result;
}
