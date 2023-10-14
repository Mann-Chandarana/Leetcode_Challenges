/* Geeks for Geeks :- Implement Queue using linked list */

#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    QueueNode *t = new QueueNode(x);
    if (front)
    {
        rear->next = t;
        rear = rear->next;
    }
    else
    {
        rear = t;
        front = t;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (!front)
        return -1;
    QueueNode *t = front;
    int r = front->data;
    front = front->next;
    delete t;
    return r;
}

int main()
{
    return 0;
}