class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int>mp;
        for(auto it : nums){
            if(mp.find(it) == mp.end()){
                mp[it]=1;
            }
            else mp[it]++;
            
        }
        vector<pair<int, int>>v;
        for(auto it : mp){
            v.push_back({it.second, it.first});
            
        }
        sort(v.begin(), v.end());
        vector<int > ans;
        int n= v.size();
         for(auto it : mp){
            cout<<it.first<<" , "<<it.second<<endl;
            
        }
        reverse(v.begin(), v.end());
        for(int i=0 ; i<k ; i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
        
    }
};
