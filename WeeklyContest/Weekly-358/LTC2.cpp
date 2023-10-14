/*--------  Medium --------*/

/*- Double a Number Represented as a Linked List -*/

//////// Question number 2816.

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

/* Upsolving solutions */

// 1) Reversing the List

ListNode *reverseTheList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseTheList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

ListNode *doubleIt(ListNode *head)
{
    head = reverseTheList(head);
    int carry = 0;
    for (ListNode *temp = head; temp; temp = temp->next)
    {
        int value = temp->val;

        int newvalue = value * 2 + carry;
        int remainder = (newvalue % 10);
        carry = (newvalue / 10);

        temp->val = remainder;

        if (temp->next == NULL and carry != 0)
        {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
    }
    head = reverseTheList(head);

    return head;
}

// 2) Using Recursion

int doubleItHelper(ListNode*head)
    {
        if(head==NULL)
          return 0;
        
        int carry = doubleItHelper(head->next);

        int curSum = head->val;
        curSum= curSum*2+carry;

        int remainder = curSum%10;
        int newCarry = curSum/10;

        head->val = remainder;

        return newCarry;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        ListNode*newHead = head;
        int carry = doubleItHelper(newHead);    

        if(carry!=0)
        {
            ListNode*temp = new ListNode(carry);
            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }

/* Contest Solution */

ListNode *doubleIt(ListNode *head)
{
    vector<int> new_list;
    ListNode *temp = head;
    while (temp != NULL)
        new_list.push_back(temp->val), temp = temp->next;

    vector<int> new_list2;
    int rem = 0;

    for (auto element : new_list)
        cout << element << " ";
    cout << endl;

    for (int i = new_list.size() - 1; i >= 0; i--)
    {
        int value = new_list[i];
        value *= 2;

        value += rem;

        string p = to_string(value);

        if (p.length() == 2)
            new_list2.push_back(p[1] - '0'), rem = p[0] - '0';
        else
            new_list2.push_back(p[0] - '0'), rem = 0;
    }

    if (rem > 0)
        new_list2.push_back(rem);

    reverse(new_list2.begin(), new_list2.end());

    ListNode *newHead = new ListNode(-1);
    ListNode *temp1 = newHead;

    for (int i = 0; i < new_list2.size(); i++)
    {
        ListNode *temp_var = new ListNode(new_list2[i]);
        temp1->next = temp_var;
        temp1 = temp1->next;
    }

    temp1->next = NULL;

    return newHead->next;
}

int main()
{
    return 0;
}