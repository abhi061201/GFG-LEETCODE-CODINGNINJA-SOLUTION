// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &B) {
        //code here
        
        unordered_set<string>set;
        for(auto it : B){
            set.insert(it);
        }
        vector<int>dp(s.size(),-1);
        return go(0,s,set,dp);
        
    }
    bool go(int i, string s,unordered_set<string>&set,  vector<int>&dp){
        
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        string res;
        for(int start=i; start<s.size(); start++){
            res.push_back(s[start]);
            if(set.find(res)!=set.end() && go(start+1,s,set,dp)){
                return dp[i]= true;
            }
        }
        
        return dp[i]=false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends
