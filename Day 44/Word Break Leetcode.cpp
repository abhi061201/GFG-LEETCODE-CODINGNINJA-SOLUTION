class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict;
        for(auto it : wordDict){
            dict.insert(it);
        }
        vector<int>dp(s.length()+1,-1);
        return go(0,s,dict,dp);
        
    }
    bool go(int start,string s, unordered_set<string>&dict,  vector<int>&dp){
        
        if(start==s.length())return true;
        if(dp[start]!=-1)return dp[start];
        string res="";
        for(int i=start ;i<s.size();i++){
            res.push_back(s[i]);
            if(dict.find(res)!=dict.end()&& go(i+1, s,dict,dp)){
                return dp[start]= true;
            }
        }
        return dp[start]= false;
        
    }
};
