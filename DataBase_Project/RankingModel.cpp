#include "RankingModel.h"

RankingModel::RankingModel() :
    mDatabaseManager(DatabaseManager::instance())
{
    RefreshRanking();
}

void RankingModel::RefreshRanking()
{
    SetupModel();

    mRanking = mDatabaseManager.mPlayerDao.Players();
    std::sort(mRanking.begin(), mRanking.end(), greater_than_score());

    for(Player player : mRanking)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(player.GetIdentifier())) << new QStandardItem(QString::number(player.GetScore()));
        m_model.appendRow(row);
    }
}

void RankingModel::SetupModel()
{
    m_model.clear();
    QStringList headerLabels;
    headerLabels << "Id" << "Score";
    m_model.setHorizontalHeaderLabels(headerLabels);
}
