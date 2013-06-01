#include "simpleencrypt.h"

SimpleEncrypt::SimpleEncrypt(QObject *parent) :
    QObject(parent)
{
}

QByteArray SimpleEncrypt::encrypt(QString data)
{
    QByteArray ba(data.toUtf8());
    QByteArray comprData = qCompress(ba, 4);
    return comprData.toHex();
}

QString SimpleEncrypt::decrypt(QByteArray data)
{
    QByteArray ba(QByteArray::fromHex(data));
    QByteArray uncomprData = qUncompress(ba);
    return QString::fromUtf8(uncomprData);
}
