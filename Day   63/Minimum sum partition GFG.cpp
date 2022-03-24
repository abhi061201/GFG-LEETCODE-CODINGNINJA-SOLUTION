// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int findsum(int arr[], int n){
        int sum=0;
        for(int i=0 ; i<n ; i++)sum+=arr[i];
        return sum;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=findsum(arr,n);
	    int k= sum/2;
	    
	    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
	    dp[0][0]=1;
	    for(int i=1 ; i<=n ; i++){
	        for(int j=0 ; j<=k ; j++){
	            dp[i][j]= dp[i-1][j];
	            if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	        int ans=0;
	        for(int j=k; j>=0 ; j--){
	            if(dp[n][j]==1){
	                ans=j;
	                break;
	            }
	        }
	    
	    return sum-2*ans;
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
