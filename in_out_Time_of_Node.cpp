#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
vector<int> vis(N, 0);

vector<int> time_in(N), time_out(N);
int dfs_timer = 1;

void dfs(int v)
{
     cout << dfs_timer << '\n';
    time_in[v] = dfs_timer++;
   
    vis[v] = 1;
    for (int u : adj[v])
    {
        if (vis[u] == 0)
            dfs(u);
    }

    // cout<<dfs_timer<<'\n';
    time_out[v] = dfs_timer++;
}
int main()
{

    int n, m;
    cin >> n >> m;

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
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " Input " << time_in[i] << " Output " << time_out[i] << '\n';
    }
}