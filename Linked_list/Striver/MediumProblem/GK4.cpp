/* Geeks for geeks :-  Intersection of Two Linked Lists */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *headB, Node *headA)
{
    // code here
    // return the head of intersection list
    Node *ptr1 = headA;
    Node *ptr2 = headB;
    Node *start = new Node(-1);
    Node *startHead = start;
    unordered_map<int, int> mp;

    while (ptr1 != NULL)
    {
        mp[ptr1->data]++;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if (mp[ptr2->data] > 0)
        {
            start->next = ptr2;
            start = start->next;
        }
        ptr2 = ptr2->next;
    }
    start->next = NULL;
    return startHead->next;
}

int main()
{
    return 0;
}