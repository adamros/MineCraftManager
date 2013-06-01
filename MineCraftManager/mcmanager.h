#ifndef MCMANAGER_H
#define MCMANAGER_H

#include <QtCore>
#include <QtGui>
#include "loginutils.h"
#include "update.h"
#include "version.h"
#include "config.h"
#include "aboutdialog.h"
#include "configdialog.h"
#include "simpleencrypt.h"

namespace Ui {
class MCManager;
}

class MCManager : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MCManager(Config *configuration, QWidget *parent = 0);
    ~MCManager();
    
private:
    Ui::MCManager *ui;

    AboutDialog *aboutLauncherDialog;
    ConfigDialog *configDialog;

    Config *config;
    Loginutils *loginClass;

    QString sid;
    QString username;

public slots:
    void receiveMessage(QString type, QString message);
    void getLoginResult(int i);

private slots:
    void doLogin();
    void playOffline();
    void setLoginMessage(QColor color, QString message);

signals:
};

#endif // MCMANAGER_H
