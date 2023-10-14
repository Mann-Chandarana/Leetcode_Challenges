/*-------- Medium -----------*/

/*- Solving Questions With Brainpower -*/

//////// Question number 2140.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Using Recursion */

long long points(int index, int &total_points, vector<vector<int>> &questions)
{
    if (index >= questions.size())
        return total_points;

    int not_picked = 0 + points(index + 1, total_points, questions);
    int picked = questions[index][0] + points(index + questions[index][1] + 1, total_points, questions);

    return max(picked, not_picked);
}

/* Using Memorization */

long long points(int index, int &total_points, vector<vector<int>> &questions, vector<int> dp)
{
    if (index >= questions.size())
        return total_points;

    if (dp[index] != -1)
        return dp[index];

    int not_picked = 0 + points(index + 1, total_points, questions, dp);
    int picked = questions[index][0] + points(index + questions[index][1] + 1, total_points, questions, dp);

    return dp[index] = max(picked, not_picked);
}

long long mostPoints(vector<vector<int>> &questions)
{
    int total_points = 0;
    vector<int> dp(questions.size(), -1);
    return points(0, total_points, questions, dp);
}

/* Using Tabulation */

ll mostPoints(vector<vector<int>> &questions)
{
    ll N = questions.size();
    vector<ll> dp(N + 1, 0);

    for (ll index = N - 1; index >= 0; index--)
    {
        ll not_picked = 0 + dp[index + 1];
        ll picked = questions[index][0];

        if (index + questions[index][1] + 1 <= N)
            picked += dp[index + questions[index][1] + 1];

        dp[index] = max(not_picked, picked);
    }
    return dp[0];
}

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << mostPoints(questions) << endl;

    return 0;
}