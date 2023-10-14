/* 860. Lemonade Change */

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;

    for (auto element : bills)
    {
        if (element == 5)
            five++;
        else if (element == 10)
        {
            if (five >= 1)
                ten += 1, five -= 1;
            else
                return false;
        }
        else
        {
            if (ten >= 1 and five >= 1)
                ten -= 1, five -= 1;
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    cout << lemonadeChange(bills) << endl;
    return 0;
}