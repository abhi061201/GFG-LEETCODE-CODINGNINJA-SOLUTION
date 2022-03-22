class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans(n,'a');
        
        k=k-n;
        int i=n-1;
        while(k>=26){
            ans[i]=char('a'+25);
            i--;
            k=k+1-26;
        }
        ans[i]= char('a'+k);
        
        return ans;
    }
};
