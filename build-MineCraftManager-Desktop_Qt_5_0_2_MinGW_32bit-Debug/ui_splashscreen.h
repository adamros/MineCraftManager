/********************************************************************************
** Form generated from reading UI file 'splashscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHSCREEN_H
#define UI_SPLASHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SplashScreen
{
public:
    QLabel *statusLabel;
    QProgressBar *progressBar;

    void setupUi(QWidget *SplashScreen)
    {
        if (SplashScreen->objectName().isEmpty())
            SplashScreen->setObjectName(QStringLiteral("SplashScreen"));
        SplashScreen->setWindowModality(Qt::ApplicationModal);
        SplashScreen->resize(320, 240);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SplashScreen->sizePolicy().hasHeightForWidth());
        SplashScreen->setSizePolicy(sizePolicy);
        SplashScreen->setStyleSheet(QLatin1String("background: url(:/splash/resources/logolixium.png) center center no-repeat;\n"
"background-color: qlineargradient(spread:pad, x1:0.483, y1:1, x2:0.478, y2:0, stop:0 rgba(0, 85, 255, 255), stop:0.443182 rgba(77, 137, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        statusLabel = new QLabel(SplashScreen);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 10, 301, 31));
        statusLabel->setStyleSheet(QLatin1String("background: none;\n"
"image: none;\n"
""));
        statusLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(SplashScreen);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 210, 301, 23));
        progressBar->setStyleSheet(QLatin1String("background: none;\n"
"image: none;"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        retranslateUi(SplashScreen);

        QMetaObject::connectSlotsByName(SplashScreen);
    } // setupUi

    void retranslateUi(QWidget *SplashScreen)
    {
        SplashScreen->setWindowTitle(QApplication::translate("SplashScreen", "Form", 0));
        statusLabel->setText(QApplication::translate("SplashScreen", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class SplashScreen: public Ui_SplashScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHSCREEN_H
