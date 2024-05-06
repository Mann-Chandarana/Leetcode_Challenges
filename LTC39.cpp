/*-------- Medium --------*/

/*- Remove Nodes From Linked List -*/

//////// Question number 2487.

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

/** Approach -1) **/

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

ListNode *removeNodes(ListNode *head)
{
    ListNode *reverseHead = reverseList(head);
    int maxi = INT_MIN;

    ListNode *temp = reverseHead;
    ListNode *prev = temp;

    while (temp != NULL)
    {
        if (temp->val < maxi)
        {
            prev->next = temp->next;
            ListNode *dummy = temp;
        }
        else
            prev = temp;

        if (temp)
            maxi = max(maxi, temp->val);
        temp = temp->next;
    }
    return reverseList(reverseHead);
}

/** Approach - 2) **/

ListNode *removeNodes(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    ListNode *nextNode = removeNodes(head->next);

    if (head->val < nextNode->val)
    {
        delete head;
        return nextNode;
    }
    head->next = nextNode;
    return head;
}

int main()
{
    return 0;
}