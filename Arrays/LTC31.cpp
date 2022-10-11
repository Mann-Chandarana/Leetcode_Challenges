//////// Question number 1346.

#include <bits/stdc++.h>
using namespace std;

// bool checkIfExist(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int idx = lower_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();

//         if (idx < arr.size() && arr[idx] == 2 * arr[i] && i != idx)
//             return true;
//     }
//     return false;
// }

bool checkIfExist(vector<int> &arr)
{
    int count_zero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count_zero++;
        }
    }
    if (count_zero >= 2)
    {
        return true;
    }

    multiset<int> s(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0 and s.find(arr[i] * 2) != s.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {0, 0};
    cout << checkIfExist(arr);

    return 0;
}