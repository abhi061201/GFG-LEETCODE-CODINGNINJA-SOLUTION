// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long int
class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int> >dp(n+1, vector<int >(n+1,-1));
        return go(arr, 0, n-1,dp);
        
    }
    
    ll go(int arr[], int l , int h, vector<vector<int> >&dp){
        
        
        if(l+1==h)return max(arr[l], arr[h]);
        
        if(dp[l][h]!=-1)return dp[l][h];
        int low_take= arr[l]+ min(go(arr,l+2,h,dp), go(arr,l+1,h-1,dp));
        int high_take= arr[h]+ min(go(arr,l+1,h-1,dp), go(arr,l,h-2,dp));
        return dp[l][h]=max(low_take, high_take);
        
        
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
