#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QStandardItemModel>
#include <vector>
#include <memory>
#include <iterator>

#include "Player.h"
#include "DatabaseManager.h"


class PlayerModel
{
public:
    PlayerModel();

    void LoadAll();
    QStandardItemModel m_model;

private:
    void SetupModel();

    DatabaseManager& mDatabaseManager;
    std::vector<Player> mPlayers; 
};

#endif // PLAYERMODEL_H
