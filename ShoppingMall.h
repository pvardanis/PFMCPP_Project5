#pragma once

#include "Visitor.h"
#include "LeakedObjectDetector.h"
#include <vector>

struct ShoppingMall
{
    int numVisitors;
    int numCameras;
    double dailyEarnings;

    ShoppingMall();
    ShoppingMall(int visitors, int cameras);
    ~ShoppingMall();

    struct MensClothing
    {
        double totalCost;
        int salePercent = 30;
        std::vector<std::string> shops; // dunno why I get this padding warning
        double applyDiscount();
        
        ~MensClothing();
    };

    struct Cosmetics
    {
        int numOfPopUpStores;
        void greetCustomer();

        ~Cosmetics();
    };

    void superviseArea();
    void performCheck(std::vector<Visitor> customerDetails);

    JUCE_LEAK_DETECTOR(ShoppingMall)
};
