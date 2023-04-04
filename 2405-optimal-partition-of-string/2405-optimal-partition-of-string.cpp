class Solution {
public:
    int partitionString(string s) {
        int n= s.length();
        
        int count=0;
        set<char>se;
        for(int i=0; i<n;i++)
        {
            if(se.find(s[i])!= se.end())
            {
                count++;
                se.clear();
            }
            se.insert(s[i]);
        }
        
        return count+1;
    }
};