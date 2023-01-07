class Solution {
public:
    int strStr(string hs, string ne) {
        int n= hs.length(), m= ne.length();
        vector<int>lps(n+m+1,0);
        string temp= ne+"&"+hs;
        int i=1,j=0;
        while(i<n+m+1)
        {
            
            if(temp[i]==temp[j]){
                j++;
                lps[i]= j;
                i++;
            }
            else {
                if(j>0)
                {
                    j= lps[j-1];
                }
                else{
                    lps[i]= 0;
                    i++;
                }
            }
        }
        
        for(int i=0; i<n+m+1; i++)if(lps[i]==m)return i-2*m;
        return -1;
        
    }
};