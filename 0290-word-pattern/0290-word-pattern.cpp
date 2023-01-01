class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        vector<string>v;
        for(auto it: s)
        {
            if(it==' ')
            {
                v.push_back(temp);
                temp="";
            }
            else temp.push_back(it);
            
        }
    
        v.push_back(temp);
        // for(auto it: v)cout<<it<<"\n";
        bool flag1=true, flag2=true;
        int n= pattern.length();
        if(n!= v.size())return 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++){
                if(pattern[i]==pattern[j] && v[i]!=v[j] )
                {
                    flag1=false;                                         
                    
                }
                
                 if(v[i]==v[j] &&pattern[i]!=pattern[j]  )
                {
                    flag2=false;                                         
                    
                }
            }
        }
        
        
        return flag1& flag2;
    }
};