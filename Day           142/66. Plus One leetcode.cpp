class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry=0;
        int n= digits.size();
        
        for(int i=n-1; i>=0 ; i--){
           
            if(i==n-1){
                carry= (digits[i]+1)/10;
             digits[i]= (digits[i]+1)%10;
            }
            
            else{
                int x=digits[i];
            digits[i]=(digits[i]+carry)%10;
            carry= (x+carry)/10;
           
                
            }
             // cout<<carry<<endl;
        }
        
        if(carry>0){
            digits.insert( digits.begin(),carry);
        }
        return digits;
    }
};
