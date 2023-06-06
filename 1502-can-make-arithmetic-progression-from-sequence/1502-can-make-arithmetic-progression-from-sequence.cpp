class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        if(n==2)return 1;
        for(int i=1; i<n-1; i++)if(arr[i]-arr[i-1] != arr[i+1]-arr[i])return false;
        return 1;
    }
};