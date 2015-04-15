#include "start_proccess.h"
#include "ui_start_proccess.h"

Start_Proccess::Start_Proccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start_Proccess)
{
    ui->setupUi(this);
}

Start_Proccess::~Start_Proccess()
{
    delete ui;
}
