class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>mp;
        for(auto it: nums)mp[it]++;
        
        priority_queue<pair<int,int>>pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        
        vector<int>ans;
        while(!pq.empty() &&k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
        
    }
};