#ifndef PLAYERDAO_H
#define PLAYERDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Player;

class PlayerDao
{
public:
    PlayerDao(QSqlDatabase& database);
    void init() const;

    void AddPlayer(Player& player);
    void UpdatePlayer(Player& player);
    void RemovePlayer(int identifier);
    std::unique_ptr<std::vector<std::unique_ptr<Player>>> Players() const;

private:
    bool PlayerExist(int identifier);

    QSqlDatabase& mDatabase;
};

#endif // PLAYERDAO_H
