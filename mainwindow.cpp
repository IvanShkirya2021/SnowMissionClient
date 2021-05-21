#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    clientSettings = new ClientWidget_Settings(this);
    settings_client = new QMenu("&Настройки");
    settings_client->addAction("Открыть настройки", this, SLOT(open_settings()));
    main_menu_bar.addMenu(settings_client);
    this->setMenuBar(&main_menu_bar);
}

MainWindow::~MainWindow()
{
    delete clientSettings;
    delete settings_client;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    clientSettings->close();
    QMainWindow::closeEvent(event);
}

void MainWindow::open_settings()
{
    clientSettings->show();
}

