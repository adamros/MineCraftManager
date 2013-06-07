/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Fri 7. Jun 10:28:21 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->setWindowModality(Qt::ApplicationModal);
        AboutDialog->resize(441, 362);
        AboutDialog->setStyleSheet(QString::fromUtf8("background: url(:/splash/resources/logolixium.png) top center no-repeat;"));
        AboutDialog->setModal(true);
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(184, 330, 81, 23));
        pushButton->setStyleSheet(QString::fromUtf8("background: none;\n"
"color: rgb(0,0,0);"));
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 160, 401, 171));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0,0,0);"));

        retranslateUi(AboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Lixium MC Manager - o launcherze", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AboutDialog", "Zamknij", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt;\">Lixium MC Manager v1.0.0.96<br/>Autor: </span><span style=\" font-size:9pt; color:#000000;\">adamros<br/></span><span style=\" font-size:9pt;\">Grafika: </span><span style=\" font-size:9pt; color:#000000;\">ReQntar</span><span style=\" font-size:9pt;\">, </span><span style=\" font-size:9pt; color:#000000;\">Vivx</span></p><p align=\"center\"><span style=\" font-size:9pt;\">Strona domowa: </span><a href=\"http://lixium.pl\"><span style=\" font-size:9pt; text-decoration: underline; color:#0000ff;\">http://lixium.pl<br/></span></a><span style=\" font-size:9pt;\">Forum Minecraft: </span><a href=\"http://minecraft.lixium.pl/forum\"><span style=\" font-size:9pt; text-decoration: underline; color:#0000ff;\">http://minecraft.lixium.pl/forum</span></a></p><p align=\"center\"><span style=\" font-size:9pt; color:#000000;\">Wszelkie prawa zastrze\305\274one Lixium \302\256 2012-2013</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
