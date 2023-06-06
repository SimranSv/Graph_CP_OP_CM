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
void Letsgo()
{
    vll v[6];
    stack<ll> st;
    v[5].pb(0);
    v[4].pb(0);
    v[5].pb(2);
    v[2].pb(3);
    v[3].pb(1);
    v[4].pb(1);
    vll indegree(6);
    rep(i, 0, 6)
    {
        rep(j, 0, v[i].size())
        {
            indegree[v[i][j]]++;
        }
    }
    queue<ll>q;
    rep(i,0,6){
        if(indegree[i]==0)q.push(i);
    }
    // vll vis(6);
    ll front=0;
    vll vis(6);
    while(!q.empty()){
        front=q.front();
        q.pop();
        vis[front]=1;
        cout<<front<<" ";
        for(auto &j:v[front]){
        if(!vis[j]){
             indegree[j]--;
           if(indegree[j]==0)             
           q.push(j);
                            
          
        }

        }
    }
}
int main()
{
    FAST;

    ll n=1, i = 0;
    // cin >> n;

    while (n--)
    {
        Letsgo();
    }
}
// Working hard to get what is mine