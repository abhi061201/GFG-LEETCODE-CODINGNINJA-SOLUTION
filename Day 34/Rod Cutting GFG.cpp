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
        vector<int> dp(n+1,-1);
        return go(n,price,dp);
        
    }
    int go(int n, int price[] ,vector<int>&dp ){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans= INT_MIN;
        
        for(int cut=1 ; cut<=n;cut++){
            int temp= price [cut-1]+go(n-cut,price,dp);
           dp[n]=  ans=max(ans,temp);
        }
        return ans;
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
