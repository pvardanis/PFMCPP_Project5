#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Visitor
{
    std::string name;
    int age;

    Visitor(std::string myName, int myAge) :
    name(myName),
    age(myAge)
    {}

    ~Visitor();
};
