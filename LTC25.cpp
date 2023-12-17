/*-------- Medium --------*/

/*- Design a Food Rating System -*/

//////// Question number 2353.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef pair<int, string> pis;

class FoodRatings
{
public:
    unordered_map<string, int> food_rating;
    unordered_map<string, set<pis>> cuisine_foodRating;
    unordered_map<string, string> food_cuisine;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            food_rating[foods[i]] = ratings[i];
            cuisine_foodRating[cuisines[i]].insert({-ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating)
    {

        string cuisine = food_cuisine[food];

        cuisine_foodRating[cuisine].erase({-food_rating[food], food});
        food_rating[food] = newRating;
        cuisine_foodRating[cuisine].insert({-food_rating[food], food});
    }

    string highestRated(string cuisine)
    {
        return begin(cuisine_foodRating[cuisine])->second;
    }
};

int main()
{
    return 0;
} 