#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int countelements(vector<ll> v){
    
    int n= v.size();
    unordered_map <ll ,ll> mp;
    for(auto x:v){ // auto keyword is used for automatic typename 
        mp[x]++;
    }
    
    
    /*
    if we want to print elements also */
        
        for(auto y :mp){
            
            cout<<y.first <<" "<< y.second<<"\n";
            
        }
        

  
    return mp.size();
    
}

int main() {

vector<long long >v;
v={1,1,1,1,1,1,1,1};

cout<<countelements(v);


	return 0;
}
