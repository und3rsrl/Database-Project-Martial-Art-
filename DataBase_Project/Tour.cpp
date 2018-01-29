#include "Tour.h"
#include <stdlib.h>
#include <time.h>

Tour::Tour(Player player1, Player player2)
{
    mPlayer1 = player1;
    mPlayer2 = player2;
}

Player Tour::GetWinner()
{
    return winner;
}

Player Tour::GetLoser()
{
    return loser;
}

void Tour::Simulate()
{
    srand (time(NULL));
    int player1Score = rand() % 100 + 1;
    int player2Score = rand() % 100 + 1;

    while(player1Score == player2Score)
    {
        int player1Score = rand() % 100 + 1;
        int player2Score = rand() % 100 + 1;
    }

    if(player1Score > player2Score)
    {
       winner = mPlayer1;
       loser = mPlayer2;
    }
    else
    {
        winner = mPlayer2;
        loser = mPlayer1;
    }
}
