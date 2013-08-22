/********************************************************************************
** Form generated from reading UI file 'mcmanager.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCMANAGER_H
#define UI_MCMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MCManager
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *offlineButton;
    QPushButton *configButton;
    QPushButton *aboutLauncher;
    QLabel *loginMessages;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *mcinstalledver;
    QLabel *label_4;
    QLabel *mcrecentver;
    QLabel *label_7;
    QProgressBar *updateProgressBar;
    QPushButton *updateClientButton;
    QPushButton *checkClientUpdates;
    QLabel *updateStatus;
    QComboBox *comboBox;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLabel *statusInfo;
    QLabel *label_6;
    QLabel *motd;
    QLabel *playerNum;
    QLabel *players;
    QPushButton *closeButton;
    QPushButton *minimizeButton;

    void setupUi(QMainWindow *MCManager)
    {
        if (MCManager->objectName().isEmpty())
            MCManager->setObjectName(QString::fromUtf8("MCManager"));
        MCManager->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MCManager->sizePolicy().hasHeightForWidth());
        MCManager->setSizePolicy(sizePolicy);
        MCManager->setMinimumSize(QSize(1000, 600));
        MCManager->setMaximumSize(QSize(1000, 600));
        MCManager->setContextMenuPolicy(Qt::NoContextMenu);
        MCManager->setWindowOpacity(1);
        MCManager->setAutoFillBackground(false);
        MCManager->setStyleSheet(QString::fromUtf8("QMainWindow > QWidget {\n"
"	background: transparent url(:/main/resources/bgmain.png) center right;\n"
"	border-radius: 5px;\n"
"	border: none;\n"
"}\n"
"\n"
"* {\n"
"	color: rgb(255,255,255);\n"
"}"));
        MCManager->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MCManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(680, 70, 311, 141));
        groupBox->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,150);"));
        usernameField = new QLineEdit(groupBox);
        usernameField->setObjectName(QString::fromUtf8("usernameField"));
        usernameField->setGeometry(QRect(10, 20, 191, 20));
        usernameField->setStyleSheet(QString::fromUtf8("background: none;\n"
"color: rgb(0,0,0);"));
        passwordField = new QLineEdit(groupBox);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        passwordField->setGeometry(QRect(10, 50, 191, 20));
        passwordField->setStyleSheet(QString::fromUtf8("background: none;\n"
"color: rgb(0,0,0);"));
        passwordField->setMaxLength(32767);
        passwordField->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(210, 20, 91, 23));
        loginButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        loginButton->setAutoDefault(true);
        loginButton->setDefault(true);
        loginButton->setFlat(false);
        offlineButton = new QPushButton(groupBox);
        offlineButton->setObjectName(QString::fromUtf8("offlineButton"));
        offlineButton->setGeometry(QRect(210, 50, 91, 23));
        offlineButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        configButton = new QPushButton(groupBox);
        configButton->setObjectName(QString::fromUtf8("configButton"));
        configButton->setGeometry(QRect(210, 80, 91, 23));
        configButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        aboutLauncher = new QPushButton(groupBox);
        aboutLauncher->setObjectName(QString::fromUtf8("aboutLauncher"));
        aboutLauncher->setGeometry(QRect(10, 80, 91, 23));
        aboutLauncher->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0); background: none;"));
        loginMessages = new QLabel(groupBox);
        loginMessages->setObjectName(QString::fromUtf8("loginMessages"));
        loginMessages->setGeometry(QRect(10, 110, 291, 21));
        loginMessages->setStyleSheet(QString::fromUtf8("background:none;\n"
"color: rgb(255,255,255);"));
        loginMessages->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 450, 411, 141));
        groupBox_2->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,150);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 141, 16));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;"));
        mcinstalledver = new QLabel(groupBox_2);
        mcinstalledver->setObjectName(QString::fromUtf8("mcinstalledver"));
        mcinstalledver->setGeometry(QRect(170, 20, 101, 16));
        mcinstalledver->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 141, 16));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;"));
        mcrecentver = new QLabel(groupBox_2);
        mcrecentver->setObjectName(QString::fromUtf8("mcrecentver"));
        mcrecentver->setGeometry(QRect(170, 40, 101, 16));
        mcrecentver->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 51, 16));
        label_7->setStyleSheet(QString::fromUtf8("background: transparent;"));
        updateProgressBar = new QProgressBar(groupBox_2);
        updateProgressBar->setObjectName(QString::fromUtf8("updateProgressBar"));
        updateProgressBar->setGeometry(QRect(10, 80, 391, 23));
        updateProgressBar->setStyleSheet(QString::fromUtf8("background: transparent;"));
        updateProgressBar->setValue(0);
        updateClientButton = new QPushButton(groupBox_2);
        updateClientButton->setObjectName(QString::fromUtf8("updateClientButton"));
        updateClientButton->setGeometry(QRect(210, 110, 191, 23));
        updateClientButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        checkClientUpdates = new QPushButton(groupBox_2);
        checkClientUpdates->setObjectName(QString::fromUtf8("checkClientUpdates"));
        checkClientUpdates->setGeometry(QRect(10, 110, 191, 23));
        checkClientUpdates->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        updateStatus = new QLabel(groupBox_2);
        updateStatus->setObjectName(QString::fromUtf8("updateStatus"));
        updateStatus->setGeometry(QRect(50, 60, 351, 16));
        updateStatus->setAutoFillBackground(false);
        updateStatus->setStyleSheet(QString::fromUtf8("background:transparent"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(100, 90, 211, 41));
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background: none;"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 90, 91, 41));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background: transparent;"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(10, 450, 190, 140));
        groupBox_3->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,150);"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 91, 16));
        label_5->setStyleSheet(QString::fromUtf8("background: transparent;"));
        statusInfo = new QLabel(groupBox_3);
        statusInfo->setObjectName(QString::fromUtf8("statusInfo"));
        statusInfo->setGeometry(QRect(105, 20, 81, 20));
        statusInfo->setStyleSheet(QString::fromUtf8("background: transparent;"));
        statusInfo->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 47, 41, 16));
        label_6->setStyleSheet(QString::fromUtf8("background: transparent;"));
        motd = new QLabel(groupBox_3);
        motd->setObjectName(QString::fromUtf8("motd"));
        motd->setGeometry(QRect(20, 60, 161, 20));
        motd->setStyleSheet(QString::fromUtf8("background: transparent;"));
        playerNum = new QLabel(groupBox_3);
        playerNum->setObjectName(QString::fromUtf8("playerNum"));
        playerNum->setGeometry(QRect(10, 100, 91, 16));
        playerNum->setStyleSheet(QString::fromUtf8("background: transparent"));
        players = new QLabel(groupBox_3);
        players->setObjectName(QString::fromUtf8("players"));
        players->setGeometry(QRect(100, 100, 81, 16));
        players->setStyleSheet(QString::fromUtf8("background:transparent;"));
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(954, 10, 31, 23));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        closeButton->setFont(font);
        closeButton->setAutoFillBackground(false);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton#closeButton {\n"
"background: transparent;\n"
"color: rgb(153, 153, 153);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#closeButton:hover {\n"
"background: transparent;\n"
"border: 5px #fff solid;\n"
"}"));
        closeButton->setAutoRepeat(false);
        closeButton->setAutoDefault(false);
        minimizeButton = new QPushButton(centralWidget);
        minimizeButton->setObjectName(QString::fromUtf8("minimizeButton"));
        minimizeButton->setGeometry(QRect(914, 10, 31, 23));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        minimizeButton->setFont(font1);
        minimizeButton->setStyleSheet(QString::fromUtf8("QPushButton#minimizeButton {\n"
"background: transparent;\n"
"color: rgb(153, 153, 153);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton#minimizeButton:hover {\n"
"background: transparent;\n"
"border: 5px #fff solid;\n"
"}"));
        MCManager->setCentralWidget(centralWidget);

        retranslateUi(MCManager);
        QObject::connect(minimizeButton, SIGNAL(clicked()), MCManager, SLOT(showMinimized()));
        QObject::connect(closeButton, SIGNAL(clicked()), MCManager, SLOT(close()));

        QMetaObject::connectSlotsByName(MCManager);
    } // setupUi

    void retranslateUi(QMainWindow *MCManager)
    {
        MCManager->setWindowTitle(QApplication::translate("MCManager", "Lixium Launcher", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MCManager", "Logowanie i konfiguracja", 0, QApplication::UnicodeUTF8));
        usernameField->setPlaceholderText(QApplication::translate("MCManager", "Login/Nick", 0, QApplication::UnicodeUTF8));
        passwordField->setInputMask(QString());
        passwordField->setText(QString());
        passwordField->setPlaceholderText(QApplication::translate("MCManager", "Has\305\202o", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("MCManager", "Zaloguj", 0, QApplication::UnicodeUTF8));
        offlineButton->setText(QApplication::translate("MCManager", "Tryb offline", 0, QApplication::UnicodeUTF8));
        configButton->setText(QApplication::translate("MCManager", "Konfiguracja", 0, QApplication::UnicodeUTF8));
        aboutLauncher->setText(QApplication::translate("MCManager", "O programie", 0, QApplication::UnicodeUTF8));
        loginMessages->setText(QApplication::translate("MCManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MCManager", "Aktualizacje", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MCManager", "<html><head/><body><p>Zainstalowana wersja klienta:</p></body></html>", 0, QApplication::UnicodeUTF8));
        mcinstalledver->setText(QApplication::translate("MCManager", "-", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MCManager", "Najnowsza wersja klienta:", 0, QApplication::UnicodeUTF8));
        mcrecentver->setText(QApplication::translate("MCManager", "-", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MCManager", "Status:", 0, QApplication::UnicodeUTF8));
        updateClientButton->setText(QApplication::translate("MCManager", "Zaktualizuj", 0, QApplication::UnicodeUTF8));
        checkClientUpdates->setText(QApplication::translate("MCManager", "Sprawd\305\272 aktualizacje", 0, QApplication::UnicodeUTF8));
        updateStatus->setText(QApplication::translate("MCManager", "Bezczynny", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MCManager", "Lixium IndustrialTech", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("MCManager", "Wybierz serwer:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MCManager", "Status i informacje serwera", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MCManager", "Status serwera:", 0, QApplication::UnicodeUTF8));
        statusInfo->setText(QApplication::translate("MCManager", "<html><head/><body><p><span style=\" color:#ffaa00;\">Not implemented</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MCManager", "MOTD:", 0, QApplication::UnicodeUTF8));
        motd->setText(QApplication::translate("MCManager", "Not implemented", 0, QApplication::UnicodeUTF8));
        playerNum->setText(QApplication::translate("MCManager", "Ilo\305\233\304\207 graczy:", 0, QApplication::UnicodeUTF8));
        players->setText(QApplication::translate("MCManager", "Not implemented", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("MCManager", "X", 0, QApplication::UnicodeUTF8));
        minimizeButton->setText(QApplication::translate("MCManager", "-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MCManager: public Ui_MCManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCMANAGER_H
