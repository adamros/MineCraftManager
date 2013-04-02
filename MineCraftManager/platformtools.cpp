#include <QtCore>

class PlatformTools {
public:
    PlatformTools();

    bool unpack(QString filepath, QString filename);
    bool pack(QString filepath, QString filename);
};

PlatformTools::PlatformTools()
{

}

bool PlatformTools::unpack(QString filepath, QString filename)
{
    QDir dir = new QDir();
    dir.toNativeSeparators(filepath);
    QFile *file = new QFile();
}

bool PlatformTools::pack(QString filepath, QString filename)
{
    QDir dir = new QDir();
    dir.toNativeSeparators(filepath);
    QFile *file = new QFile(dir + filename);
}
