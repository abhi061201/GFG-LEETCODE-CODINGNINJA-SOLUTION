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
    ll n,k;
    cin>>n>>k;
    vector <int> v;
    
    if(n==2 && k==2){
    v.push_back(1);
    v.push_back(2);
    }
    else if(k>=2){
        for(int i=1 ;i<=k-1 ;i++){
            v.push_back(i);
        }
        for(int i= n ;i>k-1 ;i--)v.push_back(i);
    }
    else if(n==1 && k==1)v.push_back(1);
    else {
        v.push_back(-1);
    }
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<"\n";
}
return 0;
}
