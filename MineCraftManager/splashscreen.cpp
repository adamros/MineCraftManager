#include "splashscreen.h"
#include "ui_splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    ui->statusLabel->setText("Inicjalizacja...");
    ui->progressBar->setValue(0);

    this->setWindowFlags(Qt::SplashScreen);
}

void SplashScreen::changeSplash(int progress, QString message)
{
    ui->progressBar->setValue(progress);
    ui->progressBar->update();
    ui->statusLabel->setText(trUtf8(message.toAscii()));
}

void SplashScreen::finish(QMainWindow *mainWindow)
{
    mainWindow->show();
    this->close();
}

SplashScreen::~SplashScreen()
{
    delete ui;
}
