#include "CategoryModel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

CategoryModel::CategoryModel() :
    mDatabaseManager(DatabaseManager::instance())
{
    LoadAll();
}

void CategoryModel::LoadAll()
{
    SetupModel();

    mCategories = mDatabaseManager.mCategoryDao.Categories();

    for(Category category : mCategories)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(category.GetIdentifier())) << new QStandardItem(QString::number(category.GetMinWeight())) << new QStandardItem(QString::number(category.GetMaxWeight()))
            << new QStandardItem(QString::number(category.GetMinAge())) << new QStandardItem(QString::number(category.GetMaxAge()));
        m_model.appendRow(row);
    }
}

void CategoryModel::SetupModel()
{
    m_model.clear();
    QStringList headerLabels;
    headerLabels << "Id" << "MinWeight" << "MaxWeight" << "MinAge" << "MaxAge";
    m_model.setHorizontalHeaderLabels(headerLabels);
}
