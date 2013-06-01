#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "config.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConfigDialog(Config *configuration, QWidget *parent = 0);
    ~ConfigDialog();

public slots:
    void save();
    void exitWSave();

private:
    Ui::ConfigDialog *ui;

    Config *config;
};

#endif // CONFIGDIALOG_H
