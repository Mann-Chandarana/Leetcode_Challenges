/* 1502. Can Make Arithmetic Progression From Sequence */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/* Approach -1)  */

bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();
    sort(all(arr));

    int difference = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0 and i + 1 < n)
            difference = arr[i + 1] - arr[i];

        else if (i + 1 < n)
        {
            if (arr[i + 1] - arr[i] != difference)
                return false;
        }
    }
    return true;
}

/* Approach -2) */

bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();

    unordered_set<int> st(all(arr));

    int min_ele = *min_element(all(arr));
    int max_ele = *max_element(all(arr));

    if ((max_ele - min_ele) % (n - 1))
        return false;

    int d = (max_ele - min_ele) / (n - 1);

    int i = 0;

    while (i < n)
    {
        if (st.find((min_ele + i * d)) == st.end())
            return false;

        i++;
    }
    return true;
}

/* Approach -3) */

bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();

    unordered_set<int> st(all(arr));

    int min_ele = *min_element(all(arr));
    int max_ele = *max_element(all(arr));

    if ((max_ele - min_ele) % (n - 1))
        return false;

    int d = (max_ele - min_ele) / (n - 1);

    int i = 0;
    while (i < n)
    {
        if (arr[i] == (min_ele + i * d))
            i++;

        else if ((arr[i] - min_ele) % d != 0)
            return false;

        else
        {
            int pos = (arr[i] - min_ele) / d;

            if (arr[i] == arr[pos])
                return false;

            swap(arr[i], arr[pos]);
        }
    }
    return true;
}

int main()
{
    return 0;
}