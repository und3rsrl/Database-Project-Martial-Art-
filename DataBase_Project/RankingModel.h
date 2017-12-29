#ifndef RANKINGMODEL_H
#define RANKINGMODEL_H

#include <vector>
#include <QStandardItemModel>
#include "DatabaseManager.h"
#include "Player.h"

struct greater_than_score
{
    inline bool operator() (Player& left, Player& right)
    {
        return (left.GetScore() > right.GetScore());
    }
};

class RankingModel
{
public:
    RankingModel();
    QStandardItemModel m_model;

    void RefreshRanking();

private:
    void SetupModel();

    DatabaseManager& mDatabaseManager;
    std::vector<Player> mRanking;
};

#endif // RANKINGMODEL_H
