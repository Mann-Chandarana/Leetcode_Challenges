/*-------- Hard -----------*/

/*- Candy -*/

//////// Question number 135.

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

/**** Approach -1 ****/

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vi candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            candies[i] = (candies[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    int sum = 0;

    for (auto c : candies)
        sum += c;

    return sum;
}

/**** Approach -2 ****/

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int candy = n;

    int i = 1;
    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            i++;
            continue;
        }

        // For increasing slope
        int peak = 0;
        while (ratings[i] > ratings[i - 1])
        {
            peak++;
            candy += peak;
            i++;
            if (i == n)
                return candy;
        }

        // For decreasing slope
        int valley = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            valley++;
            candy += valley;
            i++;
        }

        // Note that we added candies coming from left to Peak and comgin from right to Peak
        // But, we need to consider only max from both of them for the Peak.
        // So, remove the min candy from Peak.
        candy -= min(peak, valley);
    }

    return candy;
}

int main()
{
    return 0;
}