class Solution {
public:
    int strStr(string hs, string ne) {
        int n= hs.length(), m= ne.length();
        vector<int>lps(n+m+1,0);
        string temp= ne+"&"+hs;
        for(int i=1; i<n+m+1; i++)
        {
            if(temp[i]==temp[lps[i-1]]){
                lps[i]= 1+ lps[i-1];
            }
            else {
                int j= lps[i-1];
                while(j>0 && temp[i]!= temp[j])
                {
                    j= lps[j-1];
                }
                if(temp[i]==temp[j])j++;
                lps[i]= j;
            }
        }
        
        for(int i=0; i<n+m+1; i++)if(lps[i]==m)return i-2*m;
        return -1;
        
    }
};