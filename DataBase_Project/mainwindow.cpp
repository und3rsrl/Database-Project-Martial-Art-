#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QDebug>
#include <Player.h>
#include "additemdialog.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mAddItemDialog = std::make_unique<AddItemDialog>(this);
    connect(ui->addButton, &QPushButton::released, this, &MainWindow::onAddPlayer);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddPlayer()
{
    int r = mAddItemDialog->exec();
    if(r == QDialog::Accepted)
    {
        std::unique_ptr<Player> newPlayer = mAddItemDialog->createPlayerFromInput();
        qDebug() << newPlayer->GetIdentifier();
        DatabaseManager::instance().mPlayerDao.AddPlayer(*newPlayer);
    }



}
