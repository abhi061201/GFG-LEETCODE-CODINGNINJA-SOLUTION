class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        vector<int>vis(n,0);
        return go(start, arr,vis);
    }
    int go(int i, vector<int>&arr,vector<int>&vis)
    {
        if(arr[i]==0)return 1;
        vis[i]=1;
        bool left=0, right=0;
        if(i-arr[i] >=0 && i-arr[i]<arr.size() && !vis[i-arr[i]] )left= go(i-arr[i],arr,vis );
        if(i+arr[i] >=0 && i+arr[i]<arr.size() && !vis[i+arr[i]] )right= go(i+arr[i],arr,vis );
        return left| right;
    }
};