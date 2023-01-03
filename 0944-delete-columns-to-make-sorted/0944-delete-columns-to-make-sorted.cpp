class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n= strs.size();
        int strl= strs[0].length();
        int count=0;
        for(int j=0; j<strl; j++)
        {
            string temp;
            for(int i=0; i<n; i++)
            {
                temp.push_back(strs[i][j]);
            }
            string str= temp;
            sort(temp.begin(), temp.end());
            count+= str!=temp;
        }
        return count;
        
    }
};