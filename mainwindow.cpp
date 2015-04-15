#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStorageInfo>
#include <QDebug>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lUtils = new utils();

    deviceList_deviceModel = new QStringListModel(lUtils->getROList_devices());
//    deviceList_labelModel = new QStringListModel(lUtils->getROList_displayNames());
//    deviceList_sizeModel = new QStringListModel(lUtils->getROList_size());

    ui->comboBox_device->setModel(deviceList_deviceModel);

    QTableView *tableStatus = new QTableView;
    tableStatus->setModel(createModel(tableStatus));


    ui->textBrowser_status->append(QString::number(lUtils->getROList_devices().length()));





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPreferences_triggered()
{
    preferences_dialog = new Preferences(this);
    preferences_dialog->show();
}


void MainWindow::on_start_clicked()
{
    start_proccess_dialog = new Start_Proccess(this);
    start_proccess_dialog->show();
}

void MainWindow::on_comboBox_device_activated(const QString &arg1)
{




}

void MainWindow::on_eject_clicked()
{
//    QProcess eject_process;
//    eject_process.start("drutil eject /dev/disk1");

    QProcess::execute("drutil eject /dev/disk1");
}

void MainWindow::on_comboBox_device_currentIndexChanged(int index)
{
    ui->textBrowser_status->clear();
    ui->textBrowser_status->append("Device: " + ui->comboBox_device->currentText() + " - " + "Running // Stopped");
  //  ui->textBrowser_status->append(deviceList_labelModel->data(0);

}
