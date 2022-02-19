// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return go(arr,0,n-2,dp);
        
    }
    
int go(int arr[], int start,int end,vector<vector<int>>&dp){

if(start>=end)return 0;
if(dp[start][end]!=-1)return dp[start][end];
int ans=INT_MAX;
for(int k=start;k<end;k++){
    int first= go(arr,start,k,dp);
    int second= go(arr,k+1,end,dp);
    ans= min(ans,first+second+arr[start]*arr[k+1]*arr[end+1]);
}
return dp[start][end]=ans;


}
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
