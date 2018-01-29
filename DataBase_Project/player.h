#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player(int identifier, QString team, int score, int age, int weight);
    Player();
    //Player(Player &other);
    void SetScore(int points);
    int GetIdentifier();
    int GetWeight();
    int GetAge();
    QString GetTeam();
    int GetScore();

    //Player& operator=(Player &rhs);

private:
    int mIdentifier;
    int mScore;
    int mAge;
    int mWeight;
    QString mTeam;
};

#endif // PLAYER_H
