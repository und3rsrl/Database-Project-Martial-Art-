#include "Category.h"

Category::Category(int identifier, int minWeight, int maxWeight, int minAge, int maxAge)
{
    mIdentifier = identifier;
    mMinWeight = minWeight;
    mMaxWeight = maxWeight;
    mMinAge = minAge;
    mMaxAge = maxAge;
}

int Category::GetIdentifier()
{
    return mIdentifier;
}

int Category::GetMinWeight()
{
    return mMinWeight;
}

int Category::GetMaxWeight()
{
    return mMaxWeight;
}

int Category::GetMinAge()
{
    return mMinAge;
}

int Category::GetMaxAge()
{
    return mMaxAge;
}
