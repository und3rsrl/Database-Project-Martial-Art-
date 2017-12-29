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
    ui->playersList->setModel(&mPlayerModel.m_model);
    ui->playersList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playersList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->clasamentList->setModel(&mRankingModel.m_model);
    ui->clasamentList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->clasamentList->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    //ui->clasamentList->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->playersList->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->clasamentList->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    mAddItemDialog = std::make_unique<AddItemDialog>(this);
    mViews = std::make_unique<QActionGroup>(this);

    mViews->addAction(ui->actionViewAddPlayers);
    mViews->addAction(ui->actionViewCategorii);
    mViews->addAction(ui->actionViewClasament);
    mViews->addAction(ui->actionViewEtape);

    connect(ui->addButton, &QPushButton::released, this, &MainWindow::onAddPlayer);
    connect(ui->removeButton, &QPushButton::released, this, &MainWindow::onDeletePlayer);
    connect(ui->actionRefreshDatabase, &QAction::triggered, this, &MainWindow::onRefresh);
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
        mPlayerModel.LoadAll();
    }
}

void MainWindow::onDeletePlayer()
{
    QItemSelectionModel *selModel = ui->playersList->selectionModel();
    QModelIndexList selIndexes = selModel->selectedIndexes();

    if(selIndexes.count() == 0)
    {
        return;
    }

    QModelIndex index = selIndexes[0];
    int id = mPlayerModel.m_model.itemData(index).first().toInt();
    DatabaseManager::instance().mPlayerDao.RemovePlayer(id);
    mPlayerModel.LoadAll();
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

void MainWindow::onRefresh()
{
    switch(ui->stackedWidget->currentIndex())
    {
    case 0:
        mRankingModel.RefreshRanking();
        break;
    case 1:
       mPlayerModel.LoadAll();
        break;
    }
}
