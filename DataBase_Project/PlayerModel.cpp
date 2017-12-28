#include "PlayerModel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

PlayerModel::PlayerModel() :
    mDatabaseManager(DatabaseManager::instance()),
    mPlayers(mDatabaseManager.mPlayerDao.Players())
{
    m_model.clear();
    QStringList headerLabels;
    headerLabels << "Id" << "Score" << "Team" << "Age" << "Weight";
    m_model.setHorizontalHeaderLabels(headerLabels);
    ui->playersList->setModel(&m_model);
}

void PlayerModel::LoadAll()
{
    mPlayers = mDatabaseManager.mPlayerDao.Players();

    for(Player player : mPlayers)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(player.GetIdentifier()) << new QStandardItem(player.GetScore()) << new QStandardItem(player.GetTeam())
            << new QStandardItem(player.GetAge()) << new QStandardItem(player.GetWeight());
    }
}
