/*--------  Hard --------*/

/*- Frog Jump -*/

//////// Question number 403.

#include <bits/stdc++.h>
using namespace std;

/**************** Recursion + Memorization ****************/

bool f(int i, int previous_jump, vector<int> &stones, unordered_map<int, int> &mp, vector<vector<int>> &dp)
{
    if (i == stones.size() - 1)
        return true;

    if (dp[i][previous_jump] != -1)
        return dp[i][previous_jump];

    bool answer = false;

    for (int jump = previous_jump - 1; jump <= previous_jump + 1; jump++)
    {
        if (jump > 0)
        {
            int next_stone = stones[i] + jump;

            if (mp.find(next_stone) != mp.end())
                answer = answer or (f(mp[next_stone], jump, stones, mp, dp));
        }
    }
    return dp[i][previous_jump] = answer;
}

bool canCross(vector<int> &stones)
{
    int n = stones.size();
    if (stones[1] != 1)
        return false;

    unordered_map<int, int> mp;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < stones.size(); i++)
        mp[stones[i]] = i;

    return f(0, 0, stones, mp, dp);
}

int main()
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};

    cout << canCross(stones) << endl;

    return 0;
}