/*-------- Medium -----------*/

/*- Build an Array With Stack Operations -*/

//////// Question number 1441.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

vector<string> buildArray(vector<int> &target, int n)
{
    vector<string> answer;
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (j == target.size())
            break;

        answer.push_back("Push");

        if (target[j] != i)
        {
            answer.push_back("Pop");
            continue;
        }

        j++;
    }
    return answer;
}

int main()
{
    return 0;
}