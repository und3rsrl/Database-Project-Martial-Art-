#include "Player.h"

Player::Player(int identifier, QString team, int score, int age, int weight)
{
    mIdentifier = identifier;
    mTeam = team;
    mScore = score;
    mAge = age;
    mWeight = weight;
}

Player::Player()
{

}

//Player::Player(Player &other)
//{
//    mIdentifier = other.GetIdentifier();
//    mScore = other.GetScore();
//    mAge = other.GetAge();
//    mWeight = other.GetWeight();
//    mTeam = other.GetTeam();
//

void Player::SetScore(int points)
{
    mScore += points;
}

int Player::GetScore()
{
    return mScore;
}

//Player& Player::operator=(Player& rhs)
//{

//  if (this != &rhs) {
 //     mIdentifier = rhs.GetIdentifier();
  //    mScore = rhs.GetScore();
 //     mAge = rhs.GetAge();
 //     mWeight = rhs.GetWeight();
 //     mTeam = rhs.GetTeam();
//  }
//   return *this;
//}

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
