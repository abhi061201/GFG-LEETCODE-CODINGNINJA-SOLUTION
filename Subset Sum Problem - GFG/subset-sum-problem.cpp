//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n= arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return go(n-1, arr, sum, 0, dp);
    }
    bool go(int i,vector<int>&arr, int sum, int cursum, vector<vector<int>>&dp )
    {
        if(cursum> sum)return 0;
        if(sum==cursum)return 1;
        if(i<0)return sum==cursum;
        if(dp[i][cursum]!=-1)return dp[i][cursum];
        int take=0, n_take=0;
        take= go(i-1, arr, sum, cursum+arr[i] , dp);
        n_take= go(i-1, arr, sum, cursum, dp);
        return dp[i][cursum]= take| n_take;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends