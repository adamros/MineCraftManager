#include "mcmanager.h"
#include "ui_mcmanager.h"

MCManager::MCManager(Config *configuration, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCManager)
{
    ui->setupUi(this);

    this->aboutLauncherDialog = new AboutDialog(this);
    this->configDialog = new ConfigDialog(this->config, this);

    this->config = configuration;
    this->loginClass = new Loginutils();

    connect(this->config, SIGNAL(sendMessage(QString,QString)), this, SLOT(receiveMessage(QString,QString)));
    connect(this->loginClass, SIGNAL(sendMessage(QString,QString)), this, SLOT(receiveMessage(QString,QString)));

    connect(this->loginClass, SIGNAL(sendResult(int)), this, SLOT(getLoginResult(int)));

    ui->usernameField->setText(this->config->readMapElement(GENERAL, "lastUser", "text"));
    ui->passwordField->setText(this->config->readMapElement(GENERAL, "encPassword", "text"));
    ui->loginMessages->setText("");

    connect(ui->aboutLauncher, SIGNAL(clicked()), this->aboutLauncherDialog, SLOT(show()));
    connect(ui->configButton, SIGNAL(clicked()), this->configDialog, SLOT(show()));
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(doLogin()));
    connect(ui->offlineButton, SIGNAL(clicked()), this, SLOT(playOffline()));
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

void MCManager::doLogin()
{
    this->loginClass->doLogin(ui->usernameField->text(), ui->passwordField->text());
}

void MCManager::getLoginResult(int i)
{
    switch (i)
    {
    case 0:
        setLoginMessage(Qt::white, "Zalogowano poprawnie!");
        this->username = this->loginClass->getUsername();
        this->sid = this->loginClass->getSID();
        break;
    case 1:
        setLoginMessage(Qt::red, "Niepoprawna nazwa użytkownika lub hasło!");
        break;
    case 2:
        setLoginMessage(Qt::red, "Stara wersja! Zgłoś to autorowi launchera!");
        break;
    case 3:
        setLoginMessage(Qt::red, "Użytkownik non-premium! Użyj trybu offline!");
        break;
    case 4:
    default:
        setLoginMessage(Qt::red, "Nie mozna połączyć się z minecraft.net");
        break;
    }
}

void MCManager::playOffline()
{
    this->loginClass->playCached(ui->usernameField->text());
    this->username = this->loginClass->getUsername();
    this->sid = this->loginClass->getSID();
}

void MCManager::setLoginMessage(QColor color, QString message)
{
    ui->loginMessages->setStyleSheet(ui->loginMessages->styleSheet() + " color: " + color.name() + " !important;");
    ui->loginMessages->setText(trUtf8(message.toAscii()));
}

MCManager::~MCManager()
{
    delete ui;
}
