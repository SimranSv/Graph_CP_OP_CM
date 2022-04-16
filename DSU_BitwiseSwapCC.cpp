// Simran Vedpathak
// https://www.codechef.com/problems/BITSWAPS

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
const ll INF = 1e9 + 7;
const ll N = 3e6 + 10;
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
        ll temp = -1;
        for (auto i = 0; i < n; i++)
        {
            if (v[i] & ((ll)1 << j))
            {
                temp = i;
                break;
            }
        }

        for (auto i = temp + 1; i < n; i++)
        {
            if (temp != -1 && v[i] & ((ll)1 << j))
            {
                union_set(v[temp], v[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (par[v[i]] != par[sorted[i]])
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
