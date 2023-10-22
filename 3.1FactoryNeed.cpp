#include <iostream>
using namespace std;

class Pizza
{
public:
    virtual void createPizza() = 0;
};

class Cheesy : public Pizza
{
public:
    void createPizza() override
    {
        cout << "Cheesy baked";
    }
};

class Mexican : public Pizza
{
public:
    void createPizza() override
    {
        cout << "Mexican baked";
    }
};

//? Imagine this is your client, you have closed dependency with the
//? classes, Cheesy, Mexican

int main()
{
    Pizza *pizza;
    string order;
    cout << "Give the order\n";
    cin >> order;

    if (order == "cheesy")
        pizza = new Cheesy();

    else if (order == "Mexican")
        pizza = new Mexican();

    pizza->createPizza();
}