#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player(int identifier, QString team, int score, int age, int weight);
    void SetScore(int points);
    int GetIdentifier();
    int GetWeight();
    int GetAge();
    int GetTeam();
    int GetScore();

private:
    int mIdentifier;
    int mScore;
    int mAge;
    int mWeight;
    QString mTeam;
};

#endif // PLAYER_H
