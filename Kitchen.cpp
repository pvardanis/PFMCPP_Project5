#include "Kitchen.h"
#include <iostream>

Kitchen::Kitchen() {}

Kitchen::Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe) : 
recipe(myRecipe),
stock(myStock) 
{}

Kitchen::~Kitchen()
{
    if (this->fridgeIsEmpty)
    {
        std::cout << "Kitchen destructed. Fridge is empty. F*** off kitchen!" << std::endl;
    }
    else
    {
        std::cout << "Kitchen destructed. Nice meal!" << std::endl;
    }
}

void Kitchen::makeSalad()
{
    for (auto it1 = this->recipe.begin(); it1 != this->recipe.end(); ++it1)
    {
        std::string ingredient = *it1;
        bool filled = false;
        for (auto it2 = this->stock.begin(); it2 != this->stock.end(); ++it2) // this it overwrites the "it" above in this scope
        {
            std::string inStock = *it2;
            if (inStock == ingredient)
            {
                filled = this->fillBowl(true, ingredient);
                break;
            }
        }
        if (!filled)
        {
            std::cout << ingredient << " not found! You can't make this salad!" << std::endl;
            break;
        }
    }
}

bool Kitchen::fillBowl(bool hasIt, std::string item)
{
    if (hasIt)
    {
        std::cout << "Filled with: " << item << std::endl;
        return true;
    }
    return false;
}

void Kitchen::printRecipe()
{
    std::cout << "Kitchen: " << this->food << std::endl;
}

    
