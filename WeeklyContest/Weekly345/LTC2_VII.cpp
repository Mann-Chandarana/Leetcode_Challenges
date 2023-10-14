/*--------  Medium --------*/

/*- Neighboring Bitwise XOR -*/

//////// Question number 2683.

#include <bits/stdc++.h>
using namespace std;

bool doesValidArrayExist(vector<int> &derived)
{
    int xr = 0;

    for (auto element : derived)
        xr = xr ^ element;

    return xr == 0;
}

int main()
{
    vector<int> derived = {1, 1};
    cout << doesValidArrayExist(derived) << endl;
    return 0;
}