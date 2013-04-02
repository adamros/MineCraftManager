#include <QtCore>

class JVMUtils : public QThread {
public:
    JVMUtils();

    void setProperty(QString name, QVariant data);
    void runVM(QString login);

private:
    QMap<QString,QVariant> *jvmconfig;
};

JVMUtils::setProperty(QString name, QVariant data)
{
    if (!name.isEmpty() && !data.isValid())
    {
        if (jvmconfig->keys().contains(name))
            jvmconfig->insert(name, data);
    }
}

JVMUtils::runVM(QString login)
{

}
