#pragma once

#include "Shape.h"
#include "LeakedObjectDetector.h"
#include <iostream>

struct Paint
{
    Shape shape;
    Shape* myShape = &shape;
    Paint(std::string color);
    Paint();
    ~Paint();

    void printArea();
    void generatePaint(std::string paint);    

    Shape::Circle circle;
    
    JUCE_LEAK_DETECTOR(Paint)
};
