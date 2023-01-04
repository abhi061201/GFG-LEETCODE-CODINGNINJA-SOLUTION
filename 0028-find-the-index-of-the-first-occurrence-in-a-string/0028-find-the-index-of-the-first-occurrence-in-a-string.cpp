class Solution {
public:
    int strStr(string hs, string ne) {
        int n= hs.length();
        int m= ne.length();
        string sub;
        for(int i=0; i<=n-m; i++)
        {   
             if(ne[0]==hs[i])
             {
                 sub= hs.substr(i,m);
                 if(sub==ne)return i;
             }
        }
        
        return -1;
    }
};