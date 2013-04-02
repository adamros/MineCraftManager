#include "version.h"

Version::Version()
{
    MAJOR = 1;
    MINOR = 0;
    RELEASE = 1;
    BUILD = 11;
}

QString Version::getVersion()
{
    return QString(MAJOR) + "." + QString(MINOR) + "." + QString(RELEASE) + "." + QString(BUILD);
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

    return false;
}

bool Version::compare(QString ver1, QString ver2)
{
    if (ver1.isEmpty() || ver1.isNull() || ver1.trimmed() == "" || ver2.isEmpty() || ver2.isNull() || ver2.trimmed() == "")
        return false;

    QStringList strlist1 = ver1.split(".");
    QStringList strlist2 = ver2.split(".");

    int numlist1[3];
    int numlist2[3];

    for (int i=0;i<strlist1.count();i++)
    {
        numlist1[i] = strlist1[i].toInt();
    }

    for (int i=0;i<strlist2.count();i++)
    {
        numlist2[i] = strlist2[i].toInt();
    }

    if (numlist1[0] == numlist2[0])
    {
        if (numlist1[1] == numlist2[1])
        {
            if (numlist1[2] == numlist2[2])
            {
                if (numlist1[3] == numlist2[3] || numlist1[3] < numlist2[3])
                    return false;
                else if (numlist1[3] > numlist2[3])
                    return true;
            }
            else if (numlist1[2] > numlist2[2])
                return true;
            else if (numlist1[2] < numlist2[2])
                return false;
        }
        else if (numlist1[1] > numlist2[1])
            return true;
        else if (numlist1[1] < numlist2[1])
            return false;
    }
    else if (numlist1[0] > numlist2[0])
        return true;
    else if (numlist1[0] < numlist2[0])
        return false;

    return false;
}
