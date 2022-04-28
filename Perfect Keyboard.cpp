//https://codeforces.com/contest/1303/problem/C
//Simran Vedpathak
#include "bits/stdc++.h"
using namespace std;
#define ll long long

void dfs(ll alpha, vector<set<ll>> adj, vector<ll> &vis)
{
    vis[alpha] = 1;
    cout << (char)(alpha + 'a');
    for (auto &i : adj[alpha])
    {

        if (!vis[i])
        {
            //vis[i] = 1;

            dfs(i, adj, vis);
        }
    }
    return;
}
void solve()
{
    vector<set<ll>> adj(26);
    vector<ll> vis(26);
    vector<ll> freq(26);
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout<<"YES\n";
        for (int i = 0; i < 26; i++)
        {
            if (!vis[i])
            {
                cout << (char)(i + 'a');
            }
        }
        cout<<"\n";
    }

    for (int i = 1; i < s.size(); i++)
    {
        adj[s[i - 1] - 'a'].insert(s[i] - 'a');
        adj[s[i] - 'a'].insert(s[i - 1] - 'a');
    }

    ll cnt = 0;
    ll store = 0;
    for (int i = 0; i < 26; i++)
    {
       
        if (adj[i].size() == 1)
        {
            store = i;
            cnt++;
        }
    }

    for (int i = 0; i < 26; i++)
    {

        if (adj[i].size() > 2)
        {
            cout << "NO\n";
            return;
        }
    }
    if (cnt != 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs(store, adj, vis);
    for (int i = 0; i < 26; i++)
    {
        if (!vis[i])
        {
            cout << (char)(i + 'a');
        }
    }
    cout << '\n';
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}