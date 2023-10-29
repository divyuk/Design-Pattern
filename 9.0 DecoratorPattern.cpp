/*
Decorator Pattern
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