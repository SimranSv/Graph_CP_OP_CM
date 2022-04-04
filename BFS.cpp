#include "bits/stdc++.h"
using namespace std;
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
        if (!vis[i])
        {
            Q.push(i);
            while (!Q.empty())
            {
                for (auto &j : adj[i])
                {
                    if (!vis[j])
                    {
                        Q.push(j);
                        vis[j] = 1;
                    }
                }
                cout << Q.front() << " ";
                Q.pop();
            }
        }
    }
}