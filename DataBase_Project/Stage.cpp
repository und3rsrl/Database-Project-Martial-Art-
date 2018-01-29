#include "Stage.h"

Stage::Stage() :
    mDatabaseManager(DatabaseManager::instance()),
    mPlayers(mDatabaseManager.mPlayerDao.Players())
{
    mPoints = 10;
}

void Stage::Simulate()
{
    while(mPlayers.size() > 1)
    {
        qDebug("Ma distrez");

        for(int i = 0; i <= mPlayers.size() / 2; i += 2)
        {
            mTours.push_back(Tour(mPlayers[i], mPlayers[i + 1]));
        }

        for(Tour tour : mTours)
        {
           tour.Simulate();
           Player winner = tour.GetWinner();
           winner.SetScore(mPoints);

           mDatabaseManager.mPlayerDao.UpdatePlayer(winner);

           for(auto player = mPlayers.begin(), itEnd = mPlayers.end(); player != itEnd; player++ )
           {
              if(player->GetIdentifier() == tour.GetLoser().GetIdentifier())
              {
                  mPlayers.erase(player);
                  break;
              }
           }
        }

        mPoints++;
        mTours.clear();
    }
}