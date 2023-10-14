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

/* first approach */

Node *segregate(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;

    Node *firsthead = new Node(-1);
    Node *firsttail = firsthead;

    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;

    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            zerotail->next = curr;
            zerotail = curr;
        }
        else if (value == 1)
        {
            firsttail->next = curr;
            firsttail = curr;
        }
        else
        {
            twotail->next = curr;
            twotail = curr;
        }
        curr = curr->next;
    }
    if (firsthead->next != NULL)
        zerotail->next = firsthead->next;
    else
        zerotail->next = twohead->next;

    firsttail->next = twohead->next;
    twotail->next = NULL;

    head = zerohead->next;

    delete zerohead;
    delete firsthead;
    delete twohead;

    return head;
}

/* Second approach */
Node *segregate(Node *head)
{

    // Add code here
    int zerocnt = 0;
    int onecnt = 0;
    int twocnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocnt++;
        }
        else if (temp->data == 1)
        {
            onecnt++;
        }
        else if (temp->data == 2)
        {
            twocnt++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zerocnt != 0)
        {
            temp->data = 0;
            zerocnt--;
        }
        else if (onecnt != 0)
        {
            temp->data = 1;
            onecnt--;
        }
        else if (twocnt != 0)
        {
            temp->data = 2;
            twocnt--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}