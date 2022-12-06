/* Middle of the linked list */
//////// Question number 876.

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

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head, *ptr = head;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }
    return slow;
}

int main()
{

    return 0;
}