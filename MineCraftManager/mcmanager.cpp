#include "mcmanager.h"
#include "ui_mcmanager.h"

MCManager::MCManager(Config *configuration, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCManager)
{
    ui->setupUi(this);

    this->aboutLauncherDialog = new AboutDialog(this);
    this->configDialog = new ConfigDialog(configuration, this);

    this->config = configuration;
    this->loginClass = new Loginutils();

    connect(this->config, SIGNAL(sendMessage(QString,QString)), this, SLOT(receiveMessage(QString,QString)));
    connect(this->loginClass, SIGNAL(sendMessage(QString,QString)), this, SLOT(receiveMessage(QString,QString)));

    connect(this->loginClass, SIGNAL(sendResult(int)), this, SLOT(getLoginResult(int)));

    ui->usernameField->setText(this->config->readMapElement(GENERAL, "lastUser", "text"));
    ui->passwordField->setText(SimpleEncrypt::calculateXor(QByteArray::fromHex(this->config->readMapElement(GENERAL, "encPassword", "text").toAscii()), QByteArray(QString("testkey").toAscii()).toHex()));
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
    ui->loginButton->setEnabled(false);
    ui->offlineButton->setEnabled(false);
}

void MCManager::getLoginResult(int i)
{
    switch (i)
    {
    case 0:
        setLoginMessage(Qt::white, "Zalogowano poprawnie!");
        ui->loginButton->setEnabled(true);
        ui->offlineButton->setEnabled(true);
        this->username = this->loginClass->getUsername();
        this->sid = this->loginClass->getSID();
        launchGame();
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
    launchGame();
}

void MCManager::setLoginMessage(QColor color, QString message)
{
    ui->loginMessages->setStyleSheet(ui->loginMessages->styleSheet() + " color: " + color.name() + " !important;");
    ui->loginMessages->setText(trUtf8(message.toAscii()));
}

bool MCManager::launchGame()
{
    LauncherClass launchClass("client/", ui->usernameField->text(), this->sid, this->config->readMapElement(JVM, "javaPath", "text"));
    launchClass.addParam("-Xms590M");
    launchClass.addParam("-Xmx1G");
    launchClass.addParam("-d64");

    return launchClass.launchGame();
}

void MCManager::closeEvent(QCloseEvent *event)
{
    this->config->writeMapElement(GENERAL, "lastUser", "text", ui->usernameField->text());
    this->config->writeMapElement(GENERAL, "encPassword", "text", SimpleEncrypt::calculateXor(ui->usernameField->text().toAscii(), QByteArray(QString("testkey").toAscii())).toHex());
    this->config->writeFile("config/config.xml");
}

MCManager::~MCManager()
{
    delete ui;
    delete aboutLauncherDialog;
    delete configDialog;
    delete config;
    delete loginClass;
}
