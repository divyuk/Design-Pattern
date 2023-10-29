/*
Decorator Pattern
The Decorator Pattern is a structural design pattern that allows behavior to be added to individual objects, either statically or dynamically, without affecting the behavior of other objects from the same class

💡 The key idea behind the Decorator Pattern is to create a set of decorator classes that are used to wrap concrete components. These decorators provide additional functionality while keeping the core interface of the component class intact.

“Wrapper” is the alternative nickname for the Decorator pattern that clearly expresses the main idea of the pattern. A *wrapper* is an object that can be linked with some *target* object. The wrapper contains the same set of methods as the target and delegates to it all requests it receives. However, the wrapper may alter the result by doing something either before or after it passes the request to the target.
*/
#include <iostream>
using namespace std;

class Coffee
{
public:
    virtual double cost() = 0;
};
class Espresso : public Coffee
{
public:
    double cost() override
    {
        return 120;
    }
};

// Decorator for Coffee
class CoffeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeDecorator(Coffee *c) : coffee(c) {}

    double cost() override
    {
        return coffee->cost();
    }
};

// Concrete Decorator 1
class MilkDecorator : public CoffeDecorator
{
public:
    MilkDecorator(Coffee *c) : CoffeDecorator(c) {}
    double cost() override
    {
        return coffee->cost() + 10;
    }
};
// Concrete Decorator 2
class SugarDecorator : public CoffeDecorator
{
public:
    SugarDecorator(Coffee *c) : CoffeDecorator(c) {}
    double cost() override
    {
        return coffee->cost() + 4;
    }
};
int main()
{
    Coffee *espresso = new Espresso();
    Coffee *milkCoffee = new MilkDecorator(espresso);
    Coffee *sweetCoffee = new SugarDecorator(milkCoffee);

    std::cout << "Espresso cost: $" << espresso->cost() << std::endl;
    std::cout << "Milk Coffee cost: $" << milkCoffee->cost() << std::endl;
    std::cout << "Sweet Coffee cost: $" << sweetCoffee->cost() << std::endl;

    delete sweetCoffee;
    delete milkCoffee;
    delete espresso;

    return 0;
}