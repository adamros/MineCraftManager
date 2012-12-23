#ifndef MCMANAGER_H
#define MCMANAGER_H

#include <QMainWindow>

namespace Ui {
class MCManager;
}

class MCManager : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MCManager(QWidget *parent = 0);
    ~MCManager();
    
private:
    Ui::MCManager *ui;
};

#endif // MCMANAGER_H
