#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;
vector<int> color(N, -1);
bool check_Bipartite(int i, vector<int> adj[], queue<int> Q)
{
    for (auto &j : adj[i])
    {
        if (color[j] == -1)
        {
            color[j] = 1 - color[i];
        }
        else
        {
            if (color[i] == color[j])
                return 0;
        }
        // Q.push(j);
    }
    return 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> vis(n + 1);
    queue<int> Q;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {

            Q.push(i);
            while (!Q.empty())
            {
                int node = Q.front();

                if (!check_Bipartite(node, adj, Q))
                {
                    cout << "NO\n";
                    return 0;
                }

                // cout << Q.front() << " ";
                Q.pop();
            }
        }
        cout << "YES\n";
    }
}