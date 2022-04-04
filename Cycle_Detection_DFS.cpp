#include "bits/stdc++.h"
using namespace std;

bool dfs(int i, int it, vector<int> adj[], vector<int> &vis)
{

    vis[i] = 1;
   
    for (auto &j : adj[i])
    {
        if (!vis[j])
        {
            if(dfs(j, i, adj, vis))return true;
        }
        else
        {
            if (j!=it)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> vis(n + 1);

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
            if (dfs(i, -1, adj, vis))cout << "YES\n";
        }
    }
}