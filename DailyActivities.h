#pragma once

#include "ShoppingMall.h"
#include "Kitchen.h"
#include "LeakedObjectDetector.h"

struct DailyActivities
{
    ShoppingMall::MensClothing shop;
    ShoppingMall::MensClothing* myShop = &shop;
        
    void printVariables();

    Kitchen kitchen;
    
    DailyActivities();
    ~DailyActivities();

    JUCE_LEAK_DETECTOR(DailyActivities)
};
