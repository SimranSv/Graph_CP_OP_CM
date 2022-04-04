#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e5 + 10;
vector<ll> adj[N];
vector<ll> sumsub(N);
void dfstree(int i, int par)
{
    sumsub[i] = i;
    for (auto &j : adj[i])
    {
        if (j != par)
        {
            dfstree(j, i);
            sumsub[i] += sumsub[j];
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfstree(1, -1);
    ll sum=0;
    for (int i = 1; i <=n; i++)
    {
        sum=max((sumsub[1]-sumsub[i])*sumsub[i],sum);
    }
    cout<<sum << '\n';
}
int main()
{
    int t;
    solve();
}