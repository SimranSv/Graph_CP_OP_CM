#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
vector<pair<ll, ll>> adj[N];
vector<ll> lvl(N, mod);
ll n, m;
int bfs()
{
    deque<ll> dq;
    dq.pb(1);
    lvl[1] = 0;
    while (!dq.empty())
    {

        ll curv = dq.front();
        dq.pop_front();
        for (auto &j : adj[curv])
        {
            ll curnode = j.first;
            ll wt = j.second;
            if (wt + lvl[curv] < lvl[curnode])
            {
                lvl[curnode] = lvl[curv] + wt;
                if (wt == 0)
                    dq.push_front(j.first);
                else
                    dq.push_back(j.first);
            }
        }
    }
    return (lvl[n] == mod)? -1 : lvl[n];
}
void solve()
{

    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }
    cout << bfs() << '\n';
}
int main()
{
    ll t;
    t = 1;
    while (t--)
        solve();
}