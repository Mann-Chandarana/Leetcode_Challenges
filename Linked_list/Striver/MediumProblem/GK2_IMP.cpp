/* Geeks for Geeks :- Segregate even and odd nodes in a Link List */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *divide(int N, Node *head)
{
    // code here
    Node *even = new Node(-1);
    Node *even_point = even;
    Node *odd = new Node(-1);
    Node *odd_point = odd;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            Node *e = new Node(curr->data);
            even_point->next = e;
            even_point = even_point->next;
        }
        else
        {
            Node *o = new Node(curr->data);
            odd_point->next = o;
            odd_point = odd_point->next;
        }
        curr = curr->next;
    }
    even_point->next = odd->next;
    return even->next;
}

int main()
{
    return 0;
}