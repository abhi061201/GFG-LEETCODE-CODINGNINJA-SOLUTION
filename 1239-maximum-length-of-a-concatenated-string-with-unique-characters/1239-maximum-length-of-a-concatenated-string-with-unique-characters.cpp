class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n= arr.size();
        string temp;
        return go(0, arr, temp);
    }
    int go(int i, vector<string>&arr, string temp)
    {
        if(i==arr.size())
        {
            return temp.size();
        }
        int take=0, n_take=0;
        if(unique(temp+arr[i]))take= go(i+1, arr, temp+arr[i]);
        n_take= go(i+1, arr, temp);
        return max(take, n_take);
    }
    int unique(string str)
    {
        map<char, int >mp;
        for(auto it: str)
        {
            if(mp.find(it)!= mp.end())
                return 0;
            mp[it]=1;
        }
        return 1;
    }
    
};