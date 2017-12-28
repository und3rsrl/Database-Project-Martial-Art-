#include "CategoryDao.h"
#include "Category.h"
#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

const QString DATABASE_TABLE_NAME = "Categories";

using namespace std;

CategoryDao::CategoryDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void CategoryDao::init() const
{
    if(!mDatabase.tables().contains(DATABASE_TABLE_NAME))
    {
        QSqlQuery query(mDatabase);
        query.prepare("CREATE TABLE Categories ( Id int PRIMARY KEY, MinWeight int, MaxWeight int, MinAge int, MaxAge int);");
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

void CategoryDao::AddCategory(Category& category)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO"
                  "     Categories"
                  "(Id, MinWeight, MaxWeight, MinAge, MaxAge)"
                  "VALUES (:id, :minWeight, :maxWeight, :minAge, :maxAge)");
        query.bindValue(":id", category.GetIdentifier());
        query.bindValue(":minWeight", category.GetMinWeight());
        query.bindValue(":maxWeight", category.GetMaxWeight());
        query.bindValue(":minAge", category.GetMinAge());
        query.bindValue(":maxAge", category.GetMaxAge());
        query.exec();
}

void CategoryDao::RemoveCategory(int identifier)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE"
                  "FROM"
                  "     Categories"
                  "WHERE "
                  "     id = (:id)");
    query.bindValue(":id", identifier);
    query.exec();
}

vector<Category> CategoryDao::Categories() const
{
    QSqlQuery query("SELECT * FROM Categories", mDatabase);
    query.exec();
    vector<Category> categoryList;
    while(query.next()) {
        int id = query.value("Id").toInt();
        int minWeight = query.value("MinWeight").toInt();
        int maxWeight = query.value("MaxWeight").toInt();
        int minAge = query.value("MinAge").toInt();
        int maxAge = query.value("MaxAge").toInt();

        Category category(id, minWeight, maxWeight, minAge, maxAge);

        categoryList.push_back(category);
    }

    return categoryList;
}
