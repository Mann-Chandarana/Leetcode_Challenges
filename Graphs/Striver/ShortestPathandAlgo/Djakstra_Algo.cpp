/* Implementing Dijkstra Algorithm */

/* Time complexity :- O(ElogV) */

#include <bits/stdc++.h>
using namespace std;

/* Using set */

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st; // {distance,node}
    vector<int> distance(V, 1e9);

    distance[S] = 0;

    st.insert({0, S});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto neighbour : adj[node])
        {
            int adjNode = neighbour[0];
            int weight = neighbour[1];

            if (dis + weight < distance[adjNode])
            {
                if (distance[adjNode] != 1e9)
                    st.erase({distance[adjNode], adjNode});

                distance[adjNode] = dis + weight;
                st.insert({distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}

/* Using priority queue */

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance,node}
    vector<int> distance(V, 1e9);

    distance[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto neighbour : adj[node])
        {
            int neigh = neighbour[0], weight = neighbour[1];

            if (dis + weight < distance[neigh])
            {
                distance[neigh] = dis + weight;
                pq.push({distance[neigh], neigh});
            }
        }
    }

    return distance;
}

int main()
{
    return 0;
}