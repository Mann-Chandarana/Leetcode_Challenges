/*--------Medium-----------*/

/*- Maximum Twin Sum of a Linked List -*/

//////// Question number 2130.

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

/** Without using stack **/

int pariSum(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *nextNode, *prev = NULL;

    while (slow)
    {
        nextNode = slow->next;
        slow->next = prev;

        prev = slow;
        slow = nextNode;
    }
    int max_sum = INT_MIN;

    while (prev)
    {
        max_sum = max(max_sum, head->val + prev->val);
        prev = prev->next;
        head = head->next;
    }
    return max_sum;
}

/** With using stack **/

int pairSum(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    stack<int> st;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    while (slow != NULL)
    {
        st.push(slow->val);
        slow = slow->next;
    }

    ListNode *temp = head;
    int max_sum = INT_MIN;
    while (!st.empty())
    {
        max_sum = max(max_sum, temp->val + st.top());
        temp = temp->next;
        st.pop();
    }
    return max_sum;
}

int main()
{
    return 0;
}