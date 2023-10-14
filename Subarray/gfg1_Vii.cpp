#include <bits/stdc++.h>
using namespace std;

/* Using sliding window */

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    int n = arr.size(), aux = 0;

    vector<int> result{0, 0}, vnone{-1};
    long long sum = 0;

    if (s != 0)
    {
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            while (sum > s)
            {
                sum -= arr[aux];
                aux++;
                if (aux >= i)
                    break;
            }

            if (sum == s)
            {
                result = {aux + 1, i + 1};
                return result;
            }
        }
    }
    return vnone;
}

/* Using hashmap*/

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    unordered_map<int, int> mp;

    int sum = 0, start = 0, end = -1;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum - s == 0)
        {
            ans.push_back(1);
            ans.push_back(i + 1);
            return ans;
        }

        if (mp.find(sum - s) != mp.end())
        {
            start = mp[sum - s] + 1;
            end = i + 1;
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        mp[sum] = i + 1;
    }
    if (end == -1)
    {
        ans.push_back(-1);
        return ans;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    vector<int> ans = subarraySum(arr, arr.size(), 12);

    for (auto element : ans)
        cout << element << " ";
    return 0;
}