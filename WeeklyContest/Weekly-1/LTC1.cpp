// 2595 :- Number of Even and Odd Bits

#include <bits/stdc++.h>
using namespace std;

vector<int> intTobinary(int n)
{
    vector<int> binary;

    while (n > 0)
    {
        binary.push_back(n % 2);
        n /= 2;
    }
    return binary;
}

vector<int> evenOddBit(int n)
{
    vector<int> binary, ans(2, 0);

    binary = intTobinary(n);
    for (int i = 0; i < binary.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (binary[i] == 1)
                ans[0]++;
        }
        else
        {
            if (binary[i] == 1)
                ans[1]++;
        }
    }
    return ans;
}

int main()
{
    vector<int> ans = evenOddBit(2);
    for (auto element : ans)
    {
        cout << element << endl;
    }
    return 0;
}