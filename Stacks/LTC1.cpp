#include <bits/stdc++.h>
using namespace std;

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
    MyQueue *queue = new MyQueue();
    queue->push(5);
    queue->push(8);
    queue->push(7);
    queue->push(6);

    while (!queue->empty())
    {
        cout << queue->peek() << " ";
        queue->pop();
    }

    return 0;
}