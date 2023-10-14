/*-------- Medium -----------*/

/*- Delete Node in a Linked List  -*/

//////// Question number 237.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }

    ~ListNode()
    {
        if (next != NULL)
            next = NULL;
    }
};

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    return 0;
}