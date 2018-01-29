#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include <memory>
#include <iterator>
#include "player.h"
#include "Tour.h"
#include "DatabaseManager.h"

class Stage
{
public:
    Stage();
    int Simulate();

private:
    int mPoints;
    DatabaseManager& mDatabaseManager;
    std::vector<Player> mPlayers;
    std::vector<Tour> mTours;
};

#endif // STAGE_H
