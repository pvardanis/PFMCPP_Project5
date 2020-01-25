/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}

/*
 copied UDT 1:
 */

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 */

/*
 new UDT 5:
 */

#include <iostream>
int main()
{
    example::main();
    std::cout << "good to go!" << std::endl;
}


#include <cmath>
#include <bits/stdc++.h> 
#include <iostream>
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
        Circle(double yourRadius) {radius = yourRadius;}
        double computeArea();
        
        ~Circle();
    };

    Circle generateRandomCircle(double minValue, double maxValue);
};

Shape::Shape(std::string yourColor) 
{
    color = yourColor;
    std::cout << color << " shape constructed." << std::endl;
}

Shape::~Shape()
{
    std::cout << color << " shape destructed." << std::endl;
}

Shape::Circle::~Circle()
{
    std::cout << "G*** circle." << std::endl;
}

double Shape::Circle::computeArea()
{
    double area;
    area = M_PI * pow(radius, 2);
    std::cout << "Circle of " << area << " m^2." << std::endl; 
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

    void makeSalad();
    bool fillBowl(bool hasIt, std::string item);
};

Kitchen::Kitchen(std::vector<std::string> myStock, std::vector<std::string> myRecipe) : 
recipe(myRecipe),
stock(myStock) 
{}

Kitchen::~Kitchen()
{
    if (fridgeIsEmpty)
    {
        std::cout << "Fridge is empty. F*** off kitchen!" << std::endl;
    }
    else
    {
        std::cout << "Nice meal!" << std::endl;
    }
}

void Kitchen::makeSalad()
{
    for (auto it1 = recipe.begin(); it1 != recipe.end(); ++it1)
    {
        std::string ingredient = *it1;
        bool filled = false;
        for (auto it2 = stock.begin(); it2 != stock.end(); ++it2) // this it overwrites the "it" above in this scope
        {
            std::string inStock = *it2;
            if (inStock == ingredient)
            {
                filled = fillBowl(true, ingredient);
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
        
    DailyActivities();
    ~DailyActivities();
};

DailyActivities::DailyActivities() 
{
    // I guess I could do that in struct's body as well
    std::cout << "Let's go shopping!" << std::endl;
    myShop->totalCost = 175.5;
    myShop->salePercent = 30;
}

DailyActivities::~DailyActivities()
{
    std::cout << "We have " << myShop->salePercent << "% discount today. Total cost is: " << myShop->applyDiscount() << "." << std::endl;

    std::cout << "Time to eat!" << std::endl;
    std::vector<std::string> stock = {"onion", "tomatoes", "peppers", "feta", "potatoes"};
    std::vector<std::string> recipe = {"onion", "tomatoes", "feta"};

    Kitchen kitchen(stock, recipe);
    Kitchen* myKitchen = &kitchen;
    myKitchen->makeSalad();
}

/*
 new UDT 5:
 */

struct Paint
{
    Shape shape;
    Shape* myShape = &shape;
    Paint(std::string color);
    ~Paint();

    void generatePaint(std::string paint);
};

Paint::Paint(std::string color) :
shape(color)
{
    std::cout << "Created shape of " << myShape->color << " color!" << std::endl;
}

Paint::~Paint()
{
    std::cout << "Paint is destructed before " << myShape->color << " shape." << std::endl;
}

void Paint::generatePaint(std::string paint)
{
    if (paint == "circle")
    {
        Shape::Circle circle = myShape->generateRandomCircle(1.0, 5.5);
        circle.computeArea();
    }
}

int main()
{
    example::main();
    DailyActivities dailyActivities;
    Paint paint("red");
    paint.generatePaint("circle");
    std::cout << "* This is printed before any variable destruction. That's how lifetime works! That's why the message 'We have 30% discount today... etc.' appears at the end of this program, because it's being executed inside dailyActivities's destructor and dailyActivities was created before paint (destruction follows the reverse order of construction) *" << std::endl;
}
