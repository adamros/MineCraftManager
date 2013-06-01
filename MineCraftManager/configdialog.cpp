#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(Config *configuration, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);

    this->config = configuration;

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(save()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(exitWSave()));
}

void ConfigDialog::save()
{
    this->close();
}

void ConfigDialog::exitWSave()
{
    this->close();
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}
