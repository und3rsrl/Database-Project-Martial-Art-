#include "PlayerDao.h"
#include "Player.h"
#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace std;

const QString DATABASE_TABLE_NAME = "Players";

PlayerDao::PlayerDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void PlayerDao::init() const
{
    if(!mDatabase.tables().contains(DATABASE_TABLE_NAME))
    {
        QSqlQuery query(mDatabase);
        query.prepare("CREATE TABLE Players ( Id int PRIMARY KEY, Score int, Team text, Age int, Weight int);");
        query.exec();
    }
}

void PlayerDao::AddPlayer(Player& player)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE"
                  "     Players"
                  "SET "
                  "     Score = (:score),"
                  "     Team = (:team),"
                  "     Age = (:age),"
                  "     Weight = (:weight)"
                  "WHERE "
                  "     Id = (:id)");
        query.bindValue(":id", player.GetIdentifier());
        query.bindValue(":score", player.GetScore());
        query.bindValue(":team", player.GetTeam());
        query.bindValue(":age", player.GetAge());
        query.bindValue(":weight", player.GetWeight());
        query.exec();
}

void PlayerDao::UpdatePlayer(Player& player)
{
    QSqlQuery query(mDatabase);
        query.prepare("UPDATE "
                      "     Players"
                      "SET"
                      "      score = (:score)"
                      "WHERE"
                      "      id = (:id)");
        query.bindValue(":score", player.GetScore());
        query.bindValue(":id", player.GetIdentifier());
        query.exec();
}


void PlayerDao::RemovePlayer(int identifier)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE"
                  "FROM"
                  "     Players "
                  "WHERE "
                  "     id = (:id)");
    query.bindValue(":id", identifier);
    query.exec();
}

unique_ptr<vector<unique_ptr<Player>>> PlayerDao::Players() const
{
    QSqlQuery query("SELECT * FROM Players", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Player>>> playerList(new vector<unique_ptr<Player>>());
    while(query.next()) {

        int id = query.value("Id").toInt();
        QString team = query.value("Team").toString();
        int age = query.value("Age").toInt();
        int weight = query.value("Weight").toInt();
        int score = query.value("Score").toInt();

        unique_ptr<Player> player(new Player(id, team, score, age, weight));
        playerList->push_back(move(player));
    }

    return playerList;
}