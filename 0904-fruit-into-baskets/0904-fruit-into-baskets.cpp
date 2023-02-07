class Solution {
public:
    int totalFruit(vector<int>& fr) {
        int n= fr.size(), maxi=0;
        map<int,int>mp;
        for(int i=0, j=0; i<n; i++)
        {
            mp[fr[i]]++;
            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fr[j]]--;
                    if(mp[fr[j]]==0)mp.erase(fr[j]);
                    j++;
                }
                
            }
            maxi= max(maxi,i-j+1);
        }
        return maxi;
    }
};