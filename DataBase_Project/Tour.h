#ifndef TOUR_H
#define TOUR_H
#include "Player.h"

class Tour
{
public:
    Tour(Player player1, Player player2);
    Player GetWinner();
    Player GetLoser();
    void Simulate();
private:
    Player mPlayer1;
    Player mPlayer2;
    Player winner;
    Player loser;
};

#endif // TOUR_H
