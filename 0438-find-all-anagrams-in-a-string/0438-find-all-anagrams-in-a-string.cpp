class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n= s.length(), m= p.length();
        vector<int>ans;
        
        vector<int>pa(26,0);
        for(auto it:p)pa[it-'a']++;
        for(int i=0; i<n; i++)
        {
            string str= s.substr(i,m);
            
            if(checkanagram(str,pa))ans.push_back(i);
        }
        return ans;
    }
    int checkanagram(string &s, vector<int>pa)
    {
        for(auto it:s)pa[it-'a']--;
        for(auto it:pa)if(it!=0)return 0;
        return 1;
    }
};