/* Geeks for Geeks :- Length of the Cycle */

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


int countNodesinLoop(struct Node *head)
{
    if (head == NULL and head->next == NULL)
        return 0;

    Node *fast = head, *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        int count = 0;

        if (fast == slow)
        {
            slow = slow->next;
            while (slow != fast)
            {
                count++;
                slow = slow->next;
            }
            return count;
        }
    }
    return -1;
}

int main()
{
    return 0;
}