/*--------  Hard --------*/

/*- Apply Operations to Maximize Score -*/

//////// Question number 2818.

#include <bits/stdc++.h>
using namespace std;

/*
1) Find prime score using prime sieve
2) Find next greater and previous greater element
3) And then find the score of the element
*/

const int MOD = 1000000007;

int maximumScore(vector<int> &nums, int k)
{
    int n = nums.size();

    //////////// Part-1)

    int upper = *max_element(nums.begin(), nums.end()) + 1;

    vector<bool> prime(upper, true);

    prime[0] = prime[1] = false;
    vector<int> primeScore(upper, 0);

    for (int i = 2; i < upper; i++)
    {
        if (prime[i])
        {
            for (int j = i; j < upper; j+=i)
            {
                primeScore[j]++;
                prime[j] = false;
            }
        }
    }

    //////////// Part -2)

    // Next greater element
    vector<int> nextGreater(n, n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and primeScore[nums[i]] >= primeScore[nums[s.top()]])
            s.pop();

        nextGreater[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Previous greater element
    vector<int> previousGreaterOrEqual(n, -1);
    s = stack<int>();

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and primeScore[nums[i]] > primeScore[nums[s.top()]])
            s.pop();

        previousGreaterOrEqual[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    /////////// Part-3)

    // Finding answer
    int res = 1;
    vector<pair<int, int>> tuples(n);

    for (int i = 0; i < n; i++)
    {
        tuples[i].first = nums[i];
        tuples[i].second = i;
    }

    sort(tuples.rbegin(), tuples.rend());

    for (const auto &[num, i] : tuples)
    {
        int operations = min(((i - previousGreaterOrEqual[i]) * (nextGreater[i] - i)), k);
        res = (int)((1L * res * pow(num, operations)) % MOD);
        k -= operations;
        if (k == 0)
            return res;
    }
    return res;
}

int main()
{
    return 0;
}