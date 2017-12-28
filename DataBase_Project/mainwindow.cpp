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
    mViews = std::make_unique<QActionGroup>(this);

    mViews->addAction(ui->actionViewAddPlayers);
    mViews->addAction(ui->actionViewCategorii);
    mViews->addAction(ui->actionViewClasament);
    mViews->addAction(ui->actionViewEtape);



    connect(ui->addButton, &QPushButton::released, this, &MainWindow::onAddPlayer);
    connect(mViews.get(), &QActionGroup::triggered, this, &MainWindow::onViewTriggered);


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

void MainWindow::onViewTriggered(QAction *action)
{
    if(action == ui->actionViewAddPlayers)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tablePersons);
        ui->stackedWidget->setCurrentIndex(1);
    }
    if(action == ui->actionViewCategorii)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tableWorkingHours);
        ui->stackedWidget->setCurrentIndex(3);

    }
    if(action == ui->actionViewClasament)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tableWorkingHours);
        ui->stackedWidget->setCurrentIndex(0);

    }
    if(action == ui->actionViewEtape)
    {
        //ui->stackedWidget->setCurrentWidget(ui->tableWorkingHours);
        ui->stackedWidget->setCurrentIndex(2);
    }

}
