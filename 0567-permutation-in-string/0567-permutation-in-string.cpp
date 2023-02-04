class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 
        vector<int>v1(26,0),v2;
        v1= sortString(s1);
        
        string temp;
        int n= s2.length(), m= s1.length();
        unordered_set<char>se(s2.begin(), s2.end());
        for(int i=0; i<=n-m; i++)
        {
            if(se.find(s2[i])!=se.end())
            {
                temp= s2.substr(i,m);
                
                v2= sortString(temp);
                
                if(v2==v1)return 1;
            }
        }
        return 0;
    }
    vector<int> sortString(string s)
    {
        vector<int>v(26,0);
        for(auto it: s)
        {
            v[it-'a']++;
        }
       
        return v;
    }
};