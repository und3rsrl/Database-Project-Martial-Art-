#include "Player.h"

Player::Player(int identifier, QString team, int score, int age, int weight)
{
    mIdentifier = identifier;
    mTeam = team;
    mScore = score;
    mAge = age;
    mWeight = weight;
}

void Player::SetScore(int points)
{
    mScore += points;
}

int Player::GetScore()
{
    return mScore;
}

int Player::GetIdentifier()
{
    return mIdentifier;
}

int Player::GetAge()
{
    return mAge;
}

int Player::GetWeight()
{
    return mWeight;
}

QString Player::GetTeam()
{
    return mTeam;
}
