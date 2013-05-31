#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT
    
public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();

public slots:
    void setMessage(QString message);
    void progressChanged(int progress);
    
private:
    Ui::SplashScreen *ui;

    int progress;
};

#endif // SPLASHSCREEN_H
