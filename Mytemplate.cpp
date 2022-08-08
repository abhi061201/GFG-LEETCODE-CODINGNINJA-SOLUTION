#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// function to count unique elements from a vector
ll mix_sum_window_size_k(vector<ll>v, ll k){
     ll windowSum= 0, n= v.size(), totalSum=0;
     for(int i=0 ; i<n ; i++){
          if(i<n-k)windowSum+=v[i];
          totalSum+= v[i];
     }
     ll j=n-k; ll temp=windowSum;
     
     while(j<n){
          temp+=v[j]-v[j-(n-k)];
          windowSum= min(windowSum,temp );
          j++;
     }
     return totalSum- windowSum;
     
}
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
    // for josephus put k-- first
ll josephus(vector<ll>&v ,ll k, ll index){
    if(v.size()==1)return v[0];
    
    index= (index+k)%v.size();
    v.erase(v.begin()+index);
    return josephus(v, k, index);
}

void solve(){
     ll t;
     cin>>t;
     while(t--){
          
     }
}    
    
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
solve();

return 0;
}
