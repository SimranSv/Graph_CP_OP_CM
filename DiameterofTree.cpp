#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vll vector<ll>
const ll N = 1e5 + 10;
const ll mod = 1e9 + 7;
vector<int> depth(N, 0);

void dfstrees(int i, int par, vector<int> adj[])
{
    for (auto &child : adj[i])
    {

        if (child == par)
            continue;
        depth[child] = depth[i] + 1;
        dfstrees(child, i, adj);
    }
}
void solve()
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
    dfstrees(1, -1, adj);
    int maxind = max_element(depth.begin(), depth.end()) - depth.begin();
    fill(depth.begin(), depth.end(), 0);
    dfstrees(maxind, -1, adj);
    maxind = max_element(depth.begin(), depth.end()) - depth.begin();
    cout << "Diameter of Tree is " << depth[maxind] << '\n';
}
int main()
{
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}