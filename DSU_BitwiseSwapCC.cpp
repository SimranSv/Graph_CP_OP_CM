//Simran Vedpathak
//https://www.codechef.com/problems/BITSWAPS

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll INF = 1e9 + 7;
const ll N = 3e5 + 10;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

unordered_map<ll, ll> par, Rank;
void make(ll v)
{
    par[v] = v;
    Rank[v] = 0;
}
ll find_parent(ll v)
{
    if (v == par[v])
        return v;
    else
        return par[v] = find_parent(par[v]);
}
void union_set(ll a, ll b)
{
    ll roota = find_parent(a);
    ll rootb = find_parent(b);
    if (roota != rootb)
    {
        if (Rank[roota] < Rank[rootb])
        {
            swap(roota, rootb);
        }
        par[rootb] = roota;
        Rank[roota]++;
    }
}
void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n), sorted(n);
    vector<ll> adj[33];
    par.clear();
    Rank.clear();

    for (auto &i : v)
    {
        cin >> i;
        make(i);
    }
    sorted = v;
    sort(sorted.begin(), sorted.end());

    for (ll j = 0; j <= 31; j++)
    {
        for (auto i = 0; i < n; i++)
        {

            if (v[i] & ((ll)1 << j))
            {
                adj[j].pb(v[i]);
            }
        }
    }

    for (int i = 0; i <= 31; i++)
    {
        for (int j = 1; j < adj[i].size(); j++)
        {
            union_set(adj[i][j-1], adj[i][j]);
            
        }
       
    }
    for (int i = 0; i < n; i++)
    {
        if (find_parent(v[i]) != find_parent(sorted[i]))
        {
            cout << "NO\n";

            return;
        }
        
    }
    cout << "YES\n";
   
}
int main()
{
    FAST;
    ll t;
    cin >> t;

    while (t--)
    {

        solve();
    }
}