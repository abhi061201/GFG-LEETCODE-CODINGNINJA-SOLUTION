// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    #define ll long long int
  public:
    long long int count(int arr[], int m, int n) {
     
     vector<vector<ll>>dp(m+1,vector<ll>(n+1,-1));
     return go(arr,m-1,n,dp);
       
    }
    ll go(int arr[], int m, int T,vector<vector<ll>>&dp){
        if(m==0){
            if(T%arr[0]==0)return 1;
            else return 0;
        }
        if(dp[m][T]!=-1)return dp[m][T];
        ll non_take= go(arr,m-1,T,dp);
        ll take=0;
        if(T>=arr[m])take= go(arr,m,T-arr[m],dp);
        return dp[m][T]= take+non_take;
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
