class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dic) {
        
        vector<string>ans;
        for(int i=0; i<queries.size(); i++)
        {
            if(check(queries[i], dic))ans.push_back(queries[i]);
        }
        return ans;
        
    }
    bool check(string &s, vector<string>& dic)
    {
        
       for(auto it: dic)
       {
           if(it.length()==s.length())
           {
                int temp=0;   
               for(int i=0; i<s.length() ; i++)
               {
                   if(s[i]!= it[i])temp++;
                   if(temp>2)break;
               }
               if(temp<=2)return 1;
           }
       }
        return 0;
    }
};