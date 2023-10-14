/*--------  Medium --------*/

/*- Fruit Into Baskets -*/

//////// Question number 904.

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;

    int i = 0, j = 0, length = 0;

    while (j < fruits.size())
    {
        mp[fruits[j]]++;
        if (mp.size() <= 2)
            length = max(length, j - i + 1);

        else
        {
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0)
                mp.erase(fruits[i]);

            i++;
        }
        j++;
    }
    return length;
}

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << totalFruit(fruits) << endl;
    return 0;
}