/*--------  Medium --------*/

/*- Min Stack -*/

//////// Question number 155.

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    vector<pair<int, int>> arr;
    MinStack()
    {
    }

    void push(int val)
    {
        if (arr.empty())
            arr.push_back({val, val});
        else
            arr.push_back({val, min(arr.back().second, val)});
    }

    void pop()
    {
        arr.pop_back();
    }

    int top()
    {
        return arr.back().first;
    }

    int getMin()
    {
        return arr.back().second;
    }
};

int main()
{
    return 0;
}