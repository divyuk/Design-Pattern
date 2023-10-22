#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Social Media Platforms

Another use case for the Observer design pattern can be found in social media platforms. Users subscribe (or follow) other users. When the user they follow posts something new, all followers are notified. Here, the followed user acts as the 'Subject', and the followers are the 'Observers'.

+------------------------+
|    Followed User       |  (Subject)
|------------------------|
| + attach(follower)     |
| + detach(follower)     |
| + postUpdate(update)   |
| - followers: List of   |
|   Followers            |
+------------------------+
           |           \
           |            \
           |             \
           |              \
           |               \
           |                \
+------------------------+ +------------------------+
|      Follower          | |      Follower          |  (Observers)
|------------------------| |------------------------|
| + update(update)       | | + update(update)       |
| - name: string         | | - name: string         |
+------------------------+ +------------------------+


*/

// Observer interface
class Follower
{
public:
    virtual void update(const string &update) = 0;
};

// Concrete Observer: User
class User : public Follower
{
public:
    User(const string &name) : name(name) {}

    void update(const string &update) override
    {
        cout << name << " received a new update: " << update << endl;
    }

private:
    string name;
};

// Subject: Followed User
class FollowedUser
{
public:
    void attach(Follower *follower)
    {
        followers.push_back(follower);
    }

    void detach(Follower *follower)
    {
        followers.erase(remove(followers.begin(), followers.end(), follower), followers.end());
    }

    void postUpdate(const string &update)
    {
        updates.push_back(update);
        notifyFollowers(update);
    }

private:
    void notifyFollowers(const string &update)
    {
        for (Follower *follower : followers)
        {
            follower->update(update);
        }
    }

    vector<Follower *> followers;
    vector<string> updates;
};

int main()
{
    FollowedUser followedUser;
    User user1("Alice");
    User user2("Bob");

    followedUser.attach(&user1);
    followedUser.attach(&user2);

    followedUser.postUpdate("Just had a great meal!");
    followedUser.postUpdate("Enjoying the sunset view!");

    followedUser.detach(&user2);

    followedUser.postUpdate("New adventure begins!");

    return 0;
}
