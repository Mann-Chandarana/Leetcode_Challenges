/*-------- Medium -----------*/

/*- Copy List with Random Pointer -*/

//////// Question number 138.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

/* Best approach */

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;

    // MERGING LISTS
    for (Node *l1 = head; l1 != NULL; l1 = l1->next->next)
    {
        Node *l2 = new Node(l1->val);
        l2->next = l1->next;
        l1->next = l2;
    }
    Node *newHead = head->next;

    // ALLOCATING RANDOMS
    for (Node *l1 = head; l1 != NULL; l1 = l1->next->next)
    {
        if (l1->random != NULL)
            l1->next->random = l1->random->next;
    }

    // SEPERATING LISTS
    for (Node *l1 = head; l1 != NULL; l1 = l1->next)
    {
        Node *l2 = l1->next;
        l1->next = l2->next;
        if (l2->next)
            l2->next = l2->next->next;
    }
    return newHead;
}

/* Using Unordered map */

Node *copyRandomList(Node *head)
{
    Node *cloneHead = NULL, *cloneTail = NULL;

    Node *temp = head;
    unordered_map<Node *, Node *> orginalToclone;

    while (temp)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    Node *originalNode = head, *cloneNode = cloneHead;

    while (originalNode)
    {
        orginalToclone[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    cloneNode = cloneHead;
    originalNode = head;

    while (cloneNode)
    {
        cloneHead->random = orginalToclone[originalNode->random];
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    return cloneHead;
}

/* Without using unordered map */

Node *copyRandomList(Node *head)
{
    Node *cloneHead = NULL, *cloneTail = NULL;

    Node *temp = head;

    while (temp)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // step 2: insert nodes of Clone List in between originalList

    Node *originalNode = head, *cloneNode = cloneHead;

    while (originalNode != NULL and cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // Step 3: Random pointer copy

    originalNode = head, cloneNode = cloneHead;

    while (originalNode != NULL and cloneNode != NULL)
    {
        if (originalNode->random != NULL)
            cloneNode->random = originalNode->random->next;
        else
            cloneNode->random = NULL;

        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    // step 4 revert step2 changes

    originalNode = head, cloneNode = cloneHead;
    while (originalNode and cloneNode)
    {
        originalNode->next = originalNode->next ? cloneNode->next : originalNode->next;

        originalNode = originalNode->next;
        cloneNode->next = cloneNode->next ? originalNode->next ? cloneNode->next;

        cloneNode = cloneNode->next;
    }

    // step 5 answer return

    return cloneHead;
}

/* Another approach */

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> m;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *copy = new Node(temp->val);
        m[temp] = copy;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        m[temp]->next = m[temp->next];
        m[temp]->random = m[temp->random];
        temp = temp->next;
    }
    return m[head];
}

int main()
{
    return 0;
}