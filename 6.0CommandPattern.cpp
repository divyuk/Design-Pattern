#include <iostream>
using namespace std;

/*
Command pattern is a behavioral design pattern, where request is send as a stand alone object which contains all the information about the request. This transformation decouples the sender of the req from the reciever, allowing you to parametrize clients with different requests,queues or log req and supports undo operations.
It has -

Reciever  ------ Command ------ Invoker

*/

//! Reciever
class AC
{
    bool isOn;
    int temp;

public:
    void turnOnAC()
    {
        isOn = true;
        cout << "AC is ON\n";
    }
    void turnOffAC()
    {
        isOn = false;
        cout << "AC is OFF\n";
    }
    void setTemperature(int t)
    {
        temp = t;
        cout << "Temperature is set to: " << temp << "\n";
    }
};

//! Command Interface
class ICommand
{
public:
    virtual void execute() = 0;
};

// Concrete Class for various Commands as specefied by ICommand
class ACTurnOn : public ICommand
{
private:
    AC &ac; // Reciever obj
public:
    ACTurnOn(AC &a) : ac(a) {} // Set the object passed into the refernce

    void execute() override
    {
        ac.turnOnAC();
    }
};

class ACTurnOff : public ICommand
{
private:
    AC &ac;

public:
    ACTurnOff(AC &a) : ac(a) {}

    void execute() override
    {
        ac.turnOffAC();
    }
};

//! Invoker
class RemoteControl
{
private:
    ICommand &command;

public:
    RemoteControl(ICommand &c) : command(c) {}
    void pressButton()
    {
        command.execute();
    }
};

// Client (User)
int main()
{
    AC ac;                       // Object ac is created on stack
    ACTurnOn cmdOn(ac);          // Instance of Turn on class and setting it with reciever
    RemoteControl remote(cmdOn); // Setting the Remote with the command required to run the reciever.//! Because of Polymorphism the derived class can set the base class
    remote.pressButton();        // User presses the button
}