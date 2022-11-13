class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        for(auto it: s)
        {
            if(it!= ' ')
            {
                temp.push_back(it);
                
            }
            else if(temp.size()>0)
            {
                reverse(temp);
                ans+= temp+ " ";
                temp= "";
                
            }
        }
        reverse(temp);
        if(temp.size()>0)ans+= temp;
        reverse(ans);
        if(ans[0]==' ')ans= ans.substr(1, ans.size()-1);
        return ans;
    
    }
    void reverse(string &s)
    {
        int i=0, j= s.length()-1;
        while(i<j)
        {
            char c= s[i];
            s[i]= s[j];
            s[j]= c;
            i++;
            j--;
        }
        
    }
};