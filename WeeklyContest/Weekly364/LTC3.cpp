#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

ll ans = 0;

void dfs(int start, vector<vector<int>> &adj, vector<int> &isPrime, bool prime)
{
    for (auto neighbour : adj[start])
    {
        cout << "Hi" << endl;
        if (prime)
        {
            if (!isPrime[neighbour])
            {
                ans++;
                cout<<neighbour<<endl;
                dfs(neighbour, adj, isPrime, prime);
            }
        }
        else
        {
            if (isPrime[neighbour])
            {
                ans++;
                dfs(neighbour, adj, isPrime, true);
            }
        }
    }
}

long long countPaths(int n, vector<vector<int>> &edges)
{
    // Creating sieve

    vector<int> isPrime(n + 1, 1);

    if (n >= 2)
        isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < edges.size(); i++)
        adj[edges[i][0]].push_back(edges[i][1]);

    for (int i = 0; i < edges.size(); i++)
    {
        if (isPrime[edges[i][0]])
            dfs(edges[i][0], adj, isPrime, true);

        else
            dfs(edges[i][0], adj, isPrime, false);
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    cout << countPaths(5, edges) << endl;
    return 0;
}