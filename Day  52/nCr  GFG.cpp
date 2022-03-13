// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define M 1000000007
class Solution{
public:
    int nCr(int n, int r){
      
      if(n<r)return 0;
      if(n-r>r)r=n-r;
      vector<int>fact(n+1, 0);
      fact[0]=1;
      for(int i=1 ; i<=n ; i++){
          
          for(int j= min(r,i ) ; j>=1 ;j--){
              fact[j]= (fact[j]+fact[j-1])%M;
              
          }
      }
      return fact[r];
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
