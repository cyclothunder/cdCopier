#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <preferences.h>
#include <start_proccess.h>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>

#include <utils.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionPreferences_triggered();


    void on_start_clicked();

    void on_comboBox_device_activated(const QString &arg1);

    void on_eject_clicked();

    void on_comboBox_device_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Preferences *preferences_dialog;
    Start_Proccess *start_proccess_dialog;

    utils *lUtils;
    QStringListModel *deviceList_deviceModel;
    QStandardItemModel *devicelist_deviceModelStd;

//    QStringListModel *deviceList_labelModel;
//    QStringListModel *deviceList_sizeModel;

};

#endif // MAINWINDOW_H
