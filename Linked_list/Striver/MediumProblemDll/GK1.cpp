/* Geeks for geeks :- Find the pair with given sum in DLL */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    struct Node *p = head;

    unordered_set<int> s;
    while (p)
    {
        s.insert(p->data);
        p = p->next;
    }
    p = head;
    while (p)
    {
        if (s.find(target - p->data) != s.end() && p->data < target - p->data)
        {
            ans.push_back({p->data, target - p->data});
        }

        p = p->next;
    }
    return ans;
}

int main()
{
    return 0;
}