class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        go(0,s,temp);
        return ans;
    }
    void go(int i, string & s, vector<string>&temp)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return ;
        }
        string str;
        for(int j=i; j<s.length();j++)
        {
            str.push_back(s[j]);
            if(ispalli(str))
            {
                temp.push_back(str);
                go(j+1, s, temp);
                temp.pop_back();
            }
       
        }
    }
    bool ispalli(string &s)
    {
        int i=0, j= s.length()-1;
        while(i<j)
        {
            if(s[i++]!= s[j--])return 0;
        }
        return 1;
    }
};