#include "PlayerModel.h"
#include <QDebug>

PlayerModel::PlayerModel() :
    mDatabaseManager(DatabaseManager::instance())
{
    LoadAll();
}

void PlayerModel::LoadAll()
{
    SetupModel();

    mPlayers = mDatabaseManager.mPlayerDao.Players();

    for(Player player : mPlayers)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(player.GetIdentifier())) << new QStandardItem(QString::number(player.GetScore())) << new QStandardItem(player.GetTeam())
            << new QStandardItem(QString::number(player.GetAge())) << new QStandardItem(QString::number(player.GetWeight()));
        m_model.appendRow(row);
    }
}

void PlayerModel::SetupModel()
{
    m_model.clear();
    QStringList headerLabels;
    headerLabels << "Id" << "Score" << "Team" << "Age" << "Weight";
    m_model.setHorizontalHeaderLabels(headerLabels);
}
