// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  int sumi(int arr[],int n){
      int sum=0;
      for(int i=0 ;i<n ;i++){
          sum+=arr[i];
      }
      return sum;
      
  }
	int minDifference(int arr[], int n)  { 
	    
	    // Your code goes here
	    int sum= sumi(arr,n);
	    int m= sum/2;
	    
	    vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,0));
	    dp[0][0]=1;
	    for(int i=1 ;i<=n ;i++){
	        for(int j=0 ;j<=sum/2 ;j++){
	            if(j>=arr[i-1])
	            dp[i][j]= dp[i-1][j]|| dp[i-1][j-arr[i-1]];
	            else 
	            dp[i][j]= dp[i-1][j];
	        }
	    }
	    int x=sum/2;
	    while(x>=0 && dp[n][x]==false){
	        x--;
	    }
	    return sum-2*x;
	    
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
