//////// Question number 1773.

#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int col_index, count = 0;
    if (ruleKey == "type")
    {
        col_index = 0;
    }
    else if (ruleKey == "color")
    {
        col_index = 1;
    }
    else
    {
        col_index = 2;
    }

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i][col_index] == ruleValue)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<string>> items = {{"phone", "blue", "pixel"},
                                    {"computer", "silver", "phone"},
                                    {"phone", "gold", "iphone"}};
    cout << countMatches(items, "type", "phone") << endl;

    return 0;
}