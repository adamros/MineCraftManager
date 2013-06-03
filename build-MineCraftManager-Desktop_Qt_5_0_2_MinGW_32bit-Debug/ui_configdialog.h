/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab_general;
    QGroupBox *groupBox_4;
    QCheckBox *storeLastUser;
    QLabel *label_10;
    QRadioButton *loginAndLaunch;
    QRadioButton *loginAndPanel;
    QCheckBox *storePassword;
    QGroupBox *groupBox_5;
    QCheckBox *queryEnabled;
    QLabel *label_11;
    QSpinBox *spinBox;
    QLabel *label_12;
    QWidget *tab_jvm;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *javaInstallDir;
    QPushButton *javaDirButton;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QCheckBox *openglAcceleration;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *d3dAcceleration;
    QCheckBox *ddrawEnabled;
    QLabel *label_5;
    QCheckBox *xrenderAcceleration;
    QLabel *label_6;
    QSpinBox *minHeap;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *maxHeap;
    QLabel *label_9;
    QCheckBox *force64bit;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->setWindowModality(Qt::ApplicationModal);
        ConfigDialog->resize(658, 500);
        ConfigDialog->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(0,0,0);"));
        ConfigDialog->setModal(true);
        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 460, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(ConfigDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 631, 441));
        tab_general = new QWidget();
        tab_general->setObjectName(QStringLiteral("tab_general"));
        groupBox_4 = new QGroupBox(tab_general);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 371, 181));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        storeLastUser = new QCheckBox(groupBox_4);
        storeLastUser->setObjectName(QStringLiteral("storeLastUser"));
        storeLastUser->setGeometry(QRect(10, 20, 351, 17));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 70, 281, 16));
        loginAndLaunch = new QRadioButton(groupBox_4);
        loginAndLaunch->setObjectName(QStringLiteral("loginAndLaunch"));
        loginAndLaunch->setGeometry(QRect(30, 90, 261, 17));
        loginAndLaunch->setChecked(true);
        loginAndPanel = new QRadioButton(groupBox_4);
        loginAndPanel->setObjectName(QStringLiteral("loginAndPanel"));
        loginAndPanel->setEnabled(false);
        loginAndPanel->setGeometry(QRect(30, 110, 331, 20));
        loginAndPanel->setCheckable(true);
        storePassword = new QCheckBox(groupBox_4);
        storePassword->setObjectName(QStringLiteral("storePassword"));
        storePassword->setGeometry(QRect(10, 40, 351, 17));
        groupBox_5 = new QGroupBox(tab_general);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setEnabled(false);
        groupBox_5->setGeometry(QRect(390, 10, 231, 181));
        queryEnabled = new QCheckBox(groupBox_5);
        queryEnabled->setObjectName(QStringLiteral("queryEnabled"));
        queryEnabled->setGeometry(QRect(10, 20, 211, 17));
        queryEnabled->setChecked(false);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 50, 211, 16));
        spinBox = new QSpinBox(groupBox_5);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(40, 70, 61, 22));
        spinBox->setMinimum(20);
        spinBox->setMaximum(3600);
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(110, 70, 46, 21));
        tabWidget->addTab(tab_general, QString());
        tab_jvm = new QWidget();
        tab_jvm->setObjectName(QStringLiteral("tab_jvm"));
        groupBox = new QGroupBox(tab_jvm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 601, 81));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 581, 16));
        javaInstallDir = new QLineEdit(groupBox);
        javaInstallDir->setObjectName(QStringLiteral("javaInstallDir"));
        javaInstallDir->setGeometry(QRect(10, 40, 501, 20));
        javaDirButton = new QPushButton(groupBox);
        javaDirButton->setObjectName(QStringLiteral("javaDirButton"));
        javaDirButton->setGeometry(QRect(520, 40, 75, 23));
        label_2 = new QLabel(tab_jvm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 0, 611, 41));
        groupBox_2 = new QGroupBox(tab_jvm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 601, 281));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(350, 20, 241, 251));
        openglAcceleration = new QCheckBox(groupBox_3);
        openglAcceleration->setObjectName(QStringLiteral("openglAcceleration"));
        openglAcceleration->setGeometry(QRect(30, 40, 201, 17));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 201, 16));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 201, 16));
        d3dAcceleration = new QCheckBox(groupBox_3);
        d3dAcceleration->setObjectName(QStringLiteral("d3dAcceleration"));
        d3dAcceleration->setGeometry(QRect(30, 100, 201, 17));
        ddrawEnabled = new QCheckBox(groupBox_3);
        ddrawEnabled->setObjectName(QStringLiteral("ddrawEnabled"));
        ddrawEnabled->setEnabled(false);
        ddrawEnabled->setGeometry(QRect(30, 120, 201, 17));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 160, 201, 16));
        xrenderAcceleration = new QCheckBox(groupBox_3);
        xrenderAcceleration->setObjectName(QStringLiteral("xrenderAcceleration"));
        xrenderAcceleration->setGeometry(QRect(30, 180, 201, 17));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 111, 21));
        minHeap = new QSpinBox(groupBox_2);
        minHeap->setObjectName(QStringLiteral("minHeap"));
        minHeap->setGeometry(QRect(120, 20, 61, 22));
        minHeap->setMinimum(32);
        minHeap->setMaximum(9216);
        minHeap->setValue(512);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 20, 46, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 50, 101, 16));
        maxHeap = new QSpinBox(groupBox_2);
        maxHeap->setObjectName(QStringLiteral("maxHeap"));
        maxHeap->setGeometry(QRect(120, 50, 61, 22));
        maxHeap->setMinimum(32);
        maxHeap->setMaximum(9216);
        maxHeap->setValue(1024);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 50, 46, 20));
        force64bit = new QCheckBox(groupBox_2);
        force64bit->setObjectName(QStringLiteral("force64bit"));
        force64bit->setGeometry(QRect(30, 80, 311, 17));
        tabWidget->addTab(tab_jvm, QString());

        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Lixium MC Manager - konfiguracja", 0));
        groupBox_4->setTitle(QApplication::translate("ConfigDialog", "Logowanie", 0));
        storeLastUser->setText(QApplication::translate("ConfigDialog", "Przechowuj ostatnio u\305\274ywan\304\205 nazw\304\231 u\305\274ytkownika", 0));
        label_10->setText(QApplication::translate("ConfigDialog", "Mechanizm logowania:", 0));
        loginAndLaunch->setText(QApplication::translate("ConfigDialog", "Zaloguj i uruchom gr\304\231", 0));
        loginAndPanel->setText(QApplication::translate("ConfigDialog", "Zaloguj i poka\305\274 panel u\305\274ytkownika oraz przycisk uruchamiania gry", 0));
        storePassword->setText(QApplication::translate("ConfigDialog", "Przechowuj has\305\202o w postaci zaszyfrowanej (opcja eksperymentalna)", 0));
        groupBox_5->setTitle(QApplication::translate("ConfigDialog", "Status serwera (Query)", 0));
        queryEnabled->setText(QApplication::translate("ConfigDialog", "W\305\202\304\205cz", 0));
        label_11->setText(QApplication::translate("ConfigDialog", "Cz\304\231stotliwo\305\233\304\207 od\305\233wie\305\274ania statusu:", 0));
        label_12->setText(QApplication::translate("ConfigDialog", "sekund", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_general), QApplication::translate("ConfigDialog", "Og\303\263lne", 0));
        groupBox->setTitle(QApplication::translate("ConfigDialog", "Java", 0));
        label->setText(QApplication::translate("ConfigDialog", "<html><head/><body><p>Katalog Javy (zostaw puste, aby u\305\274y\304\207 ustawie\305\204 systemu):</p></body></html>", 0));
        javaDirButton->setText(QApplication::translate("ConfigDialog", "Przegl\304\205daj...", 0));
        label_2->setText(QApplication::translate("ConfigDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ff0000;\">Bez ruszania tych ustawie\305\204 wszystko powinno dzia\305\202a\304\207 poprawnie.<br/>Wszelkich zmian dokonujesz na w\305\202asn\304\205 odpowiedzialno\305\233\304\207!</span></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("ConfigDialog", "Parametry JVM", 0));
        groupBox_3->setTitle(QApplication::translate("ConfigDialog", "Opcje eksperymentalne", 0));
        openglAcceleration->setText(QApplication::translate("ConfigDialog", "Sprz\304\231towa akceleracja OpenGL", 0));
        label_3->setText(QApplication::translate("ConfigDialog", "Wszystkie systemy:", 0));
        label_4->setText(QApplication::translate("ConfigDialog", "Tylko Windows:", 0));
        d3dAcceleration->setText(QApplication::translate("ConfigDialog", "Akceleracja Direct3D", 0));
        ddrawEnabled->setText(QApplication::translate("ConfigDialog", "W\305\202\304\205cz DirectDraw", 0));
        label_5->setText(QApplication::translate("ConfigDialog", "Tylko Linux, BSD i Solaris:", 0));
        xrenderAcceleration->setText(QApplication::translate("ConfigDialog", "Akceleracja XRender (tylko Java 7)", 0));
        label_6->setText(QApplication::translate("ConfigDialog", "Pami\304\231\304\207 pocz\304\205tkowa:", 0));
        label_7->setText(QApplication::translate("ConfigDialog", "MB", 0));
        label_8->setText(QApplication::translate("ConfigDialog", "Pami\304\231\304\207 maksymalna:", 0));
        label_9->setText(QApplication::translate("ConfigDialog", "MB", 0));
        force64bit->setText(QApplication::translate("ConfigDialog", "Wymu\305\233 tryb 64-bitowy (tylko systemy oraz Java 64-bit)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_jvm), QApplication::translate("ConfigDialog", "Konfiguracja Javy", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
