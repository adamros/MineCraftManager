/********************************************************************************
** Form generated from reading UI file 'splashscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHSCREEN_H
#define UI_SPLASHSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SplashScreen
{
public:
    QLabel *statusLabel;
    QProgressBar *progressBar;

    void setupUi(QWidget *SplashScreen)
    {
        if (SplashScreen->objectName().isEmpty())
            SplashScreen->setObjectName(QString::fromUtf8("SplashScreen"));
        SplashScreen->setWindowModality(Qt::ApplicationModal);
        SplashScreen->resize(320, 240);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SplashScreen->sizePolicy().hasHeightForWidth());
        SplashScreen->setSizePolicy(sizePolicy);
        SplashScreen->setStyleSheet(QString::fromUtf8("background: url(:/splash/resources/logolixium.png) center center no-repeat;\n"
"background-color: qlineargradient(spread:pad, x1:0.483, y1:1, x2:0.478, y2:0, stop:0 rgba(0, 85, 255, 255), stop:0.443182 rgba(77, 137, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        statusLabel = new QLabel(SplashScreen);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 10, 301, 31));
        statusLabel->setStyleSheet(QString::fromUtf8("background: none;\n"
"image: none;\n"
""));
        statusLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(SplashScreen);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 210, 301, 23));
        progressBar->setStyleSheet(QString::fromUtf8("background: none;\n"
"image: none;"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        retranslateUi(SplashScreen);

        QMetaObject::connectSlotsByName(SplashScreen);
    } // setupUi

    void retranslateUi(QWidget *SplashScreen)
    {
        SplashScreen->setWindowTitle(QApplication::translate("SplashScreen", "Form", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("SplashScreen", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SplashScreen: public Ui_SplashScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHSCREEN_H
