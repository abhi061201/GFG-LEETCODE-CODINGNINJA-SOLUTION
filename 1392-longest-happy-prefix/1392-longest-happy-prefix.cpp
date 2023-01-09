class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length(),i=1;
        vector<int>lps(n,0);
        while(i<n)
        {
            if(s[i]== s[lps[i-1]])
            {
                lps[i]= 1+lps[i-1];
            }
            else
            {
                int j= lps[i-1];
                while(j>0 && s[i]!=s[j])
                {
                    j= lps[j-1];
                }
                if(s[j]==s[i])j++;
                lps[i]=j;
            }
            i++;
        }
        int maxlength= lps[n-1];
        // cout<<maxlength;
         return s.substr(0,maxlength);
        return "";
        
    }
};