#include "mcmanager.h"
#include "ui_mcmanager.h"

MCManager::MCManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCManager)
{
    ui->setupUi(this);

    configuration = new Config(CONFIG);
}

void MCManager::receiveMessage(QString type, QString message)
{
    if (type == "error")
        QMessageBox::critical(this, "Błąd", message);
    else if (type == "warning")
        QMessageBox::warning(this, "Ostrzeżenie", message);
    else
        QMessageBox::information(this, "Informacja", message);
}

MCManager::~MCManager()
{
    delete ui;
}
