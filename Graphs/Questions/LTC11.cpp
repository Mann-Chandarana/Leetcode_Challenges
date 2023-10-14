/*--------  Medium --------*/

/*- Clone Graph -*/

//////// Question number 133.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/* Using DFS */

unordered_map<Node *, Node *> mp;

void dfs(Node *n, Node *cloneNode)
{
    for (auto x : n->neighbors)
    {

        if (mp.find(x) == mp.end())
        {
            Node *clone = new Node(x->val);
            mp[x] = clone;
            cloneNode->neighbors.push_back(clone);
            dfs(n, clone);
        }
        else
            cloneNode->neighbors.push_back(mp[x]);
    }
}

Node *cloneGraph(Node *node)
{
    if (!node)
        return node;

    Node *cloneNode = new Node(node->val);

    mp[node] = cloneNode;

    dfs(node, cloneNode);
}

/* Using BFS*/

Node *cloneGraph(Node *node)
{
    if (!node)
        return node;

    unordered_map<Node *, Node *> mp;
    queue<Node *> q;

    Node *cloneNode = new Node(node->val);
    mp[node] = cloneNode;
    q.push(node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        for (auto x : temp->neighbors)
        {
            if (mp.find(x) == mp.end())
            {
                mp[x] = new Node(x->val);
                q.push(x);
            }
            mp[temp]->neighbors.push_back(mp[x]);
        }
    }

    return cloneNode;
}

int main()
{
    return 0;
}