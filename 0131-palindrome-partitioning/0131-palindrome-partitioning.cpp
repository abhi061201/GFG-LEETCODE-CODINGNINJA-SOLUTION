class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        go(0, s, temp);
        
        return ans;
    }
    
    void go(int start, string &s, vector<string>&temp)
    {
        if(start==s.length())ans.push_back(temp);
        string tempstr;
        for(int i=start; i<s.length(); i++)
        {
            tempstr.push_back(s[i]);
            if(pali(tempstr))
            {
                temp.push_back(tempstr);
                go(i+1, s, temp);
                temp.pop_back();
            }
        }
    }
    bool pali(string &s)
    {
        int i=0, j = s.length()-1;
        while(i<j)
        {
            if(s[i]!= s[j])return 0;
            i++;j--;
        }
        return 1;
    }
};