#include "CategoryModel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

CategoryModel::CategoryModel() :
    mDatabaseManager(DatabaseManager::instance()),
    mCategories(mDatabaseManager.mCategoryDao.Categories())
{
    m_model.clear();
    QStringList headerLabels;
    headerLabels << "Id" << "MinWeight" << "MaxWeight" << "MinAge" << "MaxAge";
    m_model.setHorizontalHeaderLabels(headerLabels);
    ui->playersList->setModel(&m_model);
}

void CategoryModel::LoadAll()
{
    mCategories = mDatabaseManager.mCategoryDao.Categories();

    for(Category category : mCategories)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(category.GetIdentifier()) << new QStandardItem(category.GetMinWeight()) << new QStandardItem(category.GetMaxWeight())
            << new QStandardItem(category.GetMinAge()) << new QStandardItem(category.GetMaxAge());
    }
}
