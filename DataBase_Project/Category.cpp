#include "Category.h"

category::category(int identifier, int minWeight, int maxWeight, int minAge, int maxAge)
{
    mIdentifier = identifier;
    mMinWeight = minWeight;
    mMaxWeight = maxWeight;
    mMinAge = minAge;
    mMaxAge = maxAge;
}

int category::GetIdentifier()
{
    return mIdentifier;
}

int category::GetMinWeight()
{
    return mMinWeight;
}

int category::GetMaxWeight()
{
    return mMaxWeight;
}

int category::GetMinAge()
{
    return minAge;
}

int category::GetMaxAge()
{
    return maxAge;
}
