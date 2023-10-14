/*--------Medium-----------*/

/*- Add Two Numbers -*/

//////// Question number 2.

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

ListNode *reverse(ListNode *head)
{

    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(struct ListNode *&head, struct ListNode *&tail, int val)
{

    ListNode *temp = new ListNode(val);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l1;

    if (l2 == NULL)
        return l2;

    int sum = 0, carry = 0;
    ListNode *ansHead = NULL, *ansTail = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (l1 != NULL)
            val1 = l1->val;

        int val2 = 0;
        if (l2 != NULL)
            val2 = l2->val;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }
    return ansHead;
}

int main()
{
    return 0;
}