#include "mcmanager.h"
#include "ui_mcmanager.h"

MCManager::MCManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCManager)
{
    ui->setupUi(this);

    configuration = new Config(Config::CONFIG);
}

void MCManager::receiveMessage(QString type, QString message)
{
    switch (type)
    {
    case "error":
        QMessageBox::critical(this, "Błąd", message);
        break;
    case "warning":
        QMessageBox::warning(this, "Ostrzeżenie", message);
        break;
    case "information":
    default:
        QMessageBox::information(this, "Informacja", message);
        break;
    }
}

MCManager::~MCManager()
{
    delete ui;
}
