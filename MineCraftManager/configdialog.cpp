#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(Config *&configuration, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);

    this->fileDialog = new QFileDialog();

    this->config = configuration;

    ui->javaInstallDir->setText(QDir::toNativeSeparators(this->config->readMapElement(JVM, "javaPath", "text")));
    ui->storeLastUser->setChecked(Config::toBool(this->config->readMapElement(GENERAL, "storeLastUser", "text")));
    ui->storePassword->setChecked(Config::toBool(this->config->readMapElement(GENERAL, "storePassword", "text")));

    /* Implemented for future use
    if (this->config->readMapElement(GENERAL, "loginMode", "text").toInt() == 0)
    {
        ui->loginAndLaunch->setChecked(true);
        ui->loginAndPanel->setChecked(false);
    }
    else {
        ui->loginAndLaunch->setChecked(false);
        ui->loginAndPanel->setChecked(true);
    }
    */

    ui->loginAndLaunch->setChecked(true);
    ui->loginAndPanel->setChecked(false);

    // Query not implemented yet
    //ui->queryEnabled->setChecked(Config::toBool(this->config->readMapElement(GENERAL, "queryEnabled", "text")));
    //ui->queryRefresh->setValue(this->config->readMapElement(GENERAL, "queryInterval", "text").toInt());

    ui->minHeap->setValue(this->config->readMapElement(JVM, "minHeap", "text").toInt());
    ui->maxHeap->setValue(this->config->readMapElement(JVM, "maxHeap", "text").toInt());
    ui->force64bit->setChecked(Config::toBool(this->config->readMapElement(JVM, "force64bit", "text")));

    ui->openglAcceleration->setChecked(Config::toBool(this->config->readMapElement(JVM, "hwOpenglAcceleration", "text")));
#ifdef Q_WS_WIN
    ui->d3dAcceleration->setChecked(Config::toBool(this->config->readMapElement(JVM, "d3dAcceleration", "text")));
    //ui->ddrawEnabled->setChecked(Config::toBool(this->config->readMapElement(JVM, "ddrawEnabled", "text")));
#else
    ui->d3dAcceleration->setChecked(false);
    ui->d3dAcceleration->setEnabled(false);
#endif
#ifdef Q_WS_X11
    ui->xrenderAcceleration->setChecked(Config::toBool(this->config->readMapElement(JVM, "xrenderAcceleration", "text")));
#else
    ui->xrenderAcceleration->setChecked(false);
    ui->xrenderAcceleration->setEnabled(false);
#endif

    this->fileDialogSetup(QFileDialog::Directory, ui->javaInstallDir);

    connect(ui->javaDirButton, SIGNAL(clicked()), this->fileDialog, SLOT(show()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(save()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(exitWSave()));
}

void ConfigDialog::save()
{
    this->config->writeMapElement(GENERAL, "storeLastUser", "text", QString::number(ui->storeLastUser->isChecked()));
    this->config->writeMapElement(GENERAL, "storePassword", "text", QString::number(ui->storePassword->isChecked()));

    if (ui->loginAndLaunch->isChecked())
        this->config->writeMapElement(GENERAL, "loginMode", "text", "0");
    else if (ui->loginAndPanel->isChecked())
        this->config->writeMapElement(GENERAL, "loginMode", "text", "1");

    this->config->writeMapElement(GENERAL, "queryEnabled", "text", QString::number(ui->queryEnabled->isChecked()));
    this->config->writeMapElement(GENERAL, "queryInterval", "text", QString::number(ui->queryRefresh->value()));

    this->config->writeMapElement(JVM, "javaPath", "text", QDir::toNativeSeparators(ui->javaInstallDir->text()));
    this->config->writeMapElement(JVM, "minHeap", "text", QString::number(ui->minHeap->value()));
    this->config->writeMapElement(JVM, "maxHeap", "text", QString::number(ui->maxHeap->value()));
    this->config->writeMapElement(JVM, "force64bit", "text", QString::number(ui->force64bit->isChecked()));
    this->config->writeMapElement(JVM, "hwOpenglAcceleration", "text", QString::number(ui->openglAcceleration->isChecked()));
    this->config->writeMapElement(JVM, "d3dAcceleration", "text", QString::number(ui->d3dAcceleration->isChecked()));
    //this->config->writeMapElement(JVM, "ddrawEnabled", "text", QString::number(ui->ddrawEnabled->isChecked()));
    this->config->writeMapElement(JVM, "xrenderAcceleration", "text", QString::number(ui->xrenderAcceleration->isChecked()));

    this->config->writeFile("config/config.xml");

    this->close();
}

void ConfigDialog::exitWSave()
{
    this->close();
}

void ConfigDialog::fileDialogSetup(QFileDialog::FileMode mode, QLineEdit *&widget, QString directory)
{
    fileDialog->setFileMode(mode);
    fileDialog->setOption(QFileDialog::ShowDirsOnly);
    fileDialog->setOption(QFileDialog::ReadOnly);
    fileDialog->setDirectory(QDir::toNativeSeparators(directory));
    fileDialog->setModal(true);

    connect(fileDialog, SIGNAL(currentChanged(QString)), widget, SLOT(setText(QString)));
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
    delete this->config;
}
