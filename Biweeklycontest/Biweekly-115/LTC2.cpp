#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef vector<int> vi;
typedef vector<string> vs;

vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
{
    int n = words.size();

    vi count(n, 1), parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (groups[i] != groups[j])
            {
                if (count[j] + 1 > count[i])
                    count[i] = count[j] + 1, parent[i] = j;
            }
        }
    }
    int maxi = INT_MIN, index;

    for (int i = 0; i < n; i++)
    {
        if (count[i] > maxi)
            maxi = count[i], index = i;
    }

    vs answer;

    while (parent[index] != index)
    {
        answer.push_back(words[index]);
        index = parent[index];
    }
    return answer;
}

int main()
{
    return 0;
}