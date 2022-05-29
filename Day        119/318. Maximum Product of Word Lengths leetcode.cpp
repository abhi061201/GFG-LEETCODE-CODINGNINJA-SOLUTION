#include <bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n= words.size();
        int ans=0;
        vector<multiset<char>>v(n);
       
       for(int i=0 ; i<n ; i++){
          string s=words[i];
           for(auto it : s){
               v[i].insert(it);
           }
       }
        
        for(int i=0 ; i<n; i++){
            for(int j=i+1 ; j<n ; j++){
                if(!iscommon(v[i],v[j])){
                   int k= v[i].size()*v[j].size();
                      ans= max(ans,k);
                }
              
            }
        }
        
        return ans;
        
        
    }
    bool iscommon(multiset<char> &s1,multiset<char>&s2){
        
        for(auto it : s1){
            if(s2.find(it)!=s2.end())return 1;
        }
        
        
        return 0;
        
    }
};
