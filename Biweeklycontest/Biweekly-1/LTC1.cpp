#include <bits/stdc++.h>
using namespace std;

int splitNum(int num)
{
    int sum = INT_MAX;
    string ans = to_string(num);

    sort(ans.begin(), ans.end());

    string ans1 = "", ans2 = "";

    for (int i = 0; i < ans.length(); i++)
    {
        if (i % 2 == 0){
            ans1.push_back(ans[i]);
        }
        else{
            ans2.push_back(ans[i]);
        }
    }
    return stoi(ans1) + stoi(ans2);
}

int main()
{
    cout << splitNum(687) << endl;
    return 0;
}