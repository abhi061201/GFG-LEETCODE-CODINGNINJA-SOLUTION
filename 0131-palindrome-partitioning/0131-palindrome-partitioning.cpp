class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        go(0, s, temp);
        return ans;
    }
    void go(int i, string &s, vector<string>&temp)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
        }
        string str;
        for(int start= i; start<s.length(); start++)
        {
            str.push_back(s[start]);
            if(ispali(str))
            {
                temp.push_back(str);
                go(start+1, s, temp);
                temp.pop_back();
            }
        }
    }
    bool ispali(string &s)
    {
        int i=0, j = s.length()-1;
        while(i<j)
        {
            if(s[i++]!= s[j--])return 0;
        }
        return 1;
    }
};