/*
The Singleton Pattern is a creational Design pattern that restricts
the instantiation of a class to a single instance and provide a global
point of access in the application.

!This can be useful where only one object is needed to cooridnate actions
!across the system, such as configuration manager or a connection pool.
? Key:
1. Private Constructor
2. Private static Instance
3. Public static method
*/

#include <iostream>
using namespace std;

class Singleton
{
    Singleton() {}
    // Private copy constructor and copy assignment operator to prevent cloning
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    static Singleton &getInstance() // passing by the reference of the object
    {
        static Singleton object;
        return object;
    }

    void someOperation()
    {
        cout << "Some Operation\n";
    }
};

int main()
{
    Singleton &instance = Singleton::getInstance();
    instance.someOperation();
    Singleton &instance2 = Singleton::getInstance();
    instance2.someOperation();
    /*
    Both instance1 and instance2 refer to the same single instance of the Singleton class. There is no additional instance being created; instead, they are two references to the same instance.
    */

    //! In this case, you would indeed create two separate instances, which would be a violation of the Singleton pattern. To enforce the Singleton pattern, always use references when obtaining the instance

    // Singleton instance3 = Singleton::getInstance();
    // instance3.someOperation();
}
