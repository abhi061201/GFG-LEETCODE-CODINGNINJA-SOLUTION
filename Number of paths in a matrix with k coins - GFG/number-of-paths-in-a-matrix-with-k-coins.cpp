//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long int
class Solution {
public:
    
    ll go(ll i, ll j,ll k,  vector<vector<int>> &arr,vector<vector<vector<ll>>>&dp)
    {
        if(i==0 && j==0 && k==1)return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long int ans=0;
        if(i-1>=0 && arr[i][j]<=k)ans+= go(i-1, j,k-arr[i][j], arr,dp);
        if(j-1>=0 && arr[i][j]<=k)ans+= go(i, j-1,k-arr[i][j], arr,dp);
        return dp[i][j][k]=ans;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(k+1,-1)));
        return go(n-1, n-1, k, arr, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends