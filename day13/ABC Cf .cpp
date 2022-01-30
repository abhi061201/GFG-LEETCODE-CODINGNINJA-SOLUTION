#include <bits/stdc++.h>
#define ll long long
using namespace std;

// function to count unique elements from a vector
int uniqueele(vector<ll> v)
{

    int n = v.size();
    unordered_map<ll, ll> mp;
    for (auto x : v)
    { // auto keyword is used for automatic typename
        mp[x]++;
    }
    //if we want to print elements also 
    //         for(auto y :mp){
    //             cout<<y.first <<" "<< y.second<<"\n";
    //         }
    return mp.size();
}

// function to check a no. is palindrome or not
int ispalindrome(string s){
    int len= s.length();
    
    for(int i=0 ;i<len/2 ;i++){
        if(s[i]!= s[len-i-1])return false;
    }}
    
int main(){

ll t;
    cin>>t;
while(t-->0){
    ll n ;
    cin>>n;
    string s;
    cin>>s;
    if(n>2)cout<<"NO\n";
    else {
         
        if(s[0]==s[1])cout<<"NO\n";
         else cout<<"YES\n";
    }
    
    
    
}
return 0;
}
