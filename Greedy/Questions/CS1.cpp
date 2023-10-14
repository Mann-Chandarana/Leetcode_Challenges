/* Code Studio */

/* Fractional knapsack */

#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    vector<vector<double>> fractional;

    for (auto element : items)
        fractional.push_back({double(element.second) / double(element.first), double(element.first), double(element.second)});

    sort(fractional.begin(), fractional.end(), greater<vector<double>>());

    double cost = 0;
    for (auto element : fractional)
    {
        if (w == 0)
            break;

        if (element[1] <= w)
            cost += element[2], w -= element[1];

        else
            cost += (double(w * element[2]) / double(element[1])), w = 0;
    }
    return cost;
}

int main()
{
    vector<pair<int, int>> items = {{50, 40}, {40, 50}, {90, 25}, {120, 100}, {10, 30}, {200, 45}};
    cout << maximumValue(items, 6, 200) << endl;
    return 0;
}