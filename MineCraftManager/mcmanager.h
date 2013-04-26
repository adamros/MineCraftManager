#ifndef MCMANAGER_H
#define MCMANAGER_H

#include <QtCore>
#include <QtGui>
#include "loginutils.h"
#include "update.h"
#include "version.h"
#include "config.h"

namespace Ui {
class MCManager;
}

class MCManager : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MCManager(QWidget *parent = 0);
    ~MCManager();

    Config *configuration;
    
private:
    Ui::MCManager *ui;

public slots:
    void receiveMessage(QString type, QString message);

private slots:

signals:
};

#endif // MCMANAGER_H
