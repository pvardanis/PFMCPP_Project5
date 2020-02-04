#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Shape
{
    bool hasAngles;
    std::string color = "default";

    Shape();
    Shape(std::string yourColor);
    ~Shape();

    struct Circle
    {
        double radius;
        Circle();   
        Circle(double yourRadius); 
        double computeArea();
        
        ~Circle();
    };

    Circle generateRandomCircle(double minValue, double maxValue);
    JUCE_LEAK_DETECTOR(Shape)
};
