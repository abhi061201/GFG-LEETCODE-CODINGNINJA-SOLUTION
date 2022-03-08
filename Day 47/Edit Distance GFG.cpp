// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
       
        int n= s.length();
        int m= t.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
    return go(s,t,0,0,dp);
        
        
        
    }   
    int go(string s, string t, int curi, int curj, vector<vector<int>>&dp){
        if(curi == s.length())return t.length()-curj;
        if(curj == t.length())return s.length()-curi;
        
        if(dp[curi][curj]!=-1)return dp[curi][curj];
        if(s[curi]==t[curj])
          return dp[curi][curj]=go(s,t,curi+1, curj+1,dp);
        
        
        int insert= 1+go(s,t,curi,curj+1,dp);
        int _remove= 1+go(s,t,curi+1,curj,dp);
        int replace = 1+go(s,t,curi+1,curj+1,dp);
        
        return dp[curi][curj]=min(insert, min(_remove,replace));
    }
        
    
    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
