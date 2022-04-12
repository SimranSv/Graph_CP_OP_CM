#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
vector<ll> par(N);
vector<ll> Rank(N);
void make(ll v)
{
    par[v] = v;
    Rank[v] = 0;
}
int Find(ll v)
{
    if (v == par[v])
        return v;
    else
    {

        return par[v] = Find(par[v]);
    }
}
void Union(ll a, ll b)
{
    ll apar = Find(a);
    ll bpar = Find(b);
    if (apar != bpar)
    {
        if (Rank[apar] < Rank[bpar])
        {
            swap(apar, bpar);
            par[bpar] = apar;
        }
        else
        {
            par[bpar] = apar;

            Rank[apar]++;
        }
    }
}

void solve()
{
    par[1] = 1;
    par[2] = 1;
    par[3] = 2;
    par[5] = 3;
    par[7] = 5;
    par[6] = 3;
    par[8] = 6;
    par[4] = 2;

    Find(3);
    Find(8);
    cout << par[8];
}
int main()
{
    ll t;
    t = 1;
    // cin >> t;
    while (t--)
        solve();
}