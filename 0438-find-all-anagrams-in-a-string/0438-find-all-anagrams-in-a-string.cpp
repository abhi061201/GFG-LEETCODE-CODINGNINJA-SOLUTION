class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>pchar(26,0), v(26,0);
        for(auto it:p)pchar[it-'a']++;
        int n = s.length(), m = p.length(), j=0; string temp;
        for(int i=0; i<n; i++)
        {
            v[s[i]-'a']++;
            if(i-j+1 > m)
            {
                v[s[j]-'a']--;
                j++;
            }
            if(v==pchar)ans.push_back(j);
        }
        return ans;
    }
    
    
};