/* 796. Rotate String */

#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;

    if ((s + s).find(goal) != string::npos)
        return true;
    return false;
}

int main()
{
    return 0;
}