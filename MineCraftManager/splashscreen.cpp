#include "splashscreen.h"
#include "ui_splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    ui->label->setText("Inicjalizacja...");
}

void SplashScreen::setMessage(QString message)
{
    ui->label->setText(message);
}

void SplashScreen::progressChanged(int progress)
{
    this->progress = (this->progress + progress)/2;
    ui->progressBar->setValue(this->progress);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}
