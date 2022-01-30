#include <bits/stdc++.h>
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        vector<pair<int,pair<int,int>>> v;
        int n_0=0;
        int n_1=0;
        int n= nums.size();
        for(int i=0 ;i<n;i++){
            if(nums[i]==1)n_1++;
            
        }
        n_0=0;
        int score= n_1;
        vector <int> ans;
      int x= score;
        int ms=score;
        v.push_back({score ,{0,n_1}});
        for(int i=0 ;i<n ;i++){
            if(nums[i]==0){
                n_0++;
            }
            else if(nums[i]==1){n_1--;}
            score = n_0+n_1;
            v.push_back({score,{n_0,n_1}});
            ms= max(score,ms);
        }
        
       for(int i=0 ;i<=n ;i++){
           if(v[i].first==ms)ans.push_back(i);
       }
        
        // if(x==ms)ans.push_back(0);
        return ans;
        
        
    }
};
