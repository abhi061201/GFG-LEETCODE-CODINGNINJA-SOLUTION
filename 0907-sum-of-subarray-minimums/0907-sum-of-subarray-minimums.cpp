class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int>left(n), right(n);
        stack<pair<int,int>>st_left;
        int mod= 1e9+7;
        
        // left array denote
        // left m se hum kitne subarray include krr skte h khudko count krke
        for(int i=0; i<n ; i++)
        {
            int count=1;
            while(!st_left.empty() && st_left.top().first > arr[i])
            {
                count+= st_left.top().second;
                st_left.pop();
            }
            st_left.push({arr[i], count});
            left[i] = count%mod;
        }
        
        // right array denote
        // k apne aap ko include krke hum right se kitne subarray le skte h
        stack<pair<int,int>>st;
        for(int i=n-1; i>=0 ;i--)
        {
            int count=1;
            while(!st.empty() && st.top().first >=arr[i])
            {
                count+= st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            right[i]= count%mod;
        }
        long long int ans=0;
        for(int i=0; i<n; i++)
        {
            long long int temp= left[i]%mod;
            temp = (temp*right[i])%mod;
            temp = (temp*arr[i])%mod;
            ans = (ans+ temp)%mod;
        }
        
        return ans;
    }
};