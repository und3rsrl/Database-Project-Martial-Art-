#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <vector>
#include <memory>
#include <iterator>

#include "Player.h"
#include "DatabaseManager.h"

namespace Ui {
class MainWindow;
}

class PlayerModel
{
public:
    PlayerModel(Ui::MainWindow* ui);

    void LoadAll();
private:
    Ui::MainWindow *ui;
    DatabaseManager& mDatabaseManager;
    std::vector<Player> mPlayers;
    QStandardItemModel m_model;
};

#endif // PLAYERMODEL_H
