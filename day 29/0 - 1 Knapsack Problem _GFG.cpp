// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
     
     vector<vector<int>>dp(n,vector<int>(W+1,-1));
     vector<int>knap;
     return kp(0,wt,val,W,n,knap,dp);
       
    }
    int kp(  int index,int weight[],  int profit[],int W,int n,vector<int>&knapsack, vector<vector<int>>&dp){
    
    if(index==n || W==0)return 0;
    
// for(auto it : knapsack){
//    cout<<"("<<weight[it]<<","<<profit[it]<<") ";
// }
// cout<<"\n";
if(dp[index][W]!=-1)return dp[index][W];
    int exclude = kp(index+1,weight,profit,W,n,knapsack,dp);
    int include= INT_MIN;
    if(weight[index]<=W){
        knapsack.push_back(index);
        include= profit[index]+kp(index+1,weight,profit,W-weight[index],n,knapsack,dp);
        knapsack.pop_back();
    }
 return dp[index][W]=max(exclude,include);
}
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
