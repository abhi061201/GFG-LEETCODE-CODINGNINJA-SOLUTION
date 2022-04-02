// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return go(n-1,n,price,dp);
    }
    
    int go(int i, int N, int price[], vector<vector<int>>&dp){
        
        if(i==0)return price[0]*N;
        if(dp[i][N]!=-1)return dp[i][N];
        int ntake=0+go(i-1, N, price,dp);
        int take= INT_MIN;
        int rlength= i+1;
        if(rlength<= N)take=price[i]+go(i, N-rlength, price,dp);
        
        return dp[i][N]=max(take, ntake);
        
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
