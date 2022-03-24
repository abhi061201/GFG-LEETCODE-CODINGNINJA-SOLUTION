class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= s.length();
        int m= t.length();
        return go(s,t,n-1,m-1);
            
    }
    
    int go(string s, string t, int i, int j){
        
        if(i<0)return 1;
        if(j<0 && i>=0)return 0;
        if(s[i]==t[j])return go(s,t, i-1, j-1);
        return go(s, t, i, j-1);
    }
};
