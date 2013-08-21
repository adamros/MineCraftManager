#include "mcmanager.h"
#include "splashscreen.h"
#include "config.h"
#include "enumstruct.h"
#include "fileutils.h"
#include <QApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Config *config = new Config(CONFIG);

    SplashScreen splash;
    splash.show();
    splash.changeSplash(30, "Ładowanie");

    FileUtils::initDirectories();
    FileUtils *fileTools = new FileUtils(config);
    fileTools->addFilesAndScan("");

    splash.changeSplash(40, "Wczytywanie konfiguracji");
    config->parseFile("config/config.xml");

    //Update *updater = new Update(LAUNCHER, config);
    //updater->checkLauncherUpdate();

    //qDebug() << config->localFiles;

    MCManager *w = new MCManager(config);

    splash.finish(w);
    
    return a.exec();
}
