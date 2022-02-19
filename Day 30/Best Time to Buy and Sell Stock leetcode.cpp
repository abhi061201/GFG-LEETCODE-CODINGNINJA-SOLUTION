// TC=O(N)
//SC=constant;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int n= p.size();
        int m_ele=INT_MAX;
        int pro=0;
        for(int i=0 ;i<n ;i++){
            m_ele=min(m_ele,p[i]);
            pro= max(pro,p[i]-m_ele);
        }
        return pro;
    }
};
