//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <boost/math/common_factor.hpp>
#define ll long long int
#define mod 1000000007
class Solution {
  public:
    int lcmOfArray(int n , int nums[]) {
        ll _lcm=nums[0];
        for(int i=1;i<n;i++)
        {
            
            _lcm=boost::math::lcm(_lcm,(ll)nums[i])%mod;
        }
        return _lcm;
    }
    int gcd(int a, int b)
    {
        if(a>b)swap(a,b);
        if(a==0)return b;
        return gcd(b%a, a);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.lcmOfArray(N,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends