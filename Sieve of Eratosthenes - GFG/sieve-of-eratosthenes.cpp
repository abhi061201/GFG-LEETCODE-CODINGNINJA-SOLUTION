//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int>ans;
        vector<int>prime(N+1,1) ;
        seive(prime);
        for(int i=0; i<=N; i++){
            if(prime[i])ans.push_back(i);
        }
        return ans;
    }
    
    void seive(vector<int>&prime){
        int n= prime.size();
        prime[0]=prime[1]=0;
        for(int i= 2 ; i*i <n ;i++)
        {
            if(prime[i])
            {
                for(int j= 2*i; j<n; j+=i){
                    prime[j]=0;
                }
            }
        }
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends