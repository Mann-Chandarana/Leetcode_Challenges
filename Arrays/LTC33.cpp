//////// Question number 941.

#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int flag = 0;
    if (arr.size() == 1 || (arr.size() == 2 && arr[0] >= arr[1]))
    {
        return false;
    }
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
        {
            flag = 1;
            continue;
        }
        if (flag == 0 && (arr[i - 1] >= arr[i] || arr[i + 1] <= arr[i]))
        {
            return false;
        }
        else if (flag == 1 && (arr[i - 1] <= arr[i] || arr[i + 1] >= arr[i]))
        {
            return false;
        }
    }
    if (flag == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    return 0;
}