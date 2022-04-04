#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;
#define ll long long
vector<ll> adj[N + 1];
vector<ll> vis(N + 1);
vector<ll> dfs(N + 1);
bool dfscheck(ll node)
{
    vis[node] = 1;
    dfs[node] = 1;
    for (auto &j : adj[node])
    {
        if (!vis[j])
        {

            if (dfscheck(j))
                return true;
        }
        else
        {
            if (dfs[j])
            {
                return true;
            }
        }
    }
    dfs[node] = 0;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfscheck(i))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
