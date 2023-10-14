// Leaders in an array :- geeks for geekss


#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n)
{
    vector<int> answer;
    int maxi = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            answer.push_back(a[i]);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    return 0;
}