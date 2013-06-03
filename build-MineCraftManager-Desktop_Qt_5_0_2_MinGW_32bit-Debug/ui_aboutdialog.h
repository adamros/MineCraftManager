/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->setWindowModality(Qt::ApplicationModal);
        AboutDialog->resize(441, 362);
        AboutDialog->setStyleSheet(QStringLiteral("background: url(:/splash/resources/logolixium.png) top center no-repeat;"));
        AboutDialog->setModal(true);
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(184, 330, 81, 23));
        pushButton->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(0,0,0);"));
        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 160, 401, 171));
        label->setStyleSheet(QLatin1String("background: transparent;\n"
"color: rgb(0,0,0);"));

        retranslateUi(AboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Lixium MC Manager - o launcherze", 0));
        pushButton->setText(QApplication::translate("AboutDialog", "Zamknij", 0));
        label->setText(QApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt;\">Lixium MC Manager v1.0.0.96<br/>Autor: </span><span style=\" font-size:9pt; color:#000000;\">adamros<br/></span><span style=\" font-size:9pt;\">Grafika: </span><span style=\" font-size:9pt; color:#000000;\">ReQntar</span><span style=\" font-size:9pt;\">, </span><span style=\" font-size:9pt; color:#000000;\">Vivx</span></p><p align=\"center\"><span style=\" font-size:9pt;\">Strona domowa: </span><a href=\"http://lixium.pl\"><span style=\" font-size:9pt; text-decoration: underline; color:#0000ff;\">http://lixium.pl<br/></span></a><span style=\" font-size:9pt;\">Forum Minecraft: </span><a href=\"http://minecraft.lixium.pl/forum\"><span style=\" font-size:9pt; text-decoration: underline; color:#0000ff;\">http://minecraft.lixium.pl/forum</span></a></p><p align=\"center\"><span style=\" font-size:9pt; color:#000000;\">Wszelkie prawa zastrze\305\274one Lixium \302\256 2012-2013</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
