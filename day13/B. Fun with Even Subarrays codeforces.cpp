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
    }
}
// function to check if a no.is power of 2 or not
bool power_2(int x){
       return x&& (!(x&(x-1)));
}    
int main(){

ll t;
    cin>>t;
while(t-->0){
     ll n;
     cin>>n;
     vector<int>v(n+1);
     for(int i=n ;i>0 ;i--){
         cin>>v[i];
     }
     
     int ans=0;
     
     int i=1;
     while(i<n){
     while(v[1]==v[i+1] ){
         i++;
         }
         if(i>=n)break;
         i=i+i;
         ans++;
         
     }
     cout<<ans<<"\n";
}
return 0;
}
