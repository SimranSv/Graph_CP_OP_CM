//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
const ll N = 1e5 +10;
vector<ll> par(N);
vector<ll> Rank(N);
#define pb push_back
class dsu{
    public:

};

class Solution{
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
  
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        map<string,int>mp;
        int n=accounts.size();
        for(int i=0;i<n;i++){make(i);}
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end())
                mp[accounts[i][j]]=i;
                else{
                    Union(mp[accounts[i][j]],i);
                    
                    
                }
            }
        }
        vector<string>ans[n];
        
        for(auto &i:mp){
            ans[Find(i.second)].pb(i.first);
            
            
        }
        vector<vector<string>>lol;
        for(int i=0;i<n;i++){
            if(ans[i].size()==0)continue;
            else {
                vector<string>temp;
                sort(ans[i].begin(),ans[i].end());
                temp.pb(accounts[i][0]);
                for(int j=0;j<ans[i].size();j++){
                    temp.pb(ans[i][j]);
                }
                lol.pb(temp);
            }
        }
        return lol;
        
        // int m=
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends