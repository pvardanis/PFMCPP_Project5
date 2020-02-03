#pragma once

#include "LeakedObjectDetector.h"
#include <vector>

struct Kitchen
{
    int numKnifes = 5;
    bool fridgeIsEmpty = false; // always true :(
    std::vector<std::string> recipe;
    std::vector<std::string> stock;

    Kitchen() {}
    Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe);
    ~Kitchen();

    void printRecipe();

    std::string food = "spaghetti";
    void makeSalad();
    bool fillBowl(bool hasIt, std::string item);

    JUCE_LEAK_DETECTOR(Kitchen)
};
