#ifndef CATEGORYMODEL_H
#define CATEGORYMODEL_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <vector>
#include <memory>
#include <iterator>

#include "Category.h"
#include "DatabaseManager.h"

namespace Ui {
class MainWindow;
}

class CategoryModel
{
public:
    CategoryModel();

    void LoadAll();

private:
    Ui::MainWindow *ui;
    DatabaseManager& mDatabaseManager;
    std::vector<Category> mCategories;
    QStandardItemModel m_model;
};

#endif // CATEGORYMODEL_H
