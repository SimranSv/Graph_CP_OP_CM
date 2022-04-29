//https://codeforces.com/contest/20/problem/C 
//Simran Vedpathak
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define readInputFile                 \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
const ll N = 1e6 + 10;
const ll inf = 1e18+7;
ll n, m;
set<pair<ll, ll>> mindist;
vector<pair<ll, ll>> adj[N];
vector<ll> dist(N, inf);
vector<ll> vis(N);
vector<ll> par(N);
void solve()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll y, x, wt;
        cin >> x >> y >> wt;
        adj[x].pb({y, wt});
        adj[y].pb({x, wt});
    }
    dist[1] = 0;
    mindist.insert({0, 1});
    par[1] = -1;
    while (mindist.size() > 0)
    {
        // pair<ll, ll> pp;
        auto pp = mindist.begin();

        mindist.erase(mindist.begin());
        ll ff = (*pp).second;
        if (vis[ff])
            continue;
        vis[ff] = 1;

        for (auto &i : adj[ff])
        {
            if (dist[ff] + i.second < dist[i.first])
            {
                par[i.first] = ff;
                dist[i.first] = i.second + dist[ff];
                mindist.insert({dist[i.first], i.first});
            }
        }
    }
    ll node = n;
    vector<ll> ans;
    if(dist[node]==inf){
        cout<<-1<<'\n';
        return;
    }
    while (node != -1)
    {
        ans.pb(node);
        node = par[node];
    }
    reverse(ans.begin(), ans.end());
    for(auto &i:ans)cout<<i<<" ";
    cout<<'\n';
}
int main()
{
    FAST;
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}