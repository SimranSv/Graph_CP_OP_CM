#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e5 + 10;

vector<ll> temp(N);
// vector<ll> ans;
void dfs(ll i, ll par, vector<ll> adj[])
{
    temp[i] = par;
    for (auto &it1 : adj[i])
    {
        if (it1 == par)
            continue;

        dfs(it1, i, adj);
    }
}
vector<ll> path(ll node)
{
    //  vector<ll> temp(N);
    vector<ll> ans;
    while (node != -1)
    {
        ans.pb(node);
        node = temp[node];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void solve()
{

    // vector<ll> ans;
    ll n, m, x, y;
    cin >> n >> m;
    vector<ll> adj[n + 1];

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1, adj);

    cin >> x >> y;
    vector<ll> v_x = path(x);
    vector<ll> v_y = path(y);
    ll lca = -1;

    for (int i = 0; i < min(v_x.size(), v_y.size()); i++)
    {
        if (v_x[i] == v_y[i])
        {
            lca = v_x[i];
        }else break;
    }
    cout<<lca<<'\n';
   
}
int main()
{
    ll t;
    t = 1;
    //  cin >> t;
    while (t--)
        solve();
}