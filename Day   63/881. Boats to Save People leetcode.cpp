class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        int boat=0;
        int n= p.size();
        vector<int>vis(n,0);
        sort(p.begin(), p.end());
        int i=0 , j=n-1;
        while(i<j){
            boat++;
            if(p[i]+p[j]<=limit){
                i++;j--;
            }
            else {
                j--;
            }
            
        }
        if(i==j)boat++;
        return boat;
    }
};
