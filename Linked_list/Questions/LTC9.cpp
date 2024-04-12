/*--------Medium-----------*/

/*- Reorder List -*/

//////// Question number 143.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Approach -1) */

ListNode *reverse(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *curr = head, *prev = NULL, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    ListNode *reverseHead = slow->next;
    slow->next = NULL;

    ListNode *temp = head, *dummy, *dummy1;

    while (reverseHead != NULL and temp != NULL)
    {
        dummy = temp;
        temp = temp->next;
        dummy->next = reverseHead;

        dummy1 = reverseHead;
        reverseHead = reverseHead->next;
        dummy1->next = temp;
    }
    if (reverseHead != NULL)
        dummy->next = reverseHead, reverseHead = NULL;
}

/* Approach -2) */

ListNode *curr;

void solve(ListNode *head)
{
    if (head == NULL)
        return;

    solve(head->next);

    ListNode *temp = curr->next;
    if (temp == NULL)
        return;
    else if (head == curr)
    {
        head->next = NULL;
        return;
    }

    curr->next = head;
    head->next = temp == head ? NULL : temp;

    curr = temp;
}

void reorderList(ListNode *head)
{
    curr = head;
    solve(head);
}

int main()
{
    return 0;
}