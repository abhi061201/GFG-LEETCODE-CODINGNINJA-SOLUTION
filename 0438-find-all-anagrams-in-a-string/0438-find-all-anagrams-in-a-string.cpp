class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>pchar(26,0);
        for(auto it:p)pchar[it-'a']++;
        int n = s.length(), m = p.length(); string temp;
        for(int i=0; i<n; i++)
        {
             temp= s.substr(i,m);
            if(check(temp,pchar))ans.push_back(i);
            
        }
        return ans;
    }
    
    int check(string &temp, vector<int>&pchar)
    {
        vector<int>v(26,0);
        for(auto it:temp)v[it-'a']++;
        return v==pchar;
        
    }
};