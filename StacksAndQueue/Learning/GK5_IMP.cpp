/* Geeks for Geeks :- Get minimum element from stack */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {
        if (s.empty())
            return -1;

        return minEle;
    }

    /*returns poped element from stack*/
    int pop()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();

        if (curr > minEle)
        {
            return curr;
        }
        else
        {
            int prevMin = minEle;
            int val = 2 * minEle - curr;
            minEle = val;
            return prevMin;
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            minEle = x;
        }
        else
        {
            if (x >= minEle)
                s.push(x);
            else
            {
                s.push(2 * x - minEle);
                minEle = x;
            }
        }
    }
};

int main()
{
    return 0;
}