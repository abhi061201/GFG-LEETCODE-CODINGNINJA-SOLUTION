
// TC= O(n) // as only one function call will be executed for one element;
// SC= O(n)// auxilary stack space  +O(n)// vector space .


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
#define N 1000000007
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
       vector<ll>dp(n+1,-1);
       dp[0]=0;
       dp[1]=1;
       for(int i=2 ;i<=n ;i++){
           dp[i]= (dp[i-1]+dp[i-2])%N;
           
       }
       return dp[n]%N;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends



// Bottom Up Approach more optimised in terms of space ;
TC= O(N);
SC= O(1);

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
#define N 1000000007
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
     
      if(n<=1)return n;
      ll p1= 1;
      ll p2= 0;
      
      for(int i=2 ;i<=n ;i++){
          ll curi=( p1 +p2)%N;
          p2= p1;
          p1= curi;
          
      }
        return p1%N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends





//
