/* Geeks for Geeks :- Add a node in doubly linked list */

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

    void addNode(Node *head, int pos, int data)
    {
        int count = 0;
        Node *curr = head;
        Node *temp = new Node(data);
        if (head == NULL)
        {
            Node *temp = new Node(data);
            head = temp;
            return;
        }

        while (curr->next != NULL && count != pos)
        {
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL)
        {
            curr->next = temp;
            temp->prev = curr;
            return;
        }
        else
        {

            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            temp->prev = curr;
            return;
        }
        //  return head;
    }
};

int main()
{
    return 0;
}