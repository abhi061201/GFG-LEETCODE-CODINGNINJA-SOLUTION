#include <bits/stdc++.h>
#define ll long long
// #define f(i,x,1) for(int i=0 ;i<m  ;i++)
// #define f(j,x,1) for(int j=0 ;i<n  ;i++)
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

ll m,n;
cin>>m>>n;

ll b[m][n];

for(int i=0 ;i<m ;i++){
    for(int j=0 ;j<n ;j++){
        cin>>b[i][j];
        
    }
}
ll a[m][n];

for(int i=0 ;i<m ;i++){
    for(int j=0 ;j<n ;j++){
        a[i][j]=1;
        
    }
}

for(int i=0 ;i<m ;i++){
    for(int j=0 ;j<n ;j++){
      if(b[i][j]==0){
          for(int k=0 ;k<n ;k++)a[i][k]=0;
          for(int k=0 ;k<m ;k++)a[k][j]=0;
      }
        
    }
}
int ans=1;
for(int i=0 ;i<m ;i++){
    for(int j=0 ;j<n ;j++){
        
        if(b[i][j]==1){
            int flag=0;
           if(a[i][j]!=1){
               for(int k=0 ;k<m ;k++)if(a[k][j]==1)flag=1;
               for(int k=0 ;k<n ;k++)if(a[i][k]==1)flag=1;
             if(!flag){
                 ans=0;
                 break;
             }
               
           }
           
        }
    
    }
}



if(ans){
    cout<<"YES\n";
    for(int i=0 ;i<m ;i++){
    for(int j=0 ;j<n ;j++){
     cout<<a[i][j]<<" ";
        
    }
    cout<<"\n";
}
}

else cout<<"NO\n";



return 0;
}
