// Simran Vedpathak
// Full Comdingbazi
//https://codeforces.com/problemset/problem/913/B
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vll vector<ll>
#define ff first
#define ss second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll m = 1e5 + 10;
vll adj[m];
map<ll, ll> mp;
void dfs(ll root, ll par)
{
    for (auto &i : adj[root])
    {
        if (i == par)
            continue;
        if (mp[i])
        {
            mp[root]--;
        }
        //  mp[root]--;
        // cout<<i<<" ";
        dfs(i, root);
    }
    if (adj[root].size()>1)
    {
        if (mp[root] < 3)
        {
           // cout << root << " ";
             cout << "No\n";
            exit(0);

        }  
    }
}
void solve()
{
    ll n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        adj[x].pb(i);
          adj[i].pb(x);
        mp[x]++;
    }
    dfs(1, -1);
    cout << "Yes\n";
}
int main()
{
    FAST;

    ll n;
    n = 1;
    // cin >> n;
    while (n--)
        solve();
}