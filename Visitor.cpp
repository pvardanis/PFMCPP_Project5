#include "Visitor.h"
#include <iostream>

Visitor::~Visitor()
{
    std::cout << "See you " << age << "!" << std::endl;
}