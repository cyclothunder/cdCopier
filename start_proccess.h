#ifndef START_PROCCESS_H
#define START_PROCCESS_H

#include <QDialog>

namespace Ui {
class Start_Proccess;
}

class Start_Proccess : public QDialog
{
    Q_OBJECT

public:
    explicit Start_Proccess(QWidget *parent = 0);
    ~Start_Proccess();

private:
    Ui::Start_Proccess *ui;
};

#endif // START_PROCCESS_H
