/* 83. Remove Duplicates from Sorted List */

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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL and head->next == NULL)
        return head;

    ListNode *start = head, *temp = head->next;

    while (temp != NULL)
    {
        while (temp != NULL and temp->val == start->val)
        {
            temp = temp->next;
        }
        start->next = temp;
        start = temp;
        if (temp != NULL)
            temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}