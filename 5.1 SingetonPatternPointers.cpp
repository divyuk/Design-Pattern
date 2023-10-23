#include <iostream>

using namespace std;

class Singleton
{
    static Singleton *instance;
    int data;

    // Private constructor so that no objects can be created.
    Singleton()
    {
        data = 0;
    }

public:
    static Singleton *getInstance()
    {
        if (!instance)
            instance = new Singleton();
        else
            cout << "getInstance(): previous instance\n";

        return instance;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main()
{
    Singleton *s = s->getInstance();
    cout << s->getData() << endl;
    s->setData(100);
    cout << s->getData() << endl;

    cout << "Pointer s2\n";
    Singleton *s2 = s2->getInstance();
    cout << s2->getData() << endl;
    s2->setData(1);
    cout << s2->getData() << endl;

    cout << "Pointer s\n";
    cout << s->getData() << endl;

    cout << "Pointer s3\n";
    Singleton *s3 = s2;
    //? This pointer is also pointing where s2 is pointing
    s3->getInstance();
    cout << s3->getData() << endl;
    return 0;
}
