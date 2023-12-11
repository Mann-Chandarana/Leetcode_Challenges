/*-------- Medium --------*/

/*- Double Modular Exponentiation -*/

//////// Question number 100155.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int power(long long num1, long long num2, long long mod)
{
    int answer = 1;

    for (int i = 0; i < num2; i++)
        answer = (answer * 1LL * num1) % mod;

    return answer;
}

vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
{
    long long n = variables.size();
    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        long long a = variables[i][0], b = variables[i][1], c = variables[i][2], d = variables[i][3];

        int sol1 = power(a, b, 10);
        int sol2 = power(sol1, c, d);

        if (sol2 == target)
            answer.push_back(i);
    }
    return answer;
}

int main()
{
    return 0;
}