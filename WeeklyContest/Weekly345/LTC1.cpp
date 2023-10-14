/* 6430 */

/* Find the Losers of the Circular Game */

#include <bits/stdc++.h>
using namespace std;

vector<int> circularGameLosers(int n, int k)
{
    int start = 0, multplier = 1;
    vector<bool> visited(n, false);

    while (!visited[start])
    {
        visited[start] = true;
        start = (start + (k * multplier++)) % n;
    }
    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            answer.push_back(i + 1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> answer = circularGameLosers(5, 3);

    for (auto element : answer)
        cout << element << " ";
    return 0;
}