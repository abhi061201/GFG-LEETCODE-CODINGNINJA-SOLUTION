class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n= num.size(), carry=0 , i=n-1, lx, ly, temp;
        vector<int>ans;
        while(i>=0||k>0)
        {
            lx= i>=0?num[i]:0;
            ly= k%10;
            temp= lx+ly+carry;
            ans.push_back(temp%10);
            carry= temp/10;
            k=k/10;
            i--;
        }
        if(carry)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};