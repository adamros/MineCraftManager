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
    for(int i = 0 , j = 0; i < data.length(); ++i , ++j)
    {
        qDebug() << i << " " << j;
        if(j == key.length())
            j = 0;
        result.append(data.at(i) ^ key.at(j));
    }
    return result;
}
