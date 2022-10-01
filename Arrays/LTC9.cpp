//////// Question number 1431.

#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxi = *max_element(candies.begin(), candies.end());

    vector<bool> vec1;

    for (int i = 0; i < candies.size(); i++)
    {
        vec1.push_back((candies[i] + extraCandies) >= maxi ? true : false);
    }
    return vec1;
}

int main()
{

    return 0;
}