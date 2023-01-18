//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define M 1000000007;
class Solution{
    // typedef M =1e9 +7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n, vector<int>(sum+1,-1));
       return go(n-1, sum, arr,dp);
	}
	int go(int i, int k, int arr[],vector<vector<int>>&dp)
	{
	    if(i<0)
	    {
	        return k==0;
	    }
	    if(dp[i][k]!=-1)return dp[i][k];
	    int take=0, n_take=0;
	    if(k>= arr[i])take= go(i-1, k-arr[i],arr,dp) %M;
	    n_take= go(i-1, k, arr,dp)%M;
	    return dp[i][k]=(take+n_take)%M;
	}
	  
};

//{ Driver Code Starts.
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