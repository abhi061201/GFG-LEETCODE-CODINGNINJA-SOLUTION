// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>v;
	    int n= nums.size();
	    for(int i=0 ;i< n ;i++){
	        v.push_back({nums[i],i});
	    }
	    int ans=0;
	    sort(v.begin(),v.end());
	    vector<int >vis(n,0);
	    for(int i=0 ;i< n ;i++){
	        
	        if(!vis[i] && v[i].second!=i){
	            int cnt=0;
	           // vis[i]=1;
	            int j=i;
	            while(!vis[j]){
	                cnt++;
	                vis[j]=1;
	                j= v[j].second;
	            }
	            if(cnt>0)ans+=cnt-1;
	            
	        }
	       
	    }
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
