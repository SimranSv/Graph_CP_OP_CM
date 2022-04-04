#include "bits/stdc++.h"
using namespace std;
//#define int long long
vector<int> ans;
const int N = 1e5 + 10;
vector<int> height(N, 0), depth(N, 0);
void dfs(int i, int par, vector<int> adj[])
{

    for (auto &j : adj[i])
    {
        if (j == par)
            continue;
        depth[j] = depth[i] + 1;
        dfs(j, i, adj);
        height[i] = max(height[j]+1, height[i]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj);

    cout << "Depth \n";
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<" "<< depth[i] << '\n';
    }
    cout << "Height \n";
    for (int i = 1; i <= n; i++)
    {
        cout <<i<<" "<< height[i] << '\n';
    }
    return 0;
}