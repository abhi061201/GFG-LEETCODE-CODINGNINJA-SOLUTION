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
ios_base::sync_with_stdio(false);cin.tie(NULL);
ll t;
    cin>>t;
while(t-->0){
    
   ll x, y;
   cin>>x>>y;
   
   if(x==0 && y==0)cout<<"0\n";
   else {
        
        int i= min(x, y);
        int ans=0;
        while(i*i <= x*x+ y*y){
             if(i*i == x*x+ y*y){
                  ans=1;
                  break;
             }
             i++;
        }
        if(ans==1)cout<<"1\n";
        else cout<<"2\n";
        
        
   }
    
}
return 0;
}
