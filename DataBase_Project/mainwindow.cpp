#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseManager::instance();
}

MainWindow::~MainWindow()
{
    delete ui;
}
