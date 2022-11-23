//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long
const ll N = 1e5 +10;
vector<ll> par(N);
vector<ll> Rank(N);
class Solution {
  public:
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
 
 
    int numProvinces(vector<vector<int>> adj, int V) {
        for(int i=0;i<V;i++)make(i);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]){
                    Union(i,j);
                    
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(Find(i)==i)ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends