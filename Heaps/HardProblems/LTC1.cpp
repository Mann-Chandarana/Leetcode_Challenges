/*--------Medium-----------*/

/*- Design Twitter -*/

//////// Question number 355.

#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    int time = 0;
    unordered_map<int, set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> answer;
        priority_queue<pair<int, int>> pq;
        for (auto element : tweets[userId])
            pq.push(element);

        for (auto follow : followers[userId])
        {
            for (auto element : tweets[follow])
                pq.push(element);
        }
        int i = 10;
        while (!pq.empty() and i--)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }
};

int main()
{

    return 0;
}