// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1) );
        return go(n-1, price,n,dp);
        
    }
    int go(int i, int price[], int rodl,vector<vector<int>>&dp){
        if(i==0){
            return price[0]*rodl;
        }
        if(dp[i][rodl]!=-1)return dp[i][rodl];
        int n_take= go(i-1, price, rodl,dp);
        int x= i+1;
        int take= INT_MIN;
        if(x<=rodl)take= price[i]+ go(i, price, rodl-x,dp);
        return dp[i][rodl]=max(take, n_take);
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
