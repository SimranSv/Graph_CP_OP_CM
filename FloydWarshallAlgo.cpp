#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vll vector<ll>
const ll N = 1e3 + 10;
const ll INF = 1e9 + 7;

int dist[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }  for (int j = 1; j <= m; j++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    for (int k = 1; k <= n; k++)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
int32_t main()
{

    // cout << fixed << setprecision(18);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        // cout << '\n';
    }
}
