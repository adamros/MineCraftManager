#include "mcmanager.h"
#include "ui_mcmanager.h"

MCManager::MCManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCManager)
{
    ui->setupUi(this);
}

MCManager::~MCManager()
{
    delete ui;
}
