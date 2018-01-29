#include "PlayerDao.h"
#include "Player.h"
#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

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
        if(query.exec())
        {
            qDebug() << "Creat";
        }
        else
        {
            qDebug() << "Necreat";
        }
    }
}

void PlayerDao::AddPlayer(Player& player)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO"
                  "     Players"
                  "(id, Score, Team, Age, Weight)"
                  "VALUES (:id, :score, :team, :age, :weight)");
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
        query.prepare("UPDATE Players SET score = :score WHERE id = :id");
        query.bindValue(":score", player.GetScore());
        query.bindValue(":id", player.GetIdentifier());
        query.exec();
}


void PlayerDao::RemovePlayer(int identifier)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Players WHERE Id = (:id)");
    query.bindValue(":id", identifier);
    qDebug() << query.exec();
}

vector<Player> PlayerDao::Players() const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Players");
    query.exec();

    vector<Player> playerList;
    while(query.next()) {

        int id = query.value("Id").toInt();
        QString team = query.value("Team").toString();
        int age = query.value("Age").toInt();
        int weight = query.value("Weight").toInt();
        int score = query.value("Score").toInt();

        Player player(id, team, score, age, weight);


        playerList.push_back(player);
    }

    return playerList;
}
