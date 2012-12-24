#include "version.h"

Version::Version()
{
}

QString Version::getVersion()
{

    return "";
}

bool Version::isNewer(const QString &str)
{
    QStringList list = str.split(".");

    int strlist[3];

    for (int i=0;i<list.count();i++)
    {
        strlist[i] = list[i].toInt();
    }

    if (strlist[0] == MAJOR)
    {
        if (strlist[1] == MINOR)
        {
            if (strlist[2] == RELEASE)
            {
                if (strlist[3] == BUILD || strlist[3] < BUILD)
                    return false;
                else if (strlist[3] > BUILD)
                    return true;
            }
            else if (strlist[2] > RELEASE)
                return true;
            else if (strlist[2] < RELEASE)
                return false;
        }
        else if (strlist[1] > MINOR)
            return true;
        else if (strlist[1] < MINOR)
            return false;
    }
    else if (strlist[0] > MAJOR)
        return true;
    else if (strlist[0] < MAJOR)
        return false;
}
