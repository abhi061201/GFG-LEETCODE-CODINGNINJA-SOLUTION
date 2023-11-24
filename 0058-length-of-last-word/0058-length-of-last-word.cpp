class Solution {
public:
    int lengthOfLastWord(string s) {
        int n= s.length();
        int j= n-1 , ans=0;
        while(j>=0 &&s[j]==' ')
        {
            j--;
        }
    
        while(j>=0&& s[j]!=' ')
        {
            j--;
            ans++;
        }
        return ans;
        
    }
};