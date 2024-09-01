class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n= nums.size();
        vector<string> v(n);
        for(int i=0; i<n;i++){
            v[i] = to_string(nums[i]);
        }
        
        int cnt =0;
        for(int i=0 ; i<n;i++){
            for(int j=i+1; j<n; j++){
                if(checkEqual(v[i], v[j]))cnt++;
            }
        }
        return cnt;
        
        
    }
    
    bool checkEqual(string x, string y){
        int diff = 0, n = x.length(), m= y.length();
        
        while(n< m ){
            x= "0"+x;
            n++;
        }
        while(m<n){y= "0"+y; m++;}
        
        unordered_map<char,int>mp1,mp2;
        for(int i=0; i<m; i++){
            diff+= x[i]!=y[i];
            mp1[x[i]]++;
            mp2[y[i]]++;
        }
        
        if(mp1 == mp2 && diff<=2)return 1;
        
        return 0;
        
    }
};