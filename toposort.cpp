// Coming back to CP soon guys...
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define stll set<ll>
#define msgll multiset<ll, greater<>>
#define msll multiset<ll>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define ss second
#define ff first
#define read(n, x)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll k;                  \
        cin >> k;              \
        x.pb(k);               \
    }
#define rep(i, j, k) for (ll i = j; i < k; i++)
#define st(v) sort(v.begin(), v.end())
#define sz(x) (ll) x.size()
#define no cout << "No\n";
#define yes cout << "Yes\n";
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
ll expo(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
double eps = 1e-6;
// Remove fastio and use endl in Interactive problems
void dfs(ll i,vll v[],vll &vis,stack<ll>&st){
    vis[i]=1;
    for(auto &j:v[i]){
      if(!vis[j])dfs(j,v,vis,st);
    //   cout<<j<<" ";
    }

    st.push(i);


}
void Letsgo()
{
    vll v[6];
    stack<ll>st;
    v[5].pb(0);
    v[4].pb(0);
    v[5].pb(2);
    v[2].pb(3);
    v[3].pb(1);
    v[4].pb(1);
    vll vis(6);
    rep(i,0,6){
    if(!vis[i])    
    dfs(i,v,vis,st);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    FAST;

    ll n = 1, i = 0;
    // cin >> n;

    while (n--)
    {
        Letsgo();
    }
}
// Working hard to get what is mine