class Solution {
public:
    int maxPoints(vector<vector<int>>& po) {
        int n= po.size();
        if(n<=2)return n;
        int maxi=2;
        for(int i=0; i<n-1;i++)
        {
            map<double, int>mp;
            for(int j= i+1; j<n;j++)
            {
                
                if(po[j][1]==po[i][1])mp[-90]++;
                else {
                    double x= (double)(po[j][0]-po[i][0])/ (double)(po[j][1]-po[i][1]);
                    mp[x]++;
                }
                
            }
            for(auto it: mp)
            {
                maxi= max(maxi, it.second+1);
            }
        }
        
        return maxi;
    }
};