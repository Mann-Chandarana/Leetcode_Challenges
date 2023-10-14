/*-------- Hard -----------*/

/*- Rotate List -*/

//////// Question number 61.

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

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy = head;
    int len = 1;

    while (dummy->next != NULL)
    {
        len++;
        dummy = dummy->next;
    }
    dummy->next = head;
    k = k % len;
    int end = len - k;

    dummy = head;
    while (end > 1)
    {
        dummy = dummy->next;
        end--;
    }
    head = dummy->next;
    dummy->next = NULL;

    return head;
}

int main()
{
    return 0;
}