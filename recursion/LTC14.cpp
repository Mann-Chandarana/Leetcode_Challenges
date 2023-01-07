/*-------- Medium -----------*/

/*- Combination Sum III -*/

//////// Question number 216.

#include <bits/stdc++.h>
using namespace std;

void solve(int &k, int target, vector<bool> &visited, vector<int> answer, vector<vector<int>> &ans,int index)
{

    if (target == 0)
    {
        if (answer.size() == k)
        {
            ans.push_back(answer);
        }
        return;
    }

    for (int i = index; i < 10; i++)
    {
        if (!visited[i] and target - i >= 0)
        {
            visited[i] = true;
            answer.push_back(i);
            solve(k, target - i, visited, answer, ans,i+1);
            answer.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> answer;
    vector<int> ans;
    vector<bool> visited(10, false);

    solve(k, n, visited, ans, answer,1);
    return answer;
}

int main()
{
    vector<vector<int>> answer = combinationSum3(4, 1);
    for (auto element : answer)
    {
        for (auto i : element)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}