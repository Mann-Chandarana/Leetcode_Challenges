/*--------  Hard --------*/

/*- Design Graph With Shortest Path Calculator -*/

//////// Question number 2642.

#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vpii;
typedef vector<pair<pair<int, int>, int>> vppi;
typedef unordered_map<string, vector<string>> umps;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

/* Using Dijkstra's algorithm */

class Graph
{
public:
    int n;
    vector<pi> *adj;

    int minimumDistance(int node1, int node2)
    {
        vector<int> distance(n + 1, 1e9);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        distance[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (distance[u] < dist)
                continue;

            for (auto element : adj[u])
            {
                int v = element.first;
                int w = element.second;

                if (dist + w < distance[v])
                {
                    distance[v] = dist + w;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance[node2] == 1e9 ? -1 : distance[node2];
    }

    Graph(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        adj = new vector<pi>[n + 1];

        for (auto element : edges)
        {
            int u = element[0];
            int v = element[1];
            int w = element[2];

            adj[u].pb({v, w});
        }
    }

    void addEdge(vector<int> edge)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].pb({v, w});
    }

    int shortestPath(int node1, int node2)
    {
        return minimumDistance(node1, node2);
    }
};

/* Using Floyd Warshall algorithm */

class Graph
{
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>> &edges)
    {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));

        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u][v] = cost;
        }

        for (int i = 0; i < n; i++)
        {
            adj[i][i] = 0;
        }

        // Floyd Warshal
        for (int k = 0; k < n; k++)
        {

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {

                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge)
    {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        // check with 2 new vertices - u and v

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                adj[i][j] = min(adj[i][j], adj[i][u] + cost + adj[v][j]);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
    }
};

int main()
{
    return 0;
}