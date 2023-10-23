#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Observer Pattern :
As the name suggest object is observing to state change in the subject in
which it is subscribed to.

Take an example of the News Agency.

Observer can susbcribe to the subject News Agency for to get //!updated
when there is an news article published.
+-----------------------------------------+
|              News Agency (Subject)      |
|-----------------------------------------|
| + attach(observer: Subscriber)         |
| + detach(observer: Subscriber)         |
| + publishArticle(article: string)      |
| + notifySubscribers()                  |
|-----------------------------------------|
| - observers: List of Subscribers       |
+-----------------------------------------+
              /            \
             /              \
            /                \
           /                  \
          /                    \
         /                      \
+-----------------------------------+
| Subscriber  (Observer)            |
|-----------------------------------|
| + update(article: string)         |
| - name: string                    |
+-----------------------------------+
*/

//? Observer Interface
class Observer
{
public:
    virtual void update(const string &article) = 0;
};

//? Concrete Observer : Subscriber
class Subscriber : public Observer
{
private:
    string name;

public:
    Subscriber(const string &name) : name(name) {}

    void update(const string &article) override
    {
        cout << "Subscriber:" << name << " recived an article: "
             << article;
    }
};

//? Subject : News Agency

class NewsAgency
{
private:
    vector<Observer *> observers;
    vector<string> articles;

public:
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    void detach(Observer *observer)
    {
        // remove function put the element to be removed at the end, erase; erase it.
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void publishArticles(const string &article)
    {
        articles.push_back(article);
        notifySubscriber(article);
    }

private:
    void notifySubscriber(const string &article)
    {
        for (Observer *observer : observers)
            observer->update(article); // Every observer needs to be updated about article
    }
};

int main()
{
    NewsAgency newsAgency; // Subject
    // Subscriber
    Subscriber subscribe1("Alice");
    Subscriber subscribe2("Bob");
    // Subscribe
    newsAgency.attach(&subscribe1);
    newsAgency.attach(&subscribe2);

    newsAgency.publishArticles("Breaking News: COVID-19 Vaccine Update\n");
    newsAgency.publishArticles("Economic Trends in 2023\n");

    newsAgency.detach(&subscribe2);
    newsAgency.publishArticles("2023 ending soon");
}