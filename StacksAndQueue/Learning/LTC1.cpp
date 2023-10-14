/* 225. Stack using queue */

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        queue<int> q1;
        while (q.size() > 1)
        {
            q1.push(q.front());
            q.pop();
        }
        int value = q.front();
        q.pop();
        while (!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }
        return value;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        if (q.empty())
            return true;
        return false;
    }
};

int main()
{
    return 0;
}