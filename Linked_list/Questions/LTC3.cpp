/*--------Medium-----------*/

/*- Swapping Nodes in a Linked List -*/

//////// Question number 1721.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/******** Two pointer approach ********/

ListNode *swapNodes(ListNode *&head, int k)
{
    ListNode *second = head, *dummy = head;
    for (int i = 0; i < k - 1; i++)
    {
        dummy = dummy->next;
    }
    ListNode *first = dummy;

    while (dummy->next != NULL)
    {
        second = second->next;
        dummy = dummy->next;
    }

    swap(first->val, second->val);
}

/******** Using length of the linked list ********/

int length(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode *swapNodes(ListNode *&head, int k)
{
    int n = length(head);
    ListNode *first = head, *second = head;
    int first_idx = k - 1, last_idx = n - k;

    for (int i = 0; i < max(first_idx, last_idx); i++)
    {
        if (i < first_idx)
            first = first->next;

        if (i < last_idx)
            second = second->next;
    }
    int temp = first->val;
    first->val = second->val;
    second->val = temp;

    return head;
}

int main()
{
    return 0;
}