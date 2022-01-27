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
   ll n;
   cin>>n;
   vector <int> v1(n);
   vector <int> v2(n);
  
   for(int i=0 ;i<n ;i++){
        cin>>v1[i];
        
   }
   for(int i=0 ;i<n ;i++){
        cin>>v2[i];
        
   }
  for(int i=0 ;i<n ;i++){
       if(v1[i]<v2[i]){
            swap(v1[i],v2[i]);
       }
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  cout<<v1[n-1]*v2[n-1]<<"\n";
   
   
   
}
return 0;
}
