#include "bits/stdc++.h"
using namespace std;

bool dfs(int node, vector<int> &color, vector<int> adj[])
{

    // color[node]+=1-
    for (auto &j : adj[node])
    {
        if (color[j] == -1)
        {
            color[j] = 1 - color[node];
            dfs(j, color, adj);
        }
        else
        {
            if (color[j] == color[node])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> color(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, color, adj))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}