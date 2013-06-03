#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QLineEdit>

#include "config.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConfigDialog(Config *&configuration, QWidget *parent = 0);
    ~ConfigDialog();

public slots:
    void save();
    void exitWSave();

private slots:
    void fileDialogSetup(QFileDialog::FileMode mode, QLineEdit *&widget, QString directory = "/");

private:
    Ui::ConfigDialog *ui;

    QFileDialog *fileDialog;

    Config *config;
};

#endif // CONFIGDIALOG_H
