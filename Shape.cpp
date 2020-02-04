#include "Shape.h"
#include <iostream>
#include <cmath>

Shape::Shape() 
{}

Shape::Shape(std::string yourColor) 
{
    this->color = yourColor;
    std::cout << this->color << " shape constructed." << std::endl;
}

Shape::~Shape()
{
    std::cout << this->color << " shape destructed." << std::endl;
}

Shape::Circle::Circle() {}

Shape::Circle::~Circle()
{
    std::cout << "Circle destructed. G*** circle." << std::endl;
}

Shape::Circle::Circle(double yourRadius) {this->radius = yourRadius;}

double Shape::Circle::computeArea()
{
    double area;
    area = M_PI * pow(radius, 2);
    // std::cout << "Circle of " << area << " m^2." << std::endl; 
    return area;
}

Shape::Circle Shape::generateRandomCircle(double minValue, double maxValue)
{
    double randomRadius = fmod(double(rand()), (maxValue - minValue + 0.001));

    while (randomRadius < (minValue + maxValue) / 2) // doesn't really make sense
    {
        double temp = fmod(double(rand()), (maxValue - minValue + 0.001));
        randomRadius = temp;
    }

    std::cout << "Generated random circle of radius " << randomRadius << " m." << std::endl;
    return Circle(randomRadius); 
}
