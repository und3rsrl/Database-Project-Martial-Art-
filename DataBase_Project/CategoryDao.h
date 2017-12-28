#ifndef CATEGORYDAO_H
#define CATEGORYDAO_H

#include <vector>

class QSqlDatabase;
class Category;

class CategoryDao
{
public:
    CategoryDao(QSqlDatabase& database);
    void init() const;

    void AddCategory(Category& category);
    void RemoveCategory(int identifier);
    std::vector<Category> Categories() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // CATEGORYDAO_H
