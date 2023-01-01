class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n= s.length();
        int m= s.length();
        if(n!=m)return 0;
        int mp1[256]={0};
        int mp2[256]= {0};
        for(int i=0; i<n; i++)
        {
            if(mp1[s[i]]!= mp2[t[i]])return 0;
            mp1[s[i]]= i+1;
            mp2[t[i]]= i+1;
        }
        return 1;
    }
};