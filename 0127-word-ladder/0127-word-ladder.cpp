class Solution {
public:
    int ladderLength(string b, string en, vector<string>& wordList) {
        set<string >se(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({b,1});
        se.erase(b);
        while(!q.empty())
        {
            string str= q.front().first;
            int curlen= q.front().second;
            q.pop();
            // cout<<str<<endl;
            if(str==en)return curlen;
            
            for(int i=0; i<str.length(); i++)
            {
                string tempstr = str;
                for(int j=0 ; j<26; j++)
                {
                    tempstr[i]= j+'a';
                    if(se.find(tempstr) != se.end())
                    {
                        
                        q.push({tempstr,1+curlen});
                        se.erase(tempstr);
                    }
                }
            }
        }
        return 0;
    }
};