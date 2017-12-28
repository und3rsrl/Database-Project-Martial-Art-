#ifndef CATEGORY_H
#define CATEGORY_H


class Category
{
public:
    Category(int identifier, int minWeight, int maxWeight, int minAge, int maxAge);

    int GetIdentifier();
    int GetMinWeight();
    int GetMaxWeight();
    int GetMinAge();
    int GetMaxAge();
private:
    int mIdentifier;
    int mMinWeight;
    int mMaxWeight;
    int mMinAge;
    int mMaxAge;
};

#endif // CATEGORY_H
