/*
Bridge Pattern -

- It solves the problem by switching from inheritance to aggregation.
- We extract one of the dimensions into separate class heierarchy so that the original class will reference an object of the new hierarchy, instead of having all its state and behaviour in one class.
*/

#include <iostream>
using namespace std;

class Colour
{
public:
    virtual void applyColour() = 0;
};

class RedColour : public Colour
{
public:
    void applyColour() override
    {
        cout << "Appling Red Colour\n";
    }
};
class BlueColour : public Colour
{
public:
    void applyColour() override
    {
        cout << "Appling Blue Colour\n";
    }
};

class Shape
{
protected:
    Colour *colour;

public:
    Shape(Colour *c) : colour(c){};
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    Circle(Colour *c) : Shape(c){};
    void draw() override
    {
        cout << "Drawing Circle\n";
        colour->applyColour();
    }
};
class Triangle : public Shape
{
public:
    Triangle(Colour *c) : Shape(c){};
    void draw() override
    {
        cout << "Drawing Triangle\n";
        colour->applyColour();
    }
};

int main()
{
    Colour *red = new RedColour();
    Shape *circle = new Circle(red);
    circle->draw();
}