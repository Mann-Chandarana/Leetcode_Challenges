/*--------  Medium --------*/

/*- Validate Binary Tree Nodes -*/

//////// Question number 1361.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Using DSU */

vector<int> parent;
int components;

int find(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

bool Union(int par, int child)
{
    int child_ka_parent = find(child);

    if (child_ka_parent != child)
        return false;

    int parent_ka_parent = find(par);

    if (parent_ka_parent == child_ka_parent)
        return false;

    parent[child] = par;
    components--;
    return true;
}

bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
{
    components = n;
    parent.resize(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        if (leftChild[i] >= 0 and !Union(i, leftChild[i]))
            return false;

        if (rightChild[i] >= 0 and !Union(i, rightChild[i]))
            return false;
    }
    return components == 1;
}

/* Approach -1)  */

bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<int> indegree(n, 0);
    unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < n; i++)
    {
        int left = leftChild[i];
        int right = rightChild[i];

        if (left != -1)
        {
            graph[i].push_back(left);
            indegree[left]++;
        }

        if (right != -1)
        {
            graph[i].push_back(right);
            indegree[right]++;
        }
    }

    vector<int> root_candiates;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            root_candiates.push_back(i);
    }

    if (root_candiates.size() != 1)
        return false;

    int root = root_candiates[0];

    queue<int> q;
    unordered_set<int> seen;

    q.push(root);
    seen.insert(root);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (graph.find(node) != graph.end())
        {
            for (int child : graph[node])
            {
                if (seen.find(child) != seen.end())
                    return false;

                seen.insert(child);
                q.push(child);
            }
        }
    }

    return seen.size() == n;
}

/* Approach -2) Using BFS */

bool isBinaryTreeValid(int root, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<bool> visited(leftChild.size(), false);
    queue<int> nodeQueue;                         
    nodeQueue.push(root);
    visited[root] = true;

    while (!nodeQueue.empty())
    {
        int current = nodeQueue.front();
        nodeQueue.pop();

        if (leftChild[current] != -1)
        {
            if (visited[leftChild[current]]) 
                return false;

            nodeQueue.push(leftChild[current]);
            visited[leftChild[current]] = true;
        }

        // Check right child
        if (rightChild[current] != -1)
        {
            if (visited[rightChild[current]]) 
                return false;

            nodeQueue.push(rightChild[current]);
            visited[rightChild[current]] = true; 
        }
    }

    for (int i = 0; i < visited.size(); i++)
        if (!visited[i])
            return false;
    return true;
}

bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        int left = leftChild[i];
        int right = rightChild[i];

        if (left != -1)
            indegree[left]++;

        if (right != -1)
            indegree[right]++;
    }

    vector<int> root_candiates;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            root_candiates.push_back(i);
    }

    if (root_candiates.size() != 1)
        return false;

    int root = root_candiates[0];

    return isBinaryTreeValid(root, leftChild, rightChild);
}

int main()
{
    return 0;
}