/*--------Medium-----------*/

/*- Odd even linked list -*/

//////// Question number 328.

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

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
    {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;

    while (odd->next && even->next)
    {
        odd->next = even->next;  
        odd = odd->next;    
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_start; 
    return head;
}

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
        return head;
    }
    ListNode *oddHead = head, *evenHead = head->next, *odd = oddHead, *even = evenHead;

    head = head->next->next;
    int turn = 0;
    while (head != NULL)
    {
        if (turn == 0)
        {
            oddHead->next = head;
            oddHead = oddHead->next;
            turn = 1;
        }
        else
        {
            evenHead->next = head;
            evenHead = evenHead->next;
            turn = 0;
        }

        head = head->next;
    }

    oddHead->next = even;
    evenHead->next = nullptr;

    return odd;
}

int main()
{

    return 0;
}