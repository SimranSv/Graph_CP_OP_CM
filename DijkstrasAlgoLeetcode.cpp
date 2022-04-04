
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    int N = 1e5 + 10;
    int inf = 1e9 + 10;
    vector<pair<int, int>> adj[n + 1];
    vector<int> dis(N, inf);
    set<pair<int, int>> st;
    for (auto &i :times)
    {

        adj[i[0]].push_back({i[1],i[2]});
    }

    st.insert({0, k});
    dis[k] = 0;
    while (st.size() > 0)
    {
        auto it = *st.begin();
        int k_node = it.second, k_dis = it.first;
        st.erase(st.begin());
        for (auto &i : adj[k_node])
        {
            if (dis[k_node] + i.second < dis[i.first])
            {
                dis[i.first] = i.second + dis[k_node];
                st.insert({dis[i.first], i.first});
            }
        }
    }
    int mm = 0;
    for (int i = 1; i <= n; i++)
    {
        
        if (dis[i] == inf)
            return -1;
        mm = max(mm, dis[i]);
    }
    return mm;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> times(m + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
       
        times[i].push_back(x);
        times[i].push_back(y);
        times[i].push_back(z);
    }
    //  for (int i = 0; i < m; i++)
    // {
    //     cout<<times[i][0]<<" "<<times[i][1]<<" "<<times[i][2]<<'\n';
    // }
    cout<<networkDelayTime(times,n,m);
}