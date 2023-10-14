/* Fractional Knapsack */

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, [&](Item &a, Item &b)
         { return ((a.value * 1.00) / a.weight) > (((b.value) * 1.00) / b.weight); });
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            double f = ((arr[i].value * 1.00) / arr[i].weight);
            ans += (f * W * 1.00);
            W = 0;
        }
    }
    return ans;
}


int main()
{
    return 0;
}