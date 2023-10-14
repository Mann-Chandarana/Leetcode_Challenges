/** Fruits into the basket **/

#include <bits/stdc++.h>
using namespace std;

int totalFruits(int N, vector<int> &fruits)
{
    unordered_map<int, int> mp;

    int i = 0, j = 0, n = fruits.size(), max_len = 0;

    while (j < n)
    {
        mp[fruits[j]]++;
        
        if (mp.size() <= 2)
        {
            max_len = max(max_len, j - i + 1);
        }
        else
        {
            if (mp.size() > j - i + 1)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
        }
        j++;
    }
    return max_len;
}

int main()
{
    vector<int> fruits = {2, 1, 2};
    cout << totalFruits(3, fruits) << endl;
    return 0;
}