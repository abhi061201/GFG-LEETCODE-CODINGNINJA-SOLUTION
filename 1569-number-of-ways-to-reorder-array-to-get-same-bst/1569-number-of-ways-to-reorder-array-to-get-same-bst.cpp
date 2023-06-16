#define ll long long

class Solution {
    int mod = 1e9+7;
    vector<vector<ll>> pascal;
    
    ll numOfWaysHelp(vector<int>& nums) {
        if(nums.size() <= 2) return 1;

        vector<int> leftSubtree, rightSubtree;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if( nums[i] < nums[0] ) leftSubtree.push_back(nums[i]);
            else rightSubtree.push_back(nums[i]);
        }

        ll leftWays = numOfWaysHelp(leftSubtree), rightWays = numOfWaysHelp(rightSubtree);
        int leftLen = leftSubtree.size(), rightLen = rightSubtree.size();
        return (pascal[n-1][leftLen] * ((leftWays * rightWays)%mod))%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        // calculate pascal triangle for calculating nCr in O(1)
        int n = nums.size();
        pascal.resize(n+1);
        for(int i=0; i<n+1; i++){
            pascal[i] = vector<ll>(i+1, 1);
            for(int j=1; j<i; j++)
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j] )%mod;
        }
        
        return numOfWaysHelp(nums)%mod - 1;
    }
};