class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n= s1.length(), m= s2.length(), i=0, j=n-1;
        vector<int>s1h(26,0);
        for(auto it : s1){
            s1h[it-'a']++;
        }
    
        while(i+n<=m){
            
            string temp= s2.substr(i,n);
            vector<int>temph(26,0);
            for(auto it : temp){
                temph[it-'a']++;
            }
            bool ans=true;
            for(int k=0 ; k<26 ; k++ ){
                if(temph[k]!=s1h[k])ans=false;
            }
            if(ans)return 1;
           
            i++;           
        }
        return 0;
        
    }
};
