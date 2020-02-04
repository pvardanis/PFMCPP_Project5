#include "Visitor.h"
#include <iostream>

Visitor::Visitor(std::string myName, int myAge) :
name(myName),
age(myAge)
{}

Visitor::~Visitor()
{
    std::cout << "See you " << age << "!" << std::endl;
}
