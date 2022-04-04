#include "bits/stdc++.h"
using namespace std;
vector<int> ans;
void dfs(int i, vector<int> adj[], vector<int>&vis)
{
    ans.push_back(i);
    vis[i] = 1;
    for (auto &j : adj[i])
    {
        if (!vis[j])
        {
            dfs(j, adj, vis);
        }
    }
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
            dfs(i, adj, vis);
        }
    }
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";

    }
    cout<<"\n";
}