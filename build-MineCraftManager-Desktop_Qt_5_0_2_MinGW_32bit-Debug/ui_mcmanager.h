/********************************************************************************
** Form generated from reading UI file 'mcmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCMANAGER_H
#define UI_MCMANAGER_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MCManager
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *offlineButton;
    QPushButton *configButton;
    QPushButton *aboutLauncher;
    QLabel *loginMessages;
    QWebView *mainWebView;
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

    void setupUi(QMainWindow *MCManager)
    {
        if (MCManager->objectName().isEmpty())
            MCManager->setObjectName(QStringLiteral("MCManager"));
        MCManager->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MCManager->sizePolicy().hasHeightForWidth());
        MCManager->setSizePolicy(sizePolicy);
        MCManager->setMinimumSize(QSize(1000, 600));
        MCManager->setMaximumSize(QSize(1000, 600));
        MCManager->setContextMenuPolicy(Qt::NoContextMenu);
        MCManager->setAutoFillBackground(false);
        MCManager->setStyleSheet(QLatin1String("background: url(:/main/resources/bgmain.png) center right;\n"
"color: rgb(255,255,255);"));
        MCManager->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MCManager);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 450, 361, 141));
        groupBox->setStyleSheet(QStringLiteral("background: rgba(0,0,0,150);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 51, 21));
        label->setStyleSheet(QStringLiteral("background: transparent;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 51, 21));
        label_2->setStyleSheet(QStringLiteral("background: transparent;"));
        usernameField = new QLineEdit(groupBox);
        usernameField->setObjectName(QStringLiteral("usernameField"));
        usernameField->setGeometry(QRect(60, 20, 191, 20));
        usernameField->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(0,0,0);"));
        passwordField = new QLineEdit(groupBox);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(60, 50, 191, 20));
        passwordField->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(0,0,0);"));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(260, 20, 91, 23));
        loginButton->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        offlineButton = new QPushButton(groupBox);
        offlineButton->setObjectName(QStringLiteral("offlineButton"));
        offlineButton->setGeometry(QRect(260, 50, 91, 23));
        offlineButton->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        configButton = new QPushButton(groupBox);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setGeometry(QRect(260, 80, 91, 23));
        configButton->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        aboutLauncher = new QPushButton(groupBox);
        aboutLauncher->setObjectName(QStringLiteral("aboutLauncher"));
        aboutLauncher->setGeometry(QRect(10, 80, 91, 23));
        aboutLauncher->setStyleSheet(QStringLiteral("color: rgb(0,0,0); background: none;"));
        loginMessages = new QLabel(groupBox);
        loginMessages->setObjectName(QStringLiteral("loginMessages"));
        loginMessages->setGeometry(QRect(10, 110, 341, 21));
        loginMessages->setStyleSheet(QLatin1String("background:none;\n"
"color: rgb(255,255,255);"));
        loginMessages->setAlignment(Qt::AlignCenter);
        mainWebView = new QWebView(centralWidget);
        mainWebView->setObjectName(QStringLiteral("mainWebView"));
        mainWebView->setGeometry(QRect(580, 10, 411, 431));
        mainWebView->setContextMenuPolicy(Qt::NoContextMenu);
        mainWebView->setUrl(QUrl(QStringLiteral("about:blank")));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 450, 411, 141));
        groupBox_2->setStyleSheet(QStringLiteral("background: rgba(0,0,0,150);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 141, 16));
        label_3->setStyleSheet(QStringLiteral("background: transparent;"));
        mcinstalledver = new QLabel(groupBox_2);
        mcinstalledver->setObjectName(QStringLiteral("mcinstalledver"));
        mcinstalledver->setGeometry(QRect(170, 20, 101, 16));
        mcinstalledver->setStyleSheet(QStringLiteral("background: transparent;"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 141, 16));
        label_4->setStyleSheet(QStringLiteral("background: transparent;"));
        mcrecentver = new QLabel(groupBox_2);
        mcrecentver->setObjectName(QStringLiteral("mcrecentver"));
        mcrecentver->setGeometry(QRect(170, 40, 101, 16));
        mcrecentver->setStyleSheet(QStringLiteral("background: transparent;"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 51, 16));
        label_7->setStyleSheet(QStringLiteral("background: transparent;"));
        updateProgressBar = new QProgressBar(groupBox_2);
        updateProgressBar->setObjectName(QStringLiteral("updateProgressBar"));
        updateProgressBar->setGeometry(QRect(10, 80, 391, 23));
        updateProgressBar->setStyleSheet(QStringLiteral("background: transparent;"));
        updateProgressBar->setValue(0);
        updateClientButton = new QPushButton(groupBox_2);
        updateClientButton->setObjectName(QStringLiteral("updateClientButton"));
        updateClientButton->setGeometry(QRect(210, 110, 191, 23));
        updateClientButton->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        checkClientUpdates = new QPushButton(groupBox_2);
        checkClientUpdates->setObjectName(QStringLiteral("checkClientUpdates"));
        checkClientUpdates->setGeometry(QRect(10, 110, 191, 23));
        checkClientUpdates->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        updateStatus = new QLabel(groupBox_2);
        updateStatus->setObjectName(QStringLiteral("updateStatus"));
        updateStatus->setGeometry(QRect(50, 60, 351, 16));
        updateStatus->setAutoFillBackground(false);
        updateStatus->setStyleSheet(QStringLiteral("background:transparent"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(100, 10, 211, 41));
        comboBox->setStyleSheet(QLatin1String("color: rgb(0,0,0);\n"
"background: none;"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 91, 41));
        label_8->setStyleSheet(QLatin1String("color: rgb(255,255,255);\n"
"background: transparent;"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(380, 450, 191, 141));
        groupBox_3->setStyleSheet(QStringLiteral("background: rgba(0,0,0,150);"));
        groupBox_3->setFlat(false);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 91, 16));
        label_5->setStyleSheet(QStringLiteral("background: transparent;"));
        statusInfo = new QLabel(groupBox_3);
        statusInfo->setObjectName(QStringLiteral("statusInfo"));
        statusInfo->setGeometry(QRect(105, 20, 81, 20));
        statusInfo->setStyleSheet(QStringLiteral("background: transparent;"));
        statusInfo->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 47, 41, 16));
        label_6->setStyleSheet(QStringLiteral("background: transparent;"));
        motd = new QLabel(groupBox_3);
        motd->setObjectName(QStringLiteral("motd"));
        motd->setGeometry(QRect(20, 60, 161, 20));
        motd->setStyleSheet(QStringLiteral("background: transparent;"));
        playerNum = new QLabel(groupBox_3);
        playerNum->setObjectName(QStringLiteral("playerNum"));
        playerNum->setGeometry(QRect(10, 100, 91, 16));
        playerNum->setStyleSheet(QStringLiteral("background: transparent"));
        players = new QLabel(groupBox_3);
        players->setObjectName(QStringLiteral("players"));
        players->setGeometry(QRect(100, 100, 81, 16));
        players->setStyleSheet(QStringLiteral("background:transparent;"));
        MCManager->setCentralWidget(centralWidget);

        retranslateUi(MCManager);

        QMetaObject::connectSlotsByName(MCManager);
    } // setupUi

    void retranslateUi(QMainWindow *MCManager)
    {
        MCManager->setWindowTitle(QApplication::translate("MCManager", "Lixium MC Manager", 0));
        groupBox->setTitle(QApplication::translate("MCManager", "Logowanie i konfiguracja", 0));
        label->setText(QApplication::translate("MCManager", "Nick:", 0));
        label_2->setText(QApplication::translate("MCManager", "Has\305\202o:", 0));
        loginButton->setText(QApplication::translate("MCManager", "Zaloguj", 0));
        offlineButton->setText(QApplication::translate("MCManager", "Tryb offline", 0));
        configButton->setText(QApplication::translate("MCManager", "Konfiguracja", 0));
        aboutLauncher->setText(QApplication::translate("MCManager", "O programie", 0));
        loginMessages->setText(QApplication::translate("MCManager", "TextLabel", 0));
        groupBox_2->setTitle(QApplication::translate("MCManager", "Aktualizacje", 0));
        label_3->setText(QApplication::translate("MCManager", "<html><head/><body><p>Zainstalowana wersja klienta:</p></body></html>", 0));
        mcinstalledver->setText(QApplication::translate("MCManager", "-", 0));
        label_4->setText(QApplication::translate("MCManager", "Najnowsza wersja klienta:", 0));
        mcrecentver->setText(QApplication::translate("MCManager", "-", 0));
        label_7->setText(QApplication::translate("MCManager", "Status:", 0));
        updateClientButton->setText(QApplication::translate("MCManager", "Zaktualizuj", 0));
        checkClientUpdates->setText(QApplication::translate("MCManager", "Sprawd\305\272 aktualizacje", 0));
        updateStatus->setText(QApplication::translate("MCManager", "Bezczynny", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MCManager", "Lixium IndustrialTech", 0)
        );
        label_8->setText(QApplication::translate("MCManager", "Wybierz serwer:", 0));
        groupBox_3->setTitle(QApplication::translate("MCManager", "Status i informacje serwera", 0));
        label_5->setText(QApplication::translate("MCManager", "Status serwera:", 0));
        statusInfo->setText(QApplication::translate("MCManager", "<html><head/><body><p><span style=\" color:#ffaa00;\">Not implemented</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MCManager", "MOTD:", 0));
        motd->setText(QApplication::translate("MCManager", "Not implemented", 0));
        playerNum->setText(QApplication::translate("MCManager", "Ilo\305\233\304\207 graczy:", 0));
        players->setText(QApplication::translate("MCManager", "Not implemented", 0));
    } // retranslateUi

};

namespace Ui {
    class MCManager: public Ui_MCManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCMANAGER_H
