/* Geeks for Geeks :-  */

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

Node *rev(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node *addOne(Node *head)
{
    if (head == NULL)
        return head;

    int carry = 0;
    head = rev(head);
    Node *temp = head;

    int sum = temp->data + 1;
    int digit = sum % 10;
    carry = sum / 10;

    Node *newNode = new Node(digit);
    Node *ansHead = newNode;
    Node *ansTail = newNode;
    temp = temp->next;

    while (temp)
    {
        sum = carry + temp->data;
        digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        temp = temp->next;
    }
    while (carry)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }
    ansHead = rev(ansHead);
    return ansHead;
}

int main()
{
    return 0;
}