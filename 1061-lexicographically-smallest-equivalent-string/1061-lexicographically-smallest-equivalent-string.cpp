// TC = O(m+n)*26
// SC = O(26);

class Solution {
public:
    vector<int>par;
    int getpar(int x)
    {
        if(x== par[x])return x;
        return par[x]= getpar(par[x]);
    }
    
    void uniongr(int a, int b)
    {
        int pa= getpar(a);
        int pb= getpar(b);
        if(pa!=pb)
        {
            if(pa<pb)
            {
                par[pb]= pa;
            }
            else {
                par[pa]= pb;
            }
        }
    }
    void go(string &s1, string &s2)
    {
        vector<int>Par(26,0);
        for(int i=0; i<26; i++)Par[i]=i;
        par= Par;
        int n= s1.length();
        for(int i=0; i<n; i++)
        {
            uniongr(s1[i]-'a', s2[i]-'a');
        }
        
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
    
        go(s1, s2);
        int x,n= baseStr.length();
        string ans;
//         char c='a';
//         for(int i=0; i<26; i++)
//         {
//             cout<<c<<" : "<<getpar(c-'a')<<endl;
//             c++;
//         }
            
        for(int i=0; i<n;i++)
        {
            x= getpar(baseStr[i]-'a');
            ans.push_back(x+'a');
        }
        return ans;
    }
};