// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
#define ll long long int
  public:
    long long int count(int arr[], int m, int n) {
            vector<vector<ll>>dp(m,vector<ll>(n+1,-1));
        return go(m-1,n,arr,dp);
        
    }
    ll go(int i,int n,int arr[],  vector<vector<ll>>&dp){
        
        if(i==0){
            if(n%arr[0]==0)return 1;
            else return 0;
            
        }
        if(dp[i][n]!=-1)return dp[i][n];
        ll non_take= go(i-1,n,arr,dp);
        ll take=0;
        if(arr[i]<=n){take= go(i,n-arr[i],arr,dp);}
        return dp[i][n]=take+non_take;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
