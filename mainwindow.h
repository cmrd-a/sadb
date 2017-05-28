#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "newdialog.h"
#include "data.h"
#include "factory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void updRooms();

public:
    Data data;
    Factory factory;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startup();
    void DisableAll();

private slots:
    void on_menuNew_triggered();

    void on_menuExit_triggered();

    void on_newRoomLE_textEdited(const QString &arg1);

    void on_addRoomBtn_clicked();

    void on_roomCB_activated(int index);

private:
    Ui::MainWindow *ui;
    NewDialog *objNewDialog;
};

#endif // MAINWINDOW_H
