class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it: s)
            mp[it]++;
        
        vector<pair<int,char>>v;
        for(auto it: mp)v.push_back({it.second, it.first});
        sort(v.begin(), v.end(), greater<>());
        string ans;
        for(auto it: v)
        {
            int k=it.first;
            while(k--)ans.push_back(it.second);
        }
        return ans;
    }
};