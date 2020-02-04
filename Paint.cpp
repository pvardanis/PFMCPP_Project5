#include "Paint.h"
#include <iostream>

Paint::Paint(std::string color) :
shape(color)
{
    std::cout << "Created paint with shape of " << this->myShape->color << " color!" << std::endl;
}

Paint::~Paint()
{
    std::cout << "Paint is destructed before " << this->myShape->color << " shape." << std::endl;
}

void Paint::generatePaint(std::string paint)
{
    if (paint == "circle")
    {
        this->circle = this->myShape->generateRandomCircle(1.0, 5.5);
    }
}

void Paint::printArea()
{
    std::cout << "Circle: Circle of " << this->circle.computeArea() << "m^2." << std::endl; 
}
