#include <bits/stdc++.h>
using namespace std;

vector<long long> countOperations(int n, vector<int> &a, long long x, int q, vector<vector<int>> &queries)
{
    vector<long long> answer(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++)
    {
        int index = queries[i][0];
        int value = queries[i][1];

        a[index] = value;

        long long sum = 0;
        for (auto element : a)
            sum += element;

        if (sum % x == 0)
            answer[i] = sum / x;
        else
            answer[i] = (sum / x) + 1;
    }
    return answer;
}

int main()
{
    vector<int> a = {101, 12, 57, 72, 3};
    vector<vector<int>> queries = {{1, 19}, {2, 170}, {4, 2}};

    vector<long long> answer = countOperations(5, a, 7, 3, queries);

    for (auto elemnet : answer)
    {
        cout << elemnet << " ";
    }

    return 0;
}