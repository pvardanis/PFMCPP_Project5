/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <cmath>
#include <bits/stdc++.h> 
#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
*/

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

Visitor::~Visitor()
{
    std::cout << "See you " << age << "!" << std::endl;
}

struct ShoppingMall
{
    int numVisitors;
    int numCameras;
    double dailyEarnings;

    ShoppingMall() {}
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

ShoppingMall::ShoppingMall(int visitors, int cameras) 
{
    numVisitors = visitors;
    numCameras = cameras;
}

ShoppingMall::~ShoppingMall() 
{
    std::cout << "Bye bye, ShoppingMall!" << std::endl;
}

ShoppingMall::MensClothing::~MensClothing()
{
    std::cout << "Thanks for your visit!" << std::endl;
}

ShoppingMall::Cosmetics::~Cosmetics()
{
    std::cout << "Thanks for your visit!" << std::endl;
}

double ShoppingMall::MensClothing::applyDiscount()
{
    return (1 - (salePercent / 100.)) * totalCost;
}

void ShoppingMall::Cosmetics::greetCustomer()
{
    std::cout << "Hello sir!" << std::endl;
}

void ShoppingMall::superviseArea()
{
    if (numVisitors < 500) 
        std::cout << "Everything all right! You don't have to worry for just " << numVisitors << "!" << std::endl;
    else if (numCameras < 50) 
        std::cout << "We need more cameras! " << numCameras << " are not enough!" << std::endl;         
}

void ShoppingMall::performCheck(std::vector<Visitor> customerDetails)
{
    std::vector<Visitor> entered;
    for( auto it = customerDetails.begin(); it != customerDetails.end(); ++it )
    {
        std::cout << "Could you please give me your details? ";
        auto age = (*it).age;
        auto name = (*it).name;
        std::cout << "My name is " << name  << " and I'm " << age  << " years old." << std::endl;
       
        if (age < 18)
        {
            std::cout << "Sorry sir! You are not allowed to enter!" << std::endl;
        } 
        else
        {
            std::cout << "Come in!" << std::endl;
            numVisitors += 1;
            entered.push_back(*it);
        }
    }

    std::cout << "List of people who entered: " << std::endl;
    for ( auto it = entered.begin(); it != entered.end(); ++it )
    {
        auto name = (*it).name;
        std::cout << name << std::endl;
    }
}

/*
 copied UDT 2:
 */

struct Shape
{
    bool hasAngles;
    std::string color = "default";

    Shape() {}
    Shape(std::string yourColor);
    ~Shape();

    struct Circle
    {
        double radius;
        Circle() {}
        Circle(double yourRadius) {this->radius = yourRadius;}
        double computeArea();
        
        ~Circle();
    };

    Circle generateRandomCircle(double minValue, double maxValue);
    JUCE_LEAK_DETECTOR(Shape)
};

Shape::Shape(std::string yourColor) 
{
    this->color = yourColor;
    std::cout << this->color << " shape constructed." << std::endl;
}

Shape::~Shape()
{
    std::cout << this->color << " shape destructed." << std::endl;
}

Shape::Circle::~Circle()
{
    std::cout << "Circle destructed. G*** circle." << std::endl;
}

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

/*
 copied UDT 3:
 */

struct Kitchen
{
    int numKnifes = 5;
    bool fridgeIsEmpty = false; // always true :(
    std::vector<std::string> recipe;
    std::vector<std::string> stock;

    Kitchen() {}
    Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe);
    ~Kitchen();

    void printRecipe()
    {
        std::cout << "Kitchen: " << this->food << std::endl;
    }

    std::string food = "spaghetti";
    void makeSalad();
    bool fillBowl(bool hasIt, std::string item);

    JUCE_LEAK_DETECTOR(Kitchen)
};

Kitchen::Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe) : 
recipe(myRecipe),
stock(myStock) 
{}

Kitchen::~Kitchen()
{
    if (this->fridgeIsEmpty)
    {
        std::cout << "Kitchen destructed. Fridge is empty. F*** off kitchen!" << std::endl;
    }
    else
    {
        std::cout << "Kitchen destructed. Nice meal!" << std::endl;
    }
}

void Kitchen::makeSalad()
{
    for (auto it1 = this->recipe.begin(); it1 != this->recipe.end(); ++it1)
    {
        std::string ingredient = *it1;
        bool filled = false;
        for (auto it2 = this->stock.begin(); it2 != this->stock.end(); ++it2) // this it overwrites the "it" above in this scope
        {
            std::string inStock = *it2;
            if (inStock == ingredient)
            {
                filled = this->fillBowl(true, ingredient);
                break;
            }
        }
        if (!filled)
        {
            std::cout << ingredient << " not found! You can't make this salad!" << std::endl;
            break;
        }
    }
}

bool Kitchen::fillBowl(bool hasIt, std::string item)
{
    if (hasIt)
    {
        std::cout << "Filled with: " << item << std::endl;
        return true;
    }
    return false;
}

/*
 new UDT 4:
 */
struct DailyActivities
{
    ShoppingMall::MensClothing shop;
    ShoppingMall::MensClothing* myShop = &shop;
        
    void printVariables()
    {
        std::cout << "DailyActivities: We have " << this->myShop->salePercent << "% discount today. Total cost is: " << this->myShop->applyDiscount() << "." << std::endl;    
    }

    Kitchen kitchen;
    
    DailyActivities();
    ~DailyActivities();

    JUCE_LEAK_DETECTOR(DailyActivities)
};

DailyActivities::DailyActivities() 
{
    // I guess I could do that in struct's body as well
    std::cout << "DailyActivities constructed. Let's go shopping!" << std::endl;
    this->myShop->totalCost = 175.5;
    this->myShop->salePercent = 30;
}

DailyActivities::~DailyActivities()
{
    std::cout << "DailyActivities destructed." << std::endl;
    std::cout << "Time to eat!" << std::endl;
}

struct DailyActivitiesWrapper
{
    DailyActivitiesWrapper( DailyActivities* ptr ) : pointerToDailyActivities( ptr ) {}
    ~DailyActivitiesWrapper()
    {
        delete pointerToDailyActivities;
    }

    DailyActivities* pointerToDailyActivities = nullptr; 
};

/*
 new UDT 5:
 */

struct Paint
{
    Shape shape;
    Shape* myShape = &shape;
    Paint(std::string color);
    Paint();
    ~Paint();

    void generatePaint(std::string paint);    

    void printArea()
    {
        std::cout << "Circle: Circle of " << this->circle.computeArea() << "m^2." << std::endl; 
    }

    Shape::Circle circle;
    
    JUCE_LEAK_DETECTOR(Paint)
};

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

struct PaintWrapper
{
    PaintWrapper( Paint* ptr ) : pointerToPaint( ptr ) {}
    ~PaintWrapper()
    {
        delete pointerToPaint;
    }

    Paint* pointerToPaint = nullptr; 
};

int main()
{

    DailyActivitiesWrapper dailyActivitiesWrapper(new DailyActivities);
    // DailyActivities dailyActivities;
    // std::cout << "dailyActivities: We have " << dailyActivities.myShop->salePercent << "% discount today. Total cost is: " << dailyActivities.myShop->applyDiscount() << "." << std::endl;  
    // dailyActivities.printVariables();
    std::cout << "dailyActivities: We have " << dailyActivitiesWrapper.pointerToDailyActivities->myShop->salePercent << "% discount today. Total cost is: " << dailyActivitiesWrapper.pointerToDailyActivities->myShop->applyDiscount() << "." << std::endl;  
    dailyActivitiesWrapper.pointerToDailyActivities->printVariables();


    std::cout << "kitchen: " << dailyActivitiesWrapper.pointerToDailyActivities->kitchen.food << std::endl;
    dailyActivitiesWrapper.pointerToDailyActivities->kitchen.printRecipe();

    PaintWrapper paintWrapper(new Paint("red"));
    // Paint paint("red");
    // paint.generatePaint("circle");
    // std::cout << "circle: Circle of " << paint.circle.computeArea() << " m^2." << std::endl;
    // paint.printArea();
    paintWrapper.pointerToPaint->generatePaint("circle");
    std::cout << "circle: Circle of " << paintWrapper.pointerToPaint->circle.computeArea() << " m^2." << std::endl;
    paintWrapper.pointerToPaint->printArea();
}
