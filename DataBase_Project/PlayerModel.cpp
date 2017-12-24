#include "PlayerModel.h"

PlayerModel::PlayerModel(QObject* parent = 0):
    QAbstractListModel(parent),
    mDatabaseManager(DatabaseManager::instance()),
    mPlayers(mDatabaseManager.mPlayerDao.Players())
{
}

QModelIndex PlayerModel::AddPlayer(const Player &player)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Player> newPlayer(new Player(player));
    mDatabaseManager.mPlayerDao.AddPlayer(*newPlayer);
    mPlayers->push_back(move(newPlayer));
    endInsertRows();
    return index(rowIndex, 0);
}
