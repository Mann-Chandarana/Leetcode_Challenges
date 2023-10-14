//////// Question number 2011.

#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int X = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "X++" || operations[i] == "++X")
        {
            X += 1;
        }
        if (operations[i] == "X--" || operations[i] == "--X")
        {
            X -= 1;
        }
    }
    return X;
}

int main()
{

    return 0;
}