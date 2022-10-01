//////// Question number 1720.

#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> &encoded, int first)
{
    vector<int> ans;
    ans.push_back(first);
    for (int i = 0; i < encoded.size(); i++)
    {
        first = encoded[i]^first;
        ans.push_back(first);
    }
    return ans;
}

int main()
{
    cout<<"Hello";
    return 0;
}