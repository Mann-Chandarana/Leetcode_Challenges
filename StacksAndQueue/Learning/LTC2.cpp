/*- Implement Queue using Stacks -*/

//////// Question number 232.

#include <bits/stdc++.h>
using namespace std;

/* Using Recursion */

class MyQueue
{
    stack<int> s;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        pushHelper(x);
    }

    void pushHelper(int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int element = s.top();
        s.pop();

        pushHelper(x);
        s.push(element);
    }

    int pop()
    {
        if (!s.empty())
        {
            int x = s.top();
            s.pop();
            return x;
        }
        else
        {
            return 0;
        }
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
    }
};

/* Using stacks */

class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if (!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            return x;
        }
        else
        {
            return 0;
        }
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    return 0;
}