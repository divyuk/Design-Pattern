#include <iostream>
using namespace std;

/*As a gneral term. ‘Factory’ are involved in creating stuff, so here the factory are involved in creating objects which are stuff in programming.
So you create an inteface for creating object and let the subclass decidie which class to instantiate
*/

//! Interface for the Pizza
class Pizza
{
public:
    virtual void createPizza() = 0;
};

class MexicanGreenWave : public Pizza
{
public:
    void createPizza() override
    {
        cout << "Green Wave Pizza 🌶\n";
    }
};
class Cheesy : public Pizza
{
public:
    void createPizza() override
    {
        cout << "Cheesy Pizza 🌶\n";
    }
};

class PizzaFactory
{
public:
    Pizza *takeOrder(const string &order)
    {
        if (order == "Cheesy")
            return new Cheesy();
        else if (order == "Mexican Green Wave")
            return new MexicanGreenWave();
        return nullptr;
    }
};

int main()
{
    // Pizza *pizza = PizzaFactory::takeOrder("Cheesy");
    // pizza->createPizza();

    PizzaFactory factory;
    Pizza *pizza = factory.takeOrder("Cheesy");
    pizza->createPizza();

    delete pizza; // Don't forget to free the allocated memory.

    return 0;
}