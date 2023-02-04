class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        s1= sortString(s1);
        // sort(s1.begin(), s1.end());
        string temp;
        int n= s2.length(), m= s1.length();
        unordered_set<char>se(s2.begin(), s2.end());
        for(int i=0; i<=n-m; i++)
        {
            if(se.find(s2[i])!=se.end())
            {
                temp= s2.substr(i,m);
                temp= sortString(temp);
                // sort(temp.begin(), temp.end());
                if(temp==s1)return 1;
            }
        }
        return 0;
    }
    string sortString(string s)
    {
        vector<int>v(26,0);
        for(auto it: s)
        {
            v[it-'a']++;
        }
        s="";
        for(int i=0; i<26; i++)
        {
            int k= v[i];
            while(k--)
            {
                s.push_back(i+'a');
            }
        }
        return s;
    }
};