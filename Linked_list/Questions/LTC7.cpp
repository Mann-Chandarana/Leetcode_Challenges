/*--------Medium-----------*/

/*- Split Linked List in Parts -*/

//////// Question number 725.

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

int sizeOfList(ListNode *head)
{
    if (head == NULL)
        return 0;

    int len = 0;

    while (head != NULL)
        len++, head = head->next;

    return len;
}

/********* Optimal Solution *********/

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> answer;

    int length = sizeOfList(head);

    int sizeofnewlist = (length / k);
    int remaining = (length % k);

    while (head != NULL)
    {
        ListNode *newHead = head, *previous = NULL;

        for (int i = 0; i < (sizeofnewlist + (remaining > 0 ? 1 : 0)); i++)
        {
            previous = head;
            head = head->next;
        }

        previous->next = NULL;
        answer.push_back(newHead);
        remaining--;
        k--;
    }

    while(k--)
      answer.push_back(NULL);

    return answer;
}

/********* Less Optimal Solution *********/

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> answer;

    int length = sizeOfList(head);

    if (length <= k)
    {
        while (head != NULL)
        {
            ListNode *temp = new ListNode(head->val);
            answer.push_back(temp);
            head = head->next;
            k--;
        }

        while (k > 0)
            answer.push_back(NULL), k--;
    }
    else
    {
        int sizeofnewlist = (length / k);
        int remaining = (length % k);

        while (head != NULL)
        {
            ListNode *newHead = new ListNode(-1);
            ListNode *temp = new ListNode(-1);
            newHead->next = temp;

            for (int i = 0; i < (sizeofnewlist + (remaining > 0 ? 1 : 0)); i++)
            {
                ListNode *temp1 = new ListNode(head->val);
                temp->next = temp1;
                temp = temp->next;
                head = head->next;
            }
            remaining--;
            answer.push_back(newHead->next->next);
        }
    }
    return answer;
}

int main()
{
    return 0;
}