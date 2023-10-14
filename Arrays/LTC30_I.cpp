//////// Question number 605.

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int i = 0; i < flowerbed.size() - 2; i++)
    {
        if (flowerbed[i] + flowerbed[i + 1] + flowerbed[i + 2] == 0)
        {
            n--;
            i++;
        }
    }
    if (n > 0)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> flowerbed = {1, 0, 1, 0, 0};
    cout << canPlaceFlowers(flowerbed, 1) << endl;

    for (int i = 0; i < flowerbed.size(); i++)
    {
        cout << flowerbed[i] << " ";
    }

    return 0;
}