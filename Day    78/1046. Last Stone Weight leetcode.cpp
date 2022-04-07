class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n= stones.size();
        for(int i=1 ; i<n ; i++){
            sort(stones.begin(), stones.end());
            stones[n-1]-=stones[n-2];
            stones[n-2]=0;
        }
        return stones[n-1];
        
    }
};
