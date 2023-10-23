#include <iostream>
using namespace std;

// Pizza Interface
class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

// Concrete Class to Make Pizza
class NYStyleCheesePizza : public Pizza
{
public:
    void prepare() override
    {
        cout << "NY Preparing started\n";
    }
    void bake() override
    {
        cout << "Baking the Pizza in NY temp\n";
    }
    void cut() override
    {
        cout << "Cutting with NY specification cut\n";
    }
    void box() override
    {
        cout << "Placing in NY boxes\n";
    }
};

// Concrete Class to Make Pizza
class ChicagoStyleCheesePizza : public Pizza
{
public:
    void prepare() override
    {
        cout << "Chicago Preparing started\n";
    }
    void bake() override
    {
        cout << "Baking the Pizza in Chicago temp\n";
    }
    void cut() override
    {
        cout << "Cutting with Chicago specification cut\n";
    }
    void box() override
    {
        cout << "Placing in Chicago boxes\n";
    }
};

// Interface for creating Pizza
class PizzaFactory
{
public:
    virtual Pizza *createPizza() = 0;
};

// Concrete Factories
class NYStylePizzaFactory : public PizzaFactory
{
public:
    Pizza *createPizza() override
    {
        return new NYStyleCheesePizza();
    }
};
class ChicagoStylePizzaFactory : public PizzaFactory
{
public:
    Pizza *createPizza() override
    {
        return new ChicagoStyleCheesePizza();
    }
};

int main()
{
    PizzaFactory *factory = new NYStylePizzaFactory(); // base class pointer pointing to derived
    Pizza *nyCheese = factory->createPizza();
    nyCheese->prepare();
    nyCheese->bake();
    nyCheese->cut();
    nyCheese->box();
}