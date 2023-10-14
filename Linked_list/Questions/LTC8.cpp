/*--------Medium-----------*/

/*- Reverse Linked List II -*/

//////// Question number 92.

/*
When there is the possibility of change in head of the list at that time make
dummy = -1  as your new head
*/

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

////////////////// Approach - 1

void reverse_list(ListNode *&head, ListNode *previous, int right, int i)
{
    ListNode *prev = NULL, *curr = head, *after;

    while (i != right + 1)
    {
        after = curr->next;

        curr->next = prev;
        prev = curr;
        curr = after;
        i++;
    }

    if (previous != NULL)
        previous->next = prev;
    if (curr != NULL)
        head->next = curr;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *temp = head, *prev = dummy;

    int i = 1;

    while (temp != NULL)
    {
        if (i == left)
        {
            reverse_list(temp, prev, right, i);
            break;
        }

        prev = temp;
        temp = temp->next;
        i++;
    }

    return dummy->next;
}

////////////////// Approach - 2

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    for (int i = 1; i < left; i++)
        prev = prev->next;

    ListNode *curr = prev->next;

    for (int i = 1; i <= right - left; i++)
    {
        ListNode *temp = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = temp;
    }
    return dummy->next;
}

int main()
{
    return 0;
}