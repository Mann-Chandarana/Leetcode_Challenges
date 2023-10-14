#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
            next = NULL;
    }
};

Node *insertAtBegining(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if (head == NULL)
        return temp;
    head = temp;
    return head;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
    Node *newNode = new Node(x);
    if (head == NULL)
        return newNode;
    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

int main()
{
    return 0;
}