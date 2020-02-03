#include "DailyActivities.h"
#include <iostream>

DailyActivities::DailyActivities() 
{
    // I guess I could do that in struct's body as well
    std::cout << "DailyActivities constructed. Let's go shopping!" << std::endl;
    this->myShop->totalCost = 175.5;
    this->myShop->salePercent = 30;
}

DailyActivities::~DailyActivities()
{
    std::cout << "DailyActivities destructed." << std::endl;
    std::cout << "Time to eat!" << std::endl;
}

void DailyActivities::printVariables()
{
    std::cout << "DailyActivities: We have " << this->myShop->salePercent << "% discount today. Total cost is: " << this->myShop->applyDiscount() << "." << std::endl;    
}