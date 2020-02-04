#include "ShoppingMall.h"
#include <iostream>

ShoppingMall::ShoppingMall() {}

ShoppingMall::ShoppingMall(int visitors, int cameras) 
{
    numVisitors = visitors;
    numCameras = cameras;
}

ShoppingMall::~ShoppingMall() 
{
    std::cout << "Bye bye, ShoppingMall!" << std::endl;
}

ShoppingMall::MensClothing::~MensClothing()
{
    std::cout << "Thanks for your visit!" << std::endl;
}

ShoppingMall::Cosmetics::~Cosmetics()
{
    std::cout << "Thanks for your visit!" << std::endl;
}

double ShoppingMall::MensClothing::applyDiscount()
{
    return (1 - (salePercent / 100.)) * totalCost;
}

void ShoppingMall::Cosmetics::greetCustomer()
{
    std::cout << "Hello sir!" << std::endl;
}

void ShoppingMall::superviseArea()
{
    if (numVisitors < 500) 
        std::cout << "Everything all right! You don't have to worry for just " << numVisitors << "!" << std::endl;
    else if (numCameras < 50) 
        std::cout << "We need more cameras! " << numCameras << " are not enough!" << std::endl;         
}

void ShoppingMall::performCheck(std::vector<Visitor> customerDetails)
{
    std::vector<Visitor> entered;
    for( auto it = customerDetails.begin(); it != customerDetails.end(); ++it )
    {
        std::cout << "Could you please give me your details? ";
        auto age = (*it).age;
        auto name = (*it).name;
        std::cout << "My name is " << name  << " and I'm " << age  << " years old." << std::endl;
       
        if (age < 18)
        {
            std::cout << "Sorry sir! You are not allowed to enter!" << std::endl;
        } 
        else
        {
            std::cout << "Come in!" << std::endl;
            numVisitors += 1;
            entered.push_back(*it);
        }
    }

    std::cout << "List of people who entered: " << std::endl;
    for ( auto it = entered.begin(); it != entered.end(); ++it )
    {
        auto name = (*it).name;
        std::cout << name << std::endl;
    }
}
