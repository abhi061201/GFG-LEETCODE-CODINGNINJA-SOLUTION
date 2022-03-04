// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
#define ll long long
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<ll>>dp(n+1, vector<ll>(x+1,-1));
        return go(m,n,x,dp);
        
    }
    ll go(int m, int n ,int x, vector<vector<ll>>&dp){
        if(n==0){
            return x==0?1:0;
        }
        if(dp[n][x]!=-1)return dp[n][x];
        ll ways=0;
        for(int y=1 ;y<=m && x>=y;y++){
            ways+= go(m,n-1 ,x-y,dp);
        }
        return dp[n][x] =ways;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends
