// Subset Sums :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int N, int sum, int index, vector<int> &answer)
{
    if (index == N)
    {
        answer.push_back(sum);
        return;
    }

    solve(arr, N, sum + arr[index], index + 1, answer);

    solve(arr, N, sum, index + 1, answer);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> answer;

    solve(arr, N, 0, 0, answer);

    return answer;
}

int main()
{
    vector<int> arr = {2, 3};
    arr = subsetSums(arr, arr.size());
    for (auto element : arr)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}