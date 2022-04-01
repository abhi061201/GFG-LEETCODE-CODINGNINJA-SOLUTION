// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int s[], int m, int n) {
        vector<vector<long long int>>dp(m+1, vector<long long int >(n+1,-1));
        return go(s, m-1,n,dp);
    }
    
    long long int go(int arr[], int i, int t, vector<vector<long long int>>&dp){
        
        if(t==0)return 1;
        if(i==0 ){
            return t%arr[0]==0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        long long int nonpick= go(arr, i-1, t,dp);
        long long int pick=0;
        if(arr[i]<=t)pick= go(arr, i, t-arr[i],dp );
        return dp[i][t]=pick+nonpick;
        
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
