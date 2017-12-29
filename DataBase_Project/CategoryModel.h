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

    void SetupModel();


    QStandardItemModel m_model;
private:
    Ui::MainWindow *ui;
    DatabaseManager& mDatabaseManager;
    std::vector<Category> mCategories;

};

#endif // CATEGORYMODEL_H
