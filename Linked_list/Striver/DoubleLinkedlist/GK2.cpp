/* Geeks for Geeks :- Delete a node in doubly linked list */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev;
    }

    ~Node()
    {
        if (next != NULL)
            next = NULL;
    }
};

Node *deleteNode(Node *head, int x)
{
    Node *temp = head;
    if (x == 1)
    {
        head->next->prev = NULL;
        temp = temp->next;
        return temp;
    }
    while (--x)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    return head;
}

int main()
{
    return 0;
}