#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmenubar.h>
#include <client_view.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMenuBar main_menu_bar;
    QMenu* settings_client;
    ClientWidget_Settings* clientSettings;
private slots:
    void open_settings();

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
