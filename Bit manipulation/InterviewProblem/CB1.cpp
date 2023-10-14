/* Find two unique number for the given array */

#include <bits/stdc++.h>
using namespace std;

int binary_decimal(int *arr)
{
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += arr[i] * p;
        p <<= 1;
    }
    return ans;
}

void unique_number(int *n, int len)
{
    int cnt[64] = {0};

    for (int i = 0; i < len; i++)
    {
        int no = n[i];
        int pos = 0;
        while (no > 0)
        {
            if (no & 1)
                cnt[pos]++;

            pos++;
            no >>= 1;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
    }
    cout << binary_decimal(cnt) << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unique_number(arr, n);

    delete[] arr;

    return 0;
}