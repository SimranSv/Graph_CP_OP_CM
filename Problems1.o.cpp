#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e5 + 10;
const ll mod = 1e9 + 7;

void dfs(ll i, vector<ll> adj[], vector<ll> &vis, ll &ans)
{
    vis[i] = 1;
    ++ans;

    for (auto &it : adj[i])
    {
        if (!vis[it])
        {

            dfs(it, adj, vis, ans);
        }
    }
}
void solve()
{
    ll count = 0, size = 1, ans = 0;
    ll n, m;

    cin >> n >> m;
    vector<ll> adj[n + 1];
    vector<ll> vis(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (ll i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            ans = 0;
            count++;
            dfs(i, adj, vis, ans);
            size =((size%mod) *(ans % mod))%mod;
        }
    }

        cout << count << " " << size << '\n';
    
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}