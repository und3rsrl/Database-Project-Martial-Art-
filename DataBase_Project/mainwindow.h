#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PlayerModel.h"
#include "RankingModel.h"
#include "CategoryModel.h"

#include <QMainWindow>
#include <memory>
#include <QActionGroup>


namespace Ui {
class MainWindow;

}

class AddItemDialog;
class AddCategoryDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:
    void onAddPlayer();
    void onAddCategory();
    void onDeletePlayer();
    void onDeleteCategory();
    void onViewTriggered(QAction *action);
    void onRefresh();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddItemDialog> mAddItemDialog;
    std::unique_ptr<AddCategoryDialog> mAddCategoryDialog;
    std::unique_ptr<QActionGroup> mViews;
    PlayerModel mPlayerModel;
    RankingModel mRankingModel;
    CategoryModel mCategoryModel;
};

#endif // MAINWINDOW_H
