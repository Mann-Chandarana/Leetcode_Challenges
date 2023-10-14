/* Geeks for geeks :- Reverse a double linked list */

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

/* Iterative solution */

Node *reverseDLL(Node *head)
{
    Node *temp = head, *prev = head;
    while (temp)
    {
        prev = temp;
        temp = temp->next;
        swap(prev->next, prev->prev);
    }
    return prev;
}

/******** Recursive solution *********/

/* Recursive Method 1 */

Node *reverseDLL(Node *&head)
{
    if (head->next == NULL)
    {
        swap(head->next, head->prev);
        return head;
    }

    swap(head->next, head->prev);
    return reverseDLL(head->prev);
}

/* Recursive Method 2 */

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        if (head != NULL)
            swap(head->next, head->prev);

        return head;
    }

    Node *newhead = reverseDLL(head->next);
    swap(head->next, head->prev);

    return newhead;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(4);
    Node *node1 = new Node(5);
    Node *node2 = new Node(6);

    head->next = node1;
    head->prev = NULL;

    node1->next = node2;
    node1->prev = head;

    node2->next = NULL;
    node2->prev = node1;

    printLL(head);
    head = reverseDLL(head);
    cout << "\n";
    cout << "Hi" << endl;
    printLL(head);

    return 0;
}