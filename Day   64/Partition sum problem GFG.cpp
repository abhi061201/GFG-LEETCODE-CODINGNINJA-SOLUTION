// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
#define M 1000000007

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        // int c_0=0;
        // for(int i=0 ; i<n ; i++)if(arr[i]==0)c_0++;
        return go(arr, n-1, sum, dp);
	}
	
	int go(int arr[], int i , int sum,vector<vector<int>>&dp){
	    
	    if(i<=-1)return sum==0;
	    if(dp[i][sum]!=-1)return dp[i][sum];
	    int nontake= go(arr, i-1, sum,dp)%M;
	    int take=0;
	    if(arr[i]<=sum)take= go(arr, i-1, sum-arr[i],dp)%M ;
	    
	    return dp[i][sum]=(take+nontake)%M;
	}
	
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
