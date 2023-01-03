class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n= strs.size();
        int strl= strs[0].length();
        int count=0;
        for(int j=0; j<strl; j++)
        {
            string temp;
            for(int i=0; i<n-1; i++)
            {
                if(strs[i][j] > strs[i+1][j])
                {
                    count++;
                    break;
                }
            }
            
        }
        return count;
        
    }
};