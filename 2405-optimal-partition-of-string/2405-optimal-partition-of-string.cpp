class Solution {
public:
    int partitionString(string s) {
        int n= s.length();
        
        int count=0;
        vector<int>v(26,0);
        for(int i=0; i<n;i++)
        {
            if(v[s[i]-'a'])
            {
                count++;
                vector<int>temp(26,0);
                v=temp;
            }
            v[s[i]-'a']=1;
        }
        
        return count+1;
    }
};