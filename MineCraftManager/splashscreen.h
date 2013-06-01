#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT
    
public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();

    void changeSplash(int progress, QString message);
    void finish(QMainWindow *mainWindow);
    
private:
    Ui::SplashScreen *ui;
};

#endif // SPLASHSCREEN_H
