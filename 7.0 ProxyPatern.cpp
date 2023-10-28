/*
Its a Structual Design Pattern.
It is used to cover a wrapper to cover the main's Object complexity from the client.
It provide a placeholder/cover up for another object to control access to it.
E.g.
? Lazy Initialization -
If there is big object like a video then instead of creating the object beforehand we can create a proxy can used to control the creation of the object an only instantiate when there is need.
There are various types of proxies in the Proxy Pattern:

Virtual Proxy: This proxy defers the creation and initialization of the real subject until it's needed. For example, in a multimedia application, a virtual proxy may load large media files only when a user requests to view them.

Remote Proxy: A remote proxy represents an object in a different address space, such as when working with distributed systems or remote services.

Cache Proxy: This proxy caches the results of expensive operations and serves cached results when the same operation is requested again.

Protection Proxy: A protection proxy controls access to the real subject by adding authentication and authorization checks. It enforces security rules before allowing access to the real subject.
*/
//? Example of a proxy for internet access. In some organizations, internet access needs to be controlled and monitored. A proxy can be used to enforce access policies and filter content.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Subject Interface
class InternetAccess
{
public:
    virtual void connect(string url) = 0;
};

// Real Subejct
class RealInternetAccess : public InternetAccess
{
public:
    void connect(string url) override
    {
        cout << "Connecting to " << url << "\n";
    }
};

// Proxy
class InternetAccessProxy : public InternetAccess
{
private:
    RealInternetAccess *realAccess;
    string username;
    vector<string> bannedSites;

public:
    InternetAccessProxy(string user) : username(user), realAccess(nullptr)
    {
        bannedSites.push_back("xxxyy.com");
        bannedSites.push_back("restricted-site.com");
    }

    void connect(string url) override
    {
        if (isAllowed(url))
        {
            if (!realAccess) // check if there is real access or not
                realAccess = new RealInternetAccess();
            realAccess->connect(url);
        }
        else
        {
            cout << "Access to " << url << " is not allowed for user " << username << endl;
        }
    }

private:
    bool isAllowed(string &url)
    {
        if (username == "admin")
            return true;
        else
        {
            vector<string>::iterator it;
            it = find(bannedSites.begin(), bannedSites.end(), url);
            if (it != bannedSites.end())
                return false;
            else
                return true;
        }
    }
};

int main()
{
    InternetAccess *user1Access = new InternetAccessProxy("User1");
    InternetAccess *adminAccess = new InternetAccessProxy("Admin");

    user1Access->connect("work-related-site.com");
    user1Access->connect("entertainment-site.com");
    adminAccess->connect("restricted-site.com");
    user1Access->connect("restricted-site.com");

    delete user1Access;
    delete adminAccess;

    return 0;
}