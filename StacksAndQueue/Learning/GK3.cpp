/* Geeks for Geeks :- Implement Stack using Linked List */

#include <bits/stdc++.h>
using namespace std;

struct stackNode
{
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};

stackNode *top = NULL;

void push(int x)
{
    stackNode *newNode = new stackNode(x);
    if (top == NULL)
        top = newNode;

    newNode->next = top;
    top = newNode;
}

// Function to remove an item from top of the stack.
int pop()
{
    if (top == NULL)
        return -1;

    int data = top->data;

    if (top->next != NULL)
        top = top->next;

    return data;
}

int main()
{
    return 0;
}