#include <iostream>
using namespace std;

/*
Startegy pattern is also called behavioral pattern, allowing client to select the
behaviour of the object at runtime.
*/

//! Interface class which signs contract to makesure everyone should makePayment()
class PaymentStrategy
{
public:
    virtual void makePayment() = 0;
};

class PaymentByCard : public PaymentStrategy
{
public:
    void makePayment() override
    {
        cout << "This is the payment by card\n";
    }
};

class PaymentByUPI : public PaymentStrategy
{
public:
    void makePayment() override
    {
        cout << "Payment done by UPI\n";
    }
};

class PaymentService
{
private:
    PaymentStrategy *paymentStrategy; // pointer to the interface
public:
    PaymentService(PaymentStrategy *p) : paymentStrategy(p)
    {
    }
    void processOrder()
    {
        paymentStrategy->makePayment();
    }
};

int main()
{
    PaymentService D(new PaymentByUPI());
    PaymentService C(new PaymentByCard());
    C.processOrder();
    D.processOrder();
}